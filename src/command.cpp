/*
 * command.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: soroush
 */
#include <memory>
#include <iostream>
#include <string>
#include <cstdio>
#include "command.hpp"

template<typename ... Args>
std::string string_format(const std::string& format, Args ... args) {
	size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
	std::unique_ptr<char[]> buf(new char[size]);
	snprintf(buf.get(), size, format.c_str(), args ...);
	return std::string(buf.get(), buf.get() + size); // We  want the '\0' inside
}

std::string u2d::command::init(const std::string& team_name, uint version,
		bool goalie) {
	std::string version_str = "";
	std::string goalie_str = "";
	if (version != 0) {
		version_str = string_format("(version %d)", version);
	}
	if (goalie) {
		goalie_str = "(goalie)";
	}
	return string_format("(init %s %s)", version_str, goalie_str);
}

std::string u2d::command::turn(float moment) {
	return string_format("(turn %f)", moment);
}

std::string u2d::command::dash(float power) {
	return string_format("(dash %f)", power);
}

std::string u2d::command::kick(float power, float direction) {
	return string_format("(kick %f %f)", power, direction);
}

std::string u2d::command::catch_(float direction) {
	return string_format("(catch %f)", direction);
}

std::string u2d::command::move(const u2d::point& target) {
	return string_format("(move %f %f)", target.x, target.y);
}

std::string u2d::command::turn_neck(float angle) {
	return string_format("(turn_neck %f)", angle);
}

std::string u2d::command::say(const std::string& message) {
	return string_format("(say %f)", message);
}

std::string u2d::command::sense_body() {
	return "(sense_body)";
}

std::string u2d::command::score() {
	return "(score)";
}

std::string u2d::command::change_view(u2d::body_t::view_mode_t type) {
	std::string width;
	std::string quality;
	switch (type.width) {
	case u2d::body_t::view_mode_t::width_t::narrow:
		width = "narrow";
		break;
	case u2d::body_t::view_mode_t::width_t::normal:
		width = "normal";
		break;
	case u2d::body_t::view_mode_t::width_t::wide:
		width = "wide";
		break;
	default:
		break;
	}
	switch (type.quality) {
	case u2d::body_t::view_mode_t::quality_t::high:
		quality = "high";
		break;
	case u2d::body_t::view_mode_t::quality_t::low:
		quality = "low";
		break;
	default:
		break;
	}
	return string_format("(change_view %s %s)", width, quality);
}
