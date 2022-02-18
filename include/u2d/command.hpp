/*
 libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.

 Copyright (c) 2011, 2012, 2013 Soroush Rabiei <soroush.rabiei@gmail.com>

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

#ifndef U2D_COMMAND_HPP
#define U2D_COMMAND_HPP

#include <string>
#include "geometry/geometry.hpp"
#include "perception/model.hpp"

namespace u2d {

class command {
public:
	command() = delete;
	~command() = delete;
	static std::string init(const std::string& team_name, uint version=0, bool goalie=false);
	static std::string turn(float moment);
	static std::string dash(float power);
	static std::string kick(float power, float direction);
	static std::string catch_(float direction);
	static std::string move(const u2d::point& target);
	static std::string turn_neck(float angle);
	static std::string say(const std::string& message);
	static std::string sense_body();
	static std::string score();
	static std::string change_view(u2d::body_t::view_mode_t type);
};

}

#endif // U2D_COMMAND_HPP
