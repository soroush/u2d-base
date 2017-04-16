/*
 libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.

 Copyright (c) 2016 Soroush Rabiei <rabiei@tidm.net>

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

#include "agent.hpp"
#include <cmath>
#include <cstddef>
#include <algorithm>
#include <mutex>

std::mutex mtx;

u2d::agent::agent(const std::string& team,
                  const std::string& host,
                  uint16_t port):
    _team(team),
    _connection(host,port),
    _parser(_istream,_ostream,_model),
    m_position_valid(false) {
}

void u2d::agent::set_team_name(const std::string& team) {
    this->_team = team;
}

void u2d::agent::run() {
    std::string init = "(init " + _team + " (version 15))";
    this->_connection.write(init);
    init = _connection.read();
    _istream.str(init);
    _parser.parse();
    while(_model.play_mode != model_t::play_mode_t::time_over) {
        std::string data = _connection.read();
        _istream.clear();
        _istream.str(data);
        _model.reset();
        _parser.parse();
        std::cout << _model;
    }
}

void u2d::agent::estimate_position() {
    std::vector<u2d::flag_t*> visuals;
    for(u2d::flag_t& f : _model.flags) {
        if(f.m_distance_valid and f.m_direction_valid) {
            visuals.push_back(&f);
        }
    }
    if(visuals.size() < 2) {
        m_position_valid=false;
        return;
    }
    // sort visual items by they distance (ascending)
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
    /*
    if(f1->m_distance + f2->m_distance > 30) {
        m_position_valid = false;
        return;
    }
    */
    bool found;
    auto intersections = intersect(
                             circle(f1->m_mark.position, f1->m_distance),
                             circle(f2->m_mark.position, f2->m_distance), found);
    if(!found) {
        m_position_valid = false;
        return;
    }
    m_position_valid = true;
    // Find out which intersection point is suitable to be assigned as current position
    // transmit axis system
    const u2d::vector v = u2d::point{0,0} - intersections[1];
    const u2d::point f1_p = f1->m_mark.position + v;
    const u2d::point f2_p = f2->m_mark.position + v;
    float alpha = std::atan2(f1_p.y, f1_p.x);
    float betha = std::atan2(f2_p.y, f2_p.x);
    if(alpha < 0) {
        alpha += M_2_PI;
    }
    if(betha < 0) {
        betha += M_2_PI;
    }
    if(alpha > betha) {
        m_position = intersections[0];
    } else {
         m_position = intersections[1];
    }
}

// void u2d::agent::print_player_param() {
//     std::cerr << "player.allow_mult_default_type: " << _model.player.allow_mult_default_type<< std::endl;
//     std::cerr << "player.catchable_area_l_stretch_max: " << _model.player.catchable_area_l_stretch_max<< std::endl;
//     std::cerr << "player.catchable_area_l_stretch_min: " << _model.player.catchable_area_l_stretch_min<< std::endl;
//     std::cerr << "player.dash_power_rate_delta_max: " << _model.player.dash_power_rate_delta_max<< std::endl;
//     std::cerr << "player.dash_power_rate_delta_min: " << _model.player.dash_power_rate_delta_min<< std::endl;
//     std::cerr << "player.effort_max_delta_factor: " << _model.player.effort_max_delta_factor<< std::endl;
//     std::cerr << "player.effort_min_delta_factor: " << _model.player.effort_min_delta_factor<< std::endl;
//     std::cerr << "player.extra_stamina_delta_max: " << _model.player.extra_stamina_delta_max<< std::endl;
//     std::cerr << "player.extra_stamina_delta_min: " << _model.player.extra_stamina_delta_min<< std::endl;
//     std::cerr << "player.foul_detect_probability_delta_factor: " << _model.player.foul_detect_probability_delta_factor<< std::endl;
//     std::cerr << "player.inertia_moment_delta_factor: " << _model.player.inertia_moment_delta_factor<< std::endl;
//     std::cerr << "player.kick_power_rate_delta_max: " << _model.player.kick_power_rate_delta_max<< std::endl;
//     std::cerr << "player.kick_power_rate_delta_min: " << _model.player.kick_power_rate_delta_min<< std::endl;
//     std::cerr << "player.kick_rand_delta_factor: " << _model.player.kick_rand_delta_factor<< std::endl;
//     std::cerr << "player.kickable_margin_delta_max: " << _model.player.kickable_margin_delta_max<< std::endl;
//     std::cerr << "player.kickable_margin_delta_min: " << _model.player.kickable_margin_delta_min<< std::endl;
//     std::cerr << "player.new_dash_power_rate_delta_max: " << _model.player.new_dash_power_rate_delta_max<< std::endl;
//     std::cerr << "player.new_dash_power_rate_delta_min: " << _model.player.new_dash_power_rate_delta_min<< std::endl;
//     std::cerr << "player.new_stamina_inc_max_delta_factor: " << _model.player.new_stamina_inc_max_delta_factor<< std::endl;
//     std::cerr << "player.player_decay_delta_max: " << _model.player.player_decay_delta_max<< std::endl;
//     std::cerr << "player.player_decay_delta_min: " << _model.player.player_decay_delta_min<< std::endl;
//     std::cerr << "player.player_size_delta_factor: " << _model.player.player_size_delta_factor<< std::endl;
//     std::cerr << "player.player_speed_max_delta_max: " << _model.player.player_speed_max_delta_max<< std::endl;
//     std::cerr << "player.player_speed_max_delta_min: " << _model.player.player_speed_max_delta_min<< std::endl;
//     std::cerr << "player.player_types: " << static_cast<int>(_model.player.player_types) << std::endl;
//     std::cerr << "player.pt_max: " << static_cast<int>(_model.player.pt_max) << std::endl;
//     std::cerr << "player.random_seed: " << _model.player.random_seed << std::endl;
//     std::cerr << "player.stamina_inc_max_delta_factor: " << _model.player.stamina_inc_max_delta_factor<< std::endl;
//     std::cerr << "player.subs_max: " << static_cast<int>(_model.player.subs_max)<< std::endl;
// }
