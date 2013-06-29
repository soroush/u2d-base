/*
 libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.

 Copyright (c) 2011, 2012, 2013 Soroush Rabiei <soroush-r@users.sf.net>

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

#include "player.h"
using namespace std;

// Player Type 1
PlayerT1::PlayerT1(const double &distance, const double &direction,
		const double &distanceChange, const double &directionChange) :
		objectT2(distance, direction, distanceChange, directionChange), m_distanceChange(
				distanceChange), m_directionChange(directionChange) {
}

// Player Type 2
PlayerT2::PlayerT2(const double &distance, const double &direction,
		const double &distanceChange, const double &directionChange,
		const double &_bodyDirection, const double &_headDirection,
		const string& _name, const unsigned int& uniform, const bool &_goalie) :
		//Object(distance, direction, distanceChange, directionChange),
		PlayerT1(distance, direction, distanceChange, directionChange), bodyDirection(
				_bodyDirection), headDirection(_headDirection), team(_name), number(
				uniform), goalie(_goalie) {
}
