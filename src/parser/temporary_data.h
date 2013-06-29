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

#ifndef TEMPORARY_DATA_H_
#define TEMPORARY_DATA_H_

#include <string>
#include "../geometry/types.h"
#include "../model/visual-objects/line.h"
using namespace std;

struct flag_data {
	flag_data(const string& stringVal, const double& _x, const double& _y);
	flag_data(const char* charVal, const double& _x, const double& _y);
	double x;
	double y;
	string s;
};

struct line_data {
	line_data(const double& parameter, const Line::Orientation& orientation);
	double p;
	Line::Orientation o;
};

#endif /* TEMPORARY_DATA_H_ */
