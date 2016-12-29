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

#include "visual_object.hpp"

u2d::visual_object::visual_object(float distance, float direction):
    m_distance (distance),
    m_direction (direction) {
}

float u2d::visual_object::distance() const {
    return this->m_distance;
}

float u2d::visual_object::direction() const {
    return this->m_direction;
}

void u2d::visual_object::set_distance(float distance) {
    this->m_distance = distance;
}

void u2d::visual_object::set_direction(float direction) {
    this->m_direction = direction;
}





