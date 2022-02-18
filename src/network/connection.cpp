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

#include <u2d/network/connection.hpp>
#include <ctime>
#include <iomanip>
#include <arpa/inet.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

u2d::connection::connection(const std::string& ip, const unsigned int& portNumber,
                            bool logging, const std::ostream& logger):
    m_logging_enabled(logging),
    m_logger(logger.rdbuf()) {
    m_init_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    m_init_address.sin_family = AF_INET;
    m_init_address.sin_addr.s_addr = inet_addr(ip.c_str());
    m_init_address.sin_port = htons(portNumber);
    m_data_address.sin_family = AF_INET;
    m_data_address.sin_addr.s_addr = inet_addr(ip.c_str());
}

std::string u2d::connection::read() {
    char* buffer = new char[8192];
    socklen_t from_len = sizeof(m_data_address);
    ssize_t data_size = recvfrom(m_init_sockfd, buffer, 8192, 0, (struct sockaddr*) &m_data_address, &from_len);
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    //buffer[data_size] = '\0';
    std::string data {buffer, static_cast<size_t>(data_size)};
    delete[] buffer;
    if(m_logging_enabled) {
        m_logger << std::put_time(&tm, "> [%F %T] [ INFO]: ") << data << std::endl;
    }
    return data;
}

void u2d::connection::write(const std::string& data, u2d::connection::message_type type) {
    ssize_t size = -1;
    switch(type) {
        case u2d::connection::message_type::initial:
            size = sendto(m_init_sockfd, data.c_str(), data.size()+1, 0, (struct sockaddr*) &m_init_address, sizeof(m_init_address));
            break;
        case u2d::connection::message_type::communication:
            size = sendto(m_init_sockfd, data.c_str(), data.size()+1, 0, (struct sockaddr*) &m_data_address, sizeof(m_data_address));
            break;
    }
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    if(size < 0) {
        m_logger << std::put_time(&tm, "< [%F %T] [ERROR]: Unable to write on socket...") << data << std::endl;
    } else {
        if(m_logging_enabled) {
            m_logger << std::put_time(&tm, "< [%F %T] [ INFO]: ") << data << std::endl;
        }
    }
}

void u2d::connection::set_logger(std::ostream& out, bool enable_logging) {
    m_logger.rdbuf(out.rdbuf());
    m_logging_enabled = enable_logging;
}

const std::ostream& u2d::connection::get_logger() const {
    return m_logger;
}

void u2d::connection::set_logging_enabled(bool enabled) {
    m_logging_enabled = enabled;
}

bool u2d::connection::is_logging_enabled() const {
    return m_logging_enabled;
}
