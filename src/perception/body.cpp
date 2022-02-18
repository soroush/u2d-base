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

#include <u2d/perception/body.hpp>

std::ostream& operator<<(std::ostream& os, const u2d::body_t& body) {
    os << "Body:\n";
    os << "    sequence: " << body.sequence  << "\n";
    std::string quality;
    std::string width;
    switch(body.view_mode.quality) {
        case u2d::body_t::view_mode_t::quality_t::high:
            quality = "high";
            break;
        case u2d::body_t::view_mode_t::quality_t::low:
            quality = "low";
            break;
    }
    switch(body.view_mode.width) {
        case u2d::body_t::view_mode_t::width_t::wide:
            width = "wide";
            break;
        case u2d::body_t::view_mode_t::width_t::narrow:
            width = "narrow";
            break;
        case u2d::body_t::view_mode_t::width_t::normal:
            width = "normal";
            break;
    }
    os << "    view mode:\n";
    os << "        quality: " << quality << '\n';
    os << "        width: " << width << '\n';
    os << "    stamina:\n";
    os << "        stamina: " << body.stamina.stamina << '\n';
    os << "        effort: "<< body.stamina.effort << '\n';
    os << "        capacity: "<< body.stamina.capacity << '\n';
    os << "    speed: "<< body.speed << '\n';
    os << std::endl;
    return os;
}
