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

#include "flag.h"

using namespace std;

Flag::Flag(const string &name, const Point &position, const double &_distance,
		const double &_direction) :
		objectT1(_distance, _direction), m_name(name), m_position(position) {
}

Flag::Flag(const string &_name, const double &x, const double &y,
		const double &_distance, const double &_direction) :
		objectT1(_distance, _direction), m_name(_name), m_position(Point(x, y)) {
}

string Flag::name() {
	return m_name;
}

void Flag::setName(const string &name) {
	this->m_name = name;
}

Point Flag::position() {
	return this->m_position;
}

void Flag::setPosition(const Point &position) {
	this->m_position = position;
}

void Flag::setPosition(const double& x, const double& y) {
	this->setPosition(Point(x, y));
}

Flag2::Flag2(const std::string& name, const Point& position,
		const double& distance, const double& direction,
		const double& distanceChange, const double& directionChange) :
		objectT2(distance, direction, distanceChange, directionChange), m_name(
				name), m_position(position) {
}

Flag2::Flag2(const std::string& name, const double& x, const double& y,
		const double& distance, const double& direction,
		const double& distanceChange, const double& directionChange) :
		objectT2(distance, direction, distanceChange, directionChange), m_name(
				name), m_position(x, y) {
}

string Flag2::name() {
	return this->m_name;
}

Point Flag2::position() {
	return this->m_position;
}

void Flag2::setPosition(const Point &position) {
	this->m_position = position;
}

void Flag2::setPosition(const double& x, const double& y) {
	this->setPosition(Point(x, y));
}
