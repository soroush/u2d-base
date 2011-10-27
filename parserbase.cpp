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
        std::cout << "seen init at "<< i << std::endl;
        i+=4;
        readTeamSide();
        break;
    case 's':
        std::cout << "seen s at "<< i << std::endl;
        i++;
        switch(input[i])
        {
        case 'e':
            i++;
            switch(input[i])
            {
            case 'e': // see
                std::cout << "seen see at "<< i << std::endl;
                break;
            case 'n':
                std::cout << "seen sense_body at "<< i << std::endl;
                break;
            case 'r':
                std::cout << "seen server_param at "<< i << std::endl;
                break;
            }

            break;
        }
        break;
    }
}
