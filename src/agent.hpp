/*
 libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.

 Copyright (c) 2011, 2012, 2013 Soroush Rabiei <rabiei@tidm.ir>

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

#ifndef U2D_AGENT_HPP
#define U2D_AGENT_HPP

#include <network/connection.hpp>
#include <perception/model.hpp>
#include <parser/Parser.h>
#include <sstream>

namespace u2d {

class agent {
public:
    agent(const std::string& team,
          const std::string& host,
          uint16_t port);
    void set_team_name(const std::string&);
    void connect(const std::string&, uint16_t);
    virtual void run();
    // inference engine
    void estimate_position();
protected:
    std::istringstream _istream;
    std::ostringstream _ostream;

    std::string _team;
    connection _connection;
    Parser _parser;
    model_t _model;

    // infered perception
    bool m_position_valid;
    u2d::point m_position;
};
}

#endif // U2D_AGENT_HPP
