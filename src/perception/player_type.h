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

#ifndef PLAYER_TYPE_H
#define PLAYER_TYPE_H

struct t_player_type {
	unsigned short int id;
	double player_speed_max;
	double stamina_inc_max;
	double player_decay;
	double inertia_moment;
	double dash_power_rate;
	double player_size;
	double kickable_margin;
	double kick_rand;
	double extra_stamina;
	double effort_max;
	double effort_min;
	double kick_power_rate;
	double foul_detect_probability;
	double catchable_area_l_stretch;
};

#endif // PLAYER_TYPE_H
