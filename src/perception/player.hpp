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

#ifndef U2D_PLAYER_HPP
#define U2D_PLAYER_HPP

#include <string>
#include <ostream>

namespace u2d {

struct player_t {
    player_t(float distance, float direction,
           float distance_change, float direction_change,
           float body_facing_dir, float head_facing_dir,
           bool goalie_seen, bool number_seen, bool team_seen,
           bool goalie = false, uint8_t number = 0, const std::string& team="");
    player_t(float distance, float direction,
           float distance_change, float direction_change,
           bool goalie_seen, bool number_seen, bool team_seen,
           bool goalie = false, uint8_t number = 0, const std::string& team="");
    player_t(float distance, float direction,
           bool goalie_seen, bool number_seen, bool team_seen,
           bool goalie = false, uint8_t number = 0, const std::string& team="");
    player_t(float distance,
           bool goalie_seen, bool number_seen, bool team_seen,
           bool goalie = false, uint8_t number = 0, const std::string& team="");
    std::string m_team;
    uint8_t m_number;
    bool m_is_goalie;
    float m_distance;
    float m_direction;
    float m_distance_change;
    float m_direction_change;
    float m_body_facing_dir;
    float m_head_facing_dir;
    // validity checks
    bool m_team_valid;
    bool m_number_valid;
    bool m_is_goalie_valid;
    bool m_distance_valid;
    bool m_direction_valid;
    bool m_distance_change_valid;
    bool m_direction_change_valid;
    bool m_body_facing_dir_valid;
    bool m_head_facing_dir_valid;
};
}

std::ostream& operator<<(std::ostream&, const u2d::player_t&);

#endif // U2D_PLAYER_HPP
