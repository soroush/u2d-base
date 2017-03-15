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

#include "connection.hpp"
#include <arpa/inet.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

u2d::connection::connection(const std::string& ip, const unsigned int& portNumber) {
    m_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = inet_addr(ip.c_str());
    m_address.sin_port = htons(portNumber);
}

std::string u2d::connection::read() {
    char* buffer = new char[8192];
    ssize_t data_size = recvfrom(m_sockfd, buffer, 8192, 0, NULL, NULL);
    buffer[data_size] = '\n';
    std::string data {buffer, static_cast<size_t>(data_size)};
    delete[] buffer;
    // std::cout << "read : " << data << std::endl;
    return data;
}

void u2d::connection::write(const std::string& data) {
    ssize_t size = sendto(this->m_sockfd, data.c_str(), data.length(), 0,(struct sockaddr*) &m_address, sizeof(m_address));
    if(size < 0) {
        // std::cerr << "write error." << std::endl;
        // std::cerr << strerror(errno) << std::endl;
        // do something
    } else {
        // std::cout << "write: " << data << std::endl;
    }
}

