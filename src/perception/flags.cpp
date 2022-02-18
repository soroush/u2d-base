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

#include <u2d/perception/flags.hpp>

u2d::flag_t::flag_t(const u2d::mark_t& mark, float distance, float direction,
                    float distance_change, float direction_change):
    m_mark(mark),
    m_distance(distance),
    m_direction(direction),
    m_distance_change(distance_change),
    m_direction_change(direction_change),
    m_distance_valid(true),
    m_direction_valid(true),
    m_distance_change_valid(true),
    m_direction_change_valid(true) {
}

u2d::flag_t::flag_t(const u2d::mark_t& mark, float distance, float direction):
    m_mark(mark),
    m_distance(distance),
    m_direction(direction),
    m_distance_valid(true),
    m_direction_valid(true),
    m_distance_change_valid(false),
    m_direction_change_valid(false) {
}

u2d::flag_t::flag_t(const u2d::mark_t& mark, float distance):
    m_mark(mark),
    m_distance(distance),
    m_distance_valid(true),
    m_direction_valid(false),
    m_distance_change_valid(false),
    m_direction_change_valid(false) {
}

u2d::flag_t::flag_t(const u2d::mark_t& mark):
    m_mark(mark),
    m_distance_valid(false),
    m_direction_valid(false) ,
    m_distance_change_valid(false),
    m_direction_change_valid(false) {
}

std::ostream& operator<<(std::ostream& os, const u2d::flag_t& p) {
    os << p.m_mark ;
    if(p.m_distance_valid) {
        os << ' ' <<  p.m_distance << "m" ;
    }
    if(p.m_direction_valid) {
        os << ' ' <<  p.m_direction <<  "\xC2\xB0" ;
    }
    return os;
}
