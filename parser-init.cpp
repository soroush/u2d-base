#include "parserbase.h"
#include <iostream>

void ParserBase::readTeamSide()
{
//    std::cout << "state: readTeamSide" << std::endl;
    i++;
    std::cout << "team-side: " << input[i] << std::endl;
    i++; // skipping the ' '
    readFormNumber();
}

void ParserBase::readFormNumber()
{
    i++; // fetch indexer to current meaningful area
//    std::cout << "state: readFormNumber" << std::endl;
    QString number = "";
    while(input[i]!=' ')
    {
        number += input[i];
        i++;

    }
    std::cout << "form-number: " << number.toInt() << std::endl;
//    i++; // set indexer to point to ' '
    readPlayMode();
}

void ParserBase::readPlayMode()
{
    i++;
    switch(input[i])
    {
    case 'b':
        i++;
        switch(input[i])
        {
        case 'e': // before_kick_off
            i+=13;
            std::cout << "PlayMode: before_kick_off" << std::endl;
            break;
        case 'a':
            break;
        }
    case 'c':
        i++;
        switch(input[i])
        {
        case 'a': // catch_fault_
            i+=11;
            switch(input[i])
            {
            case 'l':
                std::cout << "PlayMode: catch_fault_l" << std::endl;
                break;
            case 'r':
                std::cout << "PlayMode: catch_fault_r" << std::endl;
                break;
            }
            break;
        case 'o': // corner_kick_
            i+=11;
            switch(input[i])
            {
            case 'l':
                std::cout << "PlayMode: corner_kick_l" << std::endl;
                break;
            case 'r':
                std::cout << "PlayMode: corner_kick_r" << std::endl;
                break;
            }
            break;
        }
        break;
    case 'd': // drop_ball
        i += 8;
        std::cout << "PlayMode: drop_ball" << std::endl;
        break;
    }
//    std::cout << "Current: " << input[i] << std::endl;
    i++; // skip )
    start();
}
