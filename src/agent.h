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

#ifndef AGENT_H
#define AGENT_H

#include <string>
#include <sstream>

#include "model/model.h"
#include "parser/Parser.h"
#include "network/connection.h"

class Agent {
public:
	Agent();
	void setTeamName(const std::string& name);
	void setGoalie(const bool& goalie);
	void setVersion(const unsigned int& version);
	void setPort(const unsigned int& port);
	void setAddress(const std::string& address);
	void start();
	void parse(const char* input);
	Model model;
	// Testing proposed
	void test();
private:
	Parser parser;
	Connection connection;
	std::stringstream inputStream;
	std::string teamName;
	unsigned int rcssVersion;
	std::string address;
	unsigned int portNumber;
	bool goalie;
};

#endif // AGENT_H
