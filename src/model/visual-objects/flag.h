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

#ifndef FLAG_H
#define FLAG_H

#include <string>
#include "../../geometry/types.h"
#include "base-objects.h"

class Flag: public objectT1 {
public:
	Flag(const std::string& name, const Point& position, const double &distance,
			const double &direction);
	Flag(const std::string& name, const double& x, const double& y,
			const double &distance, const double &direction);
	std::string name();
	void setName(const std::string& name);
	Point position();
	void setPosition(const Point& position);
	void setPosition(const double& x, const double& y);
protected:
	std::string m_name;
	Point m_position;
};

class Flag2: public objectT2 {
public:
	Flag2(const std::string& name, const Point& position,
			const double &distance, const double &direction,
			const double &distanceChange, const double &directionChange);
	Flag2(const std::string& name, const double& x, const double& y,
			const double &distance, const double &direction,
			const double &distanceChange, const double &directionChange);
	std::string name();
	void setName(const std::string& name);
	Point position();
	void setPosition(const Point& position);
	void setPosition(const double& x, const double& y);
protected:
	std::string m_name;
	Point m_position;
};

#endif // FLAG_H
