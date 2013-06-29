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

#include "agent.h"
#include <sstream>
using namespace std;

Agent::Agent() {
	this->parser.setParent(this);
}

void Agent::setTeamName(const string &name) {
	this->teamName = name;
}

void Agent::setGoalie(const bool &_goalie) {
	this->goalie = _goalie;
}

void Agent::setVersion(const unsigned int &version) {
	this->rcssVersion = version;
}

void Agent::setPort(const unsigned int &port) {
	this->portNumber = port;
}

void Agent::setAddress(const string &_address) {
	this->address = _address;
}

void Agent::start() {
	this->parser.setIstream(this->inputStream);
	connection.initialize(this->address, this->portNumber, this);
	char buffer[50];
	sprintf(buffer, "(init %s (version %d) %s)", this->teamName.c_str(),
			this->rcssVersion, (this->goalie ? "(goalie)" : ""));
	connection.setInitializationCommand(buffer);
	connection.loop();
}

void Agent::parse(const char *input) {
	inputStream.str(std::string());
	inputStream << input;
//    cout << "parsing result: " << endl;
	this->parser.reset();
	int r = this->parser.parse();
//    cout << r << endl;
//    if(r)
//        exit(r);
}

// Testing proposed
void Agent::test() {
	parser.setIstream(std::cin);
	while (true)
		parser.parse();
//    string value;
//    this->parser.setIstream(inputStream);
//    while(true)
//    {
//        getline(cin,value);
//        inputStream.str("");
//        inputStream << value;
//        this->parser.reset();
//        this->parser.parse();
//    }
}
