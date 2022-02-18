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

#ifndef LINE_H_
#define LINE_H_

#include "base-objects.h"

class Line: public objectT1 {
public:
	enum Orientation {
		Horizontal, Vertical
	};
	Line(const double& parameter, Orientation& oriantation,
			const double& distance, const double& direction);
	virtual ~Line();
private:
	double parameter;
	Orientation orientation;

};

#endif /* LINE_H_ */
