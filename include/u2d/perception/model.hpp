/*
 libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.

 Copyright (c) 2016-2022 Soroush Rabiei <soroush.rabiei@gmail.com>

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

#ifndef U2D_MODEL_HPP
#define U2D_MODEL_HPP

#include "server_param.hpp"
#include "player_param.hpp"
#include "player.hpp"
#include "flags.hpp"
#include "body.hpp"
#include <ostream>
#include <vector>

namespace u2d {
struct model_t {
    enum class input_t : uint8_t {
        init,
        server_param,
        player_param,
        player_type,
        sense_body,
        see,
        hear,
        warning,
        error,
    };
    enum class play_mode_t : uint8_t {
        before_kick_off,
        play_on,
        time_over,
        kick_off_l,
        kick_off_r,
        kick_in_l,
        kick_in_r,
        free_kick_l,
        free_kick_r,
        corner_kick_l,
        corner_kick_r,
        goal_kick_l,
        goal_kick_r,
        goal_l,
        goal_r,
        drop_ball,
        offside_l,
        offside_r,
    };
    input_t last_input;
    server_param_t server;
    player_param_t player;
    play_mode_t play_mode;
    body_t body;
    std::vector<player_t> players;
    std::vector<flag_t> flags;
    // operations
    void reset();
    std::string play_mode_str();
};
}

std::ostream& operator<<(std::ostream&, const u2d::model_t&);

#endif // U2D_MODEL_HPP
