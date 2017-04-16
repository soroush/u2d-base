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

#include "model.hpp"

void u2d::model_t::reset() {
    players.clear();
    flags.clear();
}

std::string u2d::model_t::play_mode_str() {
    switch(this->play_mode) {
        case play_mode_t::before_kick_off:
            return "before_kick_off";
            break;
        case play_mode_t::play_on:
            return "play_on";
            break;
        case play_mode_t::time_over:
            return "time_over";
            break;
        case play_mode_t::kick_off_l:
            return "kick_off_l";
            break;
        case play_mode_t::kick_off_r:
            return "kick_off_r";
            break;
        case play_mode_t::kick_in_l:
            return " kick_in_l";
            break;
        case play_mode_t::kick_in_r:
            return "kick_in_r";
            break;
        case play_mode_t::free_kick_l:
            return "free_kick_l";
            break;
        case play_mode_t::free_kick_r:
            return "free_kick_r";
            break;
        case play_mode_t::corner_kick_l:
            return "corner_kick_l";
            break;
        case play_mode_t::corner_kick_r:
            return "corner_kick_r";
            break;
        case play_mode_t::goal_kick_l:
            return "goal_kick_l";
            break;
        case play_mode_t::goal_kick_r:
            return "goal_kick_r";
            break;
        case play_mode_t::goal_l:
            return "goal_l";
            break;
        case play_mode_t::goal_r:
            return "goal_r";
            break;
        case play_mode_t::drop_ball:
            return "drop_ball";
            break;
        case play_mode_t::offside_l:
            return "offside_l";
            break;
        case play_mode_t::offside_r:
            return "offside_r";
            break;
    }
    return "unknown_mode";
}

std::ostream& operator<<(std::ostream& os, const u2d::model_t& model) {
    switch(model.last_input) {
        case u2d::model_t::input_t::init:
            break;
        case u2d::model_t::input_t::server_param:
            os << model.server << std::endl;
            break;
        case u2d::model_t::input_t::player_param:
            os << model.player << std::endl;
            break;
        case u2d::model_t::input_t::player_type:
            break;
        case u2d::model_t::input_t::sense_body:
            os << model.body << std::endl;
            break;
        case u2d::model_t::input_t::see:
            for(const u2d::player_t& p : model.players) {
                os << p;
            }
            break;
        case u2d::model_t::input_t::hear:
            break;
        case u2d::model_t::input_t::error:
            break;
        case u2d::model_t::input_t::warning:
            break;
    }
    return os;
}
