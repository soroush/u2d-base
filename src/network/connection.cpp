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

#include "connection.h"
#include "../agent.h"
#include <iostream>
#include <arpa/inet.h>

using namespace std;

Connection::Connection() {
}

Connection::Connection(const char *ip, const unsigned int &portNumber,
		Agent* _parant) :
		parant(_parant) {
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr(ip);
	address.sin_port = htons(portNumber);
}

Connection::Connection(const std::string &ip, const unsigned int &portNumber,
		Agent *_parent) :
		parant(_parent) {
	Connection(ip.c_str(), portNumber);
}

void Connection::initialize(const string &ip, const unsigned int &portNumber,
		Agent *_parent) {
	this->parant = _parent;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr(ip.c_str());
	address.sin_port = htons(portNumber);
}

void Connection::loop() {
	//cout << "Initialization: " << initializeCommand << endl;
	char* buffer = new char[8192];
	sendto(sockfd, initializeCommand.c_str(), initializeCommand.length(), 0,
			(struct sockaddr *) &address, sizeof(address));
	int n;
	int i = 0;
	while (true) {
		n = recvfrom(sockfd, buffer, 8192, 0, NULL, NULL);
		buffer[n] = 0;
		parant->parse(buffer);
		i++;
	}
}

void Connection::setInitializationCommand(const string &command) {
	this->initializeCommand = command;
}
