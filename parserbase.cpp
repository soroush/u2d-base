#include "parserbase.h"
#include <iostream>


ParserBase::ParserBase(QObject *parent) :
    QObject(parent)
{
}

void ParserBase::start()
{
    switch(input[i])
    {
    case '(':
        //valid
        readSensorName();
        break;
    }
}

void ParserBase::readSensorName()
{
    i++;
    switch(input[i])
    {
    case 'i':
        // init
//        std::cout << "seen init at "<< i << std::endl;
        i+=4;
        readTeamSide();
        break;
    case 's':
//        std::cout << "seen s at "<< i << std::endl;
        i++;
        switch(input[i])
        {
        case 'e':
            i++;
            switch(input[i])
            {
            case 'e': // see
//                std::cout << "seen see at "<< i << std::endl;
                break;
            case 'n': // sense_body
                i+=9;
                sb_startRead();
                break;
            case 'r':
//                std::cout << "seen server_param at "<< i << std::endl;
                i+=10;
                sp_read();
                break;
            }
            break;
        case 'c': // score
            break;
        }
        break;
    case 'p': // player_type
//        std::cout << "seen player_type at "<< i << std::endl;
        break;
    case 'h': // hear
//        std::cout << "seen hear at "<< i << std::endl;
        break;
    case 'e': // error
//        std::cout << "seen error at "<< i << std::endl;
        break;
    case 'o': // ok_say
//        std::cout << "seen ok_say at "<< i << std::endl;
        break;
    }
}
