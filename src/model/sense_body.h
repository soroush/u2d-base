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

#ifndef SENSE_BODY_H
#define SENSE_BODY_H

#include "../geometry/types.h"

struct t_view_mode {
	enum view_mode_quality {
		high, low
	};
	enum view_mode_width {
		narrow, normal_w, wide
	};

	view_mode_quality quality;
	view_mode_width width;
};

struct t_stamina {
	double stamina;
	double effort;
	double capacity;
	t_stamina() :
			stamina(0), effort(0), capacity(0) {
	}
};

struct t_arm {
	int movable;
	Point target;
	int expires;
	int count;
	t_arm() :
			movable(0), target(Point(0.0, 0.0)), expires(0), count(0) {
	}
};

struct t_focus {
	enum focus_type {
		none = 0, l, r
	};
	focus_type type;
	int unum;
	int count;
	t_focus() :
			type(none), unum(0), count(0) {
	}
};

struct t_tackle {
	int expires;
	int count;
	t_tackle() :
			expires(0), count(0) {
	}
};

struct t_collition {
	enum collition_type {
		none = 0, ball = 1, player = 2, post = 4
	};
	collition_type type;
	t_collition() :
			type(none) {
	}
};

struct t_foul {
	enum card_type {
		none, yellow
	};
	int charged;
	card_type card;
	t_foul() :
			charged(0), card(none) {
	}
};

struct t_sense_body {
	int time;
	t_view_mode view_mode;
	t_stamina stamina;
	Point speed;
	int head_angle;
	int kick;
	int dash;
	int turn;
	int say;
	int turn_neck;
	int catch_;
	int move;
	int change_view;
	t_arm arm;
	t_focus focus;
	t_tackle tackle;
	t_collition collition;
	t_foul foul;
};

#endif // SENSE_BODY_H
