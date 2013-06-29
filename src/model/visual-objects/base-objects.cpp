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

#include "base-objects.h"

objectT1::objectT1(const double &distance, const double &direction) :
		m_distance(distance), m_direction(direction) {
}

double objectT1::distance() {
	return m_distance;
}

double objectT1::direction() {
	return m_direction;
}

void objectT1::setDistance(const double& distance) {
	m_distance = distance;
}

void objectT1::setDirection(const double& direction) {
	m_direction = direction;
}

objectT2::objectT2(const double &distance, const double &direction,
		const double &distanceChange, const double &directionChange) :
		objectT1(distance, direction), m_distanceChange(distanceChange), m_directionChange(
				directionChange) {
}

void objectT2::setDistanceChange(const double& distanceChange) {
	m_distanceChange = distanceChange;
}

void objectT2::setDirectionChange(const double& directionChange) {
	m_directionChange = directionChange;
}

