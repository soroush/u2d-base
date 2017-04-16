/*
  libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.

  Copyright (c) 2017 Soroush Rabiei <rabiei@tidm.net>

  U2D is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  See the file COPYING included with this distribution for more
  information.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <thread>
#include <mutex>
#include <ctime>
#include <iomanip>
#include <algorithm>

#include <src/agent.hpp>
#include <src/command.hpp>
#include <src/geometry/geometry.hpp>

std::mutex mtx;
std::once_flag call_flag;

class test_agent: public u2d::agent {
public:
    test_agent() :
        agent("", "127.0.0.1", 6000) {
    }

    void initialize() {
        file.open("positioning.dat", std::ofstream::out | std::ofstream::trunc);
    }

    static void finalize() {
        file.close();
    }

    void run(int form_number, const std::string& team) {
        std::call_once(call_flag, &test_agent::initialize, this);
        // std::stringstream stream;
        // auto t = std::time(nullptr);
        // auto tm = *std::localtime(&t);
        // stream << "log_" << team << form_number << "_" << std::put_time(&tm, "_%F_%T.txt");
        // std::ofstream logfile;
        // logfile.open(stream.str(), std::ofstream::out | std::ofstream::trunc);
        // if(logfile.is_open()) {
        //     _connection.set_logger(logfile, true);
        // }

        _connection.write(u2d::command::init(team, 15),
                          u2d::connection::message_type::initial);
        // Bypass initial information, until first sensor data arrives
        while(_model.last_input != u2d::model_t::input_t::see) {
            std::string info = _connection.read();
            _istream.str(info);
            if(_parser.parse() != 0) {
                std::cerr << "Unable to parse: " << info << std::endl;
            }
        }

        u2d::point position;
        u2d::point center(0, 0);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> xs(-52.5, +00.0);
        std::uniform_real_distribution<float> ys(-34.0, +34.0);
        std::uniform_real_distribution<float> angles(-180.0, +180.0);
        std::uniform_int_distribution<int> dice(0, 1);
        for(int i = 0;
                i < 3000 && _model.play_mode == u2d::model_t::play_mode_t::before_kick_off;
                ) {
            // move or turn
            if(dice(gen)) {
                position.x = xs(gen);
                position.y = ys(gen);
                _connection.write(u2d::command::move(position));
                ++i;
            } else {
                _connection.write(u2d::command::turn(angles(gen)));
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
            for(int j=0; j<10; ++j) {
                std::string data = _connection.read();
                _istream.clear();
                _istream.str();
                _istream.str(data);
                _model.reset();
                if(_parser.parse() != 0) {
                    std::lock_guard<std::mutex> lck{mtx};
                    std::cerr << "! " << data << std::endl;
                    break;
                }
                if(_model.last_input == u2d::model_t::input_t::see) {
                    estimate_position();
                    if(m_position_valid) {
                        /* ============ Redundant work  ============  */
                        std::vector<u2d::flag_t*> visuals;
                        for(u2d::flag_t& f : _model.flags) {
                            if(f.m_distance_valid and f.m_direction_valid) {
                                visuals.push_back(&f);
                            }
                        }
                        // sort visual items by they direction (ascending)
                        auto comparer = [](u2d::flag_t* a, u2d::flag_t* b) -> bool {
                            return a->m_distance < b->m_distance;
                        };
                        std::sort(visuals.begin(), visuals.end(), comparer);
                        // pick up two flags
                        const u2d::flag_t* f1 = visuals.at(0);
                        const u2d::flag_t* f2 = visuals.at(1);
                        if(f1->m_direction > f2->m_direction) {
                            std::swap(f1, f2);
                        }
                        /* =========End of Redundant work  =========  */
                        {
                            std::lock_guard<std::mutex> lck{mtx};
                            file << std::showpos << std::scientific <<
                                 f1->m_mark.position.x << ' ' << f1->m_mark.position.y << ' ' << f1->m_distance << ' ' <<
                                 f2->m_mark.position.x << ' ' << f2->m_mark.position.y << ' ' << f2->m_distance << ' ' <<
                                position.x << ' ' << position.y << ' ' << m_position.x << ' ' << m_position.y <<  std::endl;
                        }
                    }
                    break;
                }
            }
        }
    }
    static std::ofstream file;
};

std::ofstream test_agent::file;

int main() {
    test_agent l[22];
    std::vector<std::thread> t;
    for(int i=0; i<11; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        t.emplace_back(&test_agent::run, &l[i], i+1, "teamA");
    }
    for(int i=0; i<11; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        t.emplace_back(&test_agent::run, &l[11+i], i+1, "teamB");
    }
    for(auto& tt : t) {
        tt.join();
    }
    test_agent::finalize();
    return 1;
}

