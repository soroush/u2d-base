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

#include <u2d/perception/detailed_visual_object.hpp>

u2d::detailed_visual_object::detailed_visual_object(float distance, float direction,
                                                    float distance_change, float direction_change):
    u2d::visual_object (distance,direction),
    m_distance_change (distance_change),
    m_direction_change (direction_change) {
}

float u2d::detailed_visual_object::distance_change() const {
    return this->m_distance_change;
}

float u2d::detailed_visual_object::direction_change() const {
    return this->m_direction_change;
}

void u2d::detailed_visual_object::set_distance_change(float distance_change) {
    this->m_distance_change = distance_change;
}

void u2d::detailed_visual_object::set_direction_change(float direction_change) {
    this->m_direction_change = direction_change;
}
