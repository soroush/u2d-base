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

#include <u2d/geometry/geometry.hpp>
#include <cmath>
#include <ostream>
#include <iostream>

u2d::point::point() :
		x { float() }, y { float() } {
}

u2d::point::point(float _x, float _y) :
		x { _x }, y { _y } {
}

u2d::vector::vector() :
		u2d::point() {
}

u2d::vector::vector(float _x, float _y) :
		u2d::point(_x, _y) {
}

float u2d::vector::length() const {
	return std::sqrt(x * x + y * y);
}

u2d::circle::circle(const u2d::point& center_, float radius_) :
		center(center_), radius(radius_) {
}

u2d::circle::circle(float x, float y, float radius_) :
		center(x, y), radius(radius_) {
}

const u2d::point u2d::midpoint(const u2d::point& a, const u2d::point& b) {
	return u2d::point((a.x + b.x) / 2, (a.y + b.y) / 2);
}

const float u2d::distance(const u2d::point& a, const u2d::point& b) {
	return std::sqrt(squared_distance(a, b));
}

const float u2d::squared_distance(const u2d::point& a, const u2d::point& b) {
	return std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2);
}

std::array<u2d::point, 2> u2d::intersect(const u2d::circle& c0,
        const u2d::circle& c1, bool& found) {
	std::array<u2d::point, 2> intersect_points;
	const float d = u2d::distance(c0.center, c1.center);
	const float& r0 = c0.radius;
	const float& r1 = c1.radius;
	if (d >= abs(r0 - r1) && d <= r0 + r1 && d != 0) {
	        found = true;
		const float a = (r0 * r0 - r1 * r1 + d * d) / (2 * d);
		const float h = std::sqrt(r0 * r0 - a * a);
		const u2d::point p2 = c0.center + (a / d) * (c1.center - c0.center);
		const float c = h / d;
		intersect_points[0].x = p2.x + c * (c1.center.y - c0.center.y);
		intersect_points[0].y = p2.y - c * (c1.center.x - c0.center.x);
		intersect_points[1].x = p2.x - c * (c1.center.y - c0.center.y);
		intersect_points[1].y = p2.y + c * (c1.center.x - c0.center.x);
	} else {
                found = false;
	}
	return intersect_points;
}

std::ostream& operator<<(std::ostream& os, const u2d::vector& v) {
	os << '(' << v.x << ',' << v.y << ')';
	return os;
}

std::ostream& operator<<(std::ostream& os, const u2d::point& p) {
	os << '(' << p.x << ',' << p.y << ')';
	return os;
}

u2d::vector operator-(const u2d::point &a, const u2d::point &b) {
	return u2d::vector { a.x - b.x, a.y - b.y };
}

u2d::vector operator+(const u2d::vector &a, const u2d::vector &b) {
	return u2d::vector { a.x + b.x, a.y + b.y };
}

u2d::vector operator-(const u2d::vector &a, const u2d::vector &b) {
	return u2d::vector { a.x - b.x, a.y - b.y };
}

u2d::vector operator*(const u2d::vector &v, float s) {
	return u2d::vector { v.x * s, v.y * s };
}

u2d::vector operator*(float s, const u2d::vector &v) {
	return v * s;
}

u2d::vector operator/(const u2d::vector &v, float s) {
	return u2d::vector { v.x / s, v.y / s };
}

u2d::point operator+(const u2d::point &a, const u2d::vector &b) {
	return u2d::point { a.x + b.x, a.y + b.y };
}

u2d::point operator-(const u2d::point &a, const u2d::vector &b) {
	return u2d::point { a.x - b.x, a.y - b.y };
}
