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

#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "server_param.h"
#include "player_param.h"
#include "player_type.h"
#include "sense_body.h"
#include "see.h"

class Model {
public:
	Model();
	enum play_mode_type {
		before_kick_off,
		play_on,
		time_over,
		kick_off_l,
		kick_off_r,
		kick_in_l,
		kick_in_r,
		free_kick_l,
		free_kick_r,
		corner_kick_l,
		corner_kick_r,
		goal_kick_l,
		goal_kick_r,
		goal_l,
		goal_r,
		drop_ball,
		offside_l,
		offside_r
	};

	void initializeFiled();
	t_server_param server;
	t_player_param player;
	play_mode_type play_mode;
	std::vector<t_player_type> player_types;
	t_sense_body body;
	See visual;

	void testServer();
};

#endif // MODEL_H
