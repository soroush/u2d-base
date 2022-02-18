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

#include <u2d/perception/player.hpp>

u2d::player_t::player_t(float distance, float direction,
                        float distance_change, float direction_change,
                        float body_facing_dir, float head_facing_dir,
                        bool goalie_seen, bool number_seen, bool team_seen,
                        bool goalie, uint8_t number, const std::string& team):
    m_team(team),
    m_number(number),
    m_is_goalie(goalie),
    m_distance(distance),
    m_direction(direction),
    m_distance_change(distance_change),
    m_direction_change(direction_change),
    m_body_facing_dir(body_facing_dir),
    m_head_facing_dir(head_facing_dir),
    m_team_valid(team_seen),
    m_number_valid(number_seen),
    m_is_goalie_valid(goalie_seen),
    m_distance_valid(true),
    m_direction_valid(true),
    m_distance_change_valid(true),
    m_direction_change_valid(true),
    m_body_facing_dir_valid(true),
    m_head_facing_dir_valid(true) {
}

u2d::player_t::player_t(float distance, float direction,
                        float distance_change, float direction_change,
                        bool goalie_seen, bool number_seen, bool team_seen,
                        bool goalie, uint8_t number, const std::string& team):
    m_team(team),
    m_number(number),
    m_is_goalie(goalie),
    m_distance(distance),
    m_direction(direction),
    m_distance_change(distance_change),
    m_direction_change(direction_change),
    m_team_valid(team_seen),
    m_number_valid(number_seen),
    m_is_goalie_valid(goalie_seen),
    m_distance_valid(true),
    m_direction_valid(true),
    m_distance_change_valid(true),
    m_direction_change_valid(true),
    m_body_facing_dir_valid(false),
    m_head_facing_dir_valid(false) {
}

u2d::player_t::player_t(float distance, float direction,
                        bool goalie_seen, bool number_seen, bool team_seen,
                        bool goalie, uint8_t number, const std::string& team):
    m_team(team),
    m_number(number),
    m_is_goalie(goalie),
    m_distance(distance),
    m_direction(direction),
    m_team_valid(team_seen),
    m_number_valid(number_seen),
    m_is_goalie_valid(goalie_seen),
    m_distance_valid(true),
    m_direction_valid(true),
    m_distance_change_valid(false),
    m_direction_change_valid(false),
    m_body_facing_dir_valid(false),
    m_head_facing_dir_valid(false) {
}

u2d::player_t::player_t(float distance,
                        bool goalie_seen, bool number_seen, bool team_seen,
                        bool goalie, uint8_t number, const std::string& team):
    m_team(team),
    m_number(number),
    m_is_goalie(goalie),
    m_distance(distance),
    m_team_valid(team_seen),
    m_number_valid(number_seen),
    m_is_goalie_valid(goalie_seen),
    m_distance_valid(true),
    m_direction_valid(false),
    m_distance_change_valid(false),
    m_direction_change_valid(false),
    m_body_facing_dir_valid(false),
    m_head_facing_dir_valid(false) {
}

std::ostream& operator<<(std::ostream& os, const u2d::player_t& p) {
    os << "Player:\n";
    if(p.m_team_valid) {
        os << "    team: " << p.m_team << '\n';
    }
    if(p.m_number_valid) {
        os << "    number: " << static_cast<int>(p.m_number) << '\n';
    }
    if(p.m_is_goalie_valid) {
        os << "    type: " << (p.m_is_goalie ? "goalie" : "player") << '\n' ;
    }
    if(p.m_distance_valid) {
        os << "    distance: " <<  p.m_distance << "m\n" ;
    }
    if(p.m_direction_valid) {
        os << "    direction: " <<  p.m_direction <<  "\xC2\xB0\n" ;
    }
    if(p.m_distance_change_valid) {
        os << "    distance change: " <<  p.m_distance_change << "m\n" ;
    }
    if(p.m_direction_change_valid) {
        os << "    direction change: " <<  p.m_direction_change << "\xC2\xB0\n" ;
    }
    if(p.m_body_facing_dir_valid) {
        os << "    body facing dir: " <<  p.m_body_facing_dir << "\xC2\xB0\n" ;
    }
    if(p.m_head_facing_dir_valid) {
        os << "    head facing dir: " <<  p.m_head_facing_dir << "\xC2\xB0\n" ;
    }
    os << std::endl;
    return os;
}
