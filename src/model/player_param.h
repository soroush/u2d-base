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

#ifndef PLAYER_PARAM_H
#define PLAYER_PARAM_H

struct t_player_param {
	bool allow_mult_default_type;
	double catchable_area_l_stretch_max;
	double catchable_area_l_stretch_min;
	double dash_power_rate_delta_max;
	double dash_power_rate_delta_min;
	double effort_max_delta_factor;
	double effort_min_delta_factor;
	double extra_stamina_delta_max;
	double extra_stamina_delta_min;
	double foul_detect_probability_delta_factor;
	double inertia_moment_delta_factor;
	double kick_power_rate_delta_max;
	double kick_power_rate_delta_min;
	double kick_rand_delta_factor;
	double kickable_margin_delta_max;
	double kickable_margin_delta_min;
	double new_dash_power_rate_delta_max;
	double new_dash_power_rate_delta_min;
	double new_stamina_inc_max_delta_factor;
	double player_decay_delta_max;
	double player_decay_delta_min;
	double player_size_delta_factor;
	double player_speed_max_delta_max;
	double player_speed_max_delta_min;
	int player_types;
	int pt_max;
	double random_seed;
	double stamina_inc_max_delta_factor;
	int subs_max;
};

#endif // PLAYER_PARAM_H
