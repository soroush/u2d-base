/*
 libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.

 Copyright (c) 2011, 2012, 2013 Soroush Rabiei <soroush.rabiei@gmail.com>

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

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "base-objects.h"

class PlayerT1: public objectT2 {
    public:
        PlayerT1(const double& distance, const double& direction,
                 const double& distanceChange, const double& directionChange);
    protected:
        double m_distanceChange;
        double m_directionChange;
};

class PlayerT2: public PlayerT1 {
    public:
        PlayerT2(const double& distance, const double& direction,
                 const double& distanceChange, const double& directionChange,
                 const double& bodyDirection, const double& headDirection,
                 const std::string& name = "", const unsigned int& uniform = 0,
                 const bool& goalie = false);
    private:
        std::string team;
        unsigned int number;
        bool goalie;
        double bodyDirection;
        double headDirection;
};
#endif // PLAYER_H

