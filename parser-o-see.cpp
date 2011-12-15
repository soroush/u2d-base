#include <iostream>
#include <QString>
#include "parserbase.h"
#include "agent.h"
#include "see.h"

void ParserBase::ss_startRead()
{
    i+=2;
    int j=0;
    char value[10];
    while(input[i]!=' ')
    {
        value[j] = input[i];
        ++i;
        ++j;
    }
    value[j]='\0';
    see::time = atoi(value);
    std::cout << "time: " << see::time << std::endl;
    while(input[i]!=')')
        ss_readParameter();
}

void ParserBase::ss_readParameter()
{
    ++i; // pass the ' '
    int j=0;
    double distance=0, direction=0, distanceChange=0, directionChange=0, bodyFacingDir=0, headFacingDir=0;
    bool goalie = false;
    char value[5];
    char teamName[50];
    object *seeingObject;
    objectData* data;
    // TEST
    playerData* test;
    // END OF TEST
    switch(input[i])
    {
    case '(':
        ++i;
        switch(input[i])
        {
        case '(':
            ++i; // pass the opening parenthes of parameter
            switch(input[i])
            {
            case 'f':
                i+=2;
                switch(input[i])
                {
                case 'c': // (f c
                    ++i;
                    switch(input[i])
                    {
                    case ')': // (f c)
                        i+=2;
                        j=0;
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        distance = atof(value);
                        ++i; // skip the ' ' between numbers
                        j=0;
                        while(input[i]!=')' && input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        direction = atof(value);
                        // if we are close enough to see the distChange and dirChange parameters of seeing target,
                        // then we can should read remaining two parameters
                        if(input[i]==')')
                        {
                            data = new objectData(distance,direction);
                            seeingObject = new object(&objectType::fc, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fc:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << std::endl;
                            break;
                        }
                        j=0;
                        ++i;
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        distanceChange = atof(value);
                        j=0;
                        ++i;
                        while(input[i]!=')')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        directionChange = atof(value);
                        data = new objectData(distance,direction,distanceChange,directionChange);
                        seeingObject = new object(&objectType::fc, data);
                        see::seeingObjects.append(seeingObject);
                        std::cout << "fc:"
                                  << see::seeingObjects.last()->data->distance << " "
                                  << see::seeingObjects.last()->data->direction << " "
                                  << see::seeingObjects.last()->data->distChange << " "
                                  << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                        break;
                    case ' ': // '(f c '
                        ++i;
                        j=0;
                        switch(input[i])
                        {
                        case 't': // (f c t)
                            i+=3;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fct, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fct: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fct, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fct:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case 'b': // (f c b)
                            i+=3;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fcb, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fcb: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                //std::cout << "seen flag (f c b) "<< distance << "   " << direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fct, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fcb:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        }
                        break;
                    }
                    break;
                case 'r':
                    i+=2;
                    j=0;
                    switch(input[i])
                    {
                    case 't': // (f r t
                        ++i;
                        switch(input[i])
                        {
                        case ')':
                            i+=2;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            double distance;
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            double direction;
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::frt, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "frt: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::frt, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "frt:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case ' ':
                            ++i;
                            switch(input[i])
                            {
                            case '1': // (f r t 10)
                                i+=4;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                double distance;
                                distance = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=' ' && input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                double direction;
                                direction = atof(value);
                                if(input[i]==')')
                                {
                                    data = new objectData(distance,direction);
                                    seeingObject = new object(&objectType::frt10, data);
                                    see::seeingObjects.append(seeingObject);
                                    std::cout << "frt10: "
                                              << see::seeingObjects.last()->data->distance << " "
                                              << see::seeingObjects.last()->data->direction << std::endl;
                                    break;
                                }
                                ++i;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distanceChange = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                directionChange = atof(value);
                                data = new objectData(distance,direction,distanceChange,directionChange);
                                seeingObject = new object(&objectType::frt10, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "frt10:"
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << " "
                                          << see::seeingObjects.last()->data->distChange << " "
                                          << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                                break;
                            case '2':
                                i+=4;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distance = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=' ' && input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                direction = atof(value);
                                if(input[i]==')')
                                {
                                    data = new objectData(distance,direction);
                                    seeingObject = new object(&objectType::frt20, data);
                                    see::seeingObjects.append(seeingObject);
                                    std::cout << "frt20: "
                                              << see::seeingObjects.last()->data->distance << " "
                                              << see::seeingObjects.last()->data->direction << std::endl;
                                    break;
                                }
                                ++i;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distanceChange = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                directionChange = atof(value);
                                data = new objectData(distance,direction,distanceChange,directionChange);
                                seeingObject = new object(&objectType::frt20, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "frt20:"
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << " "
                                          << see::seeingObjects.last()->data->distChange << " "
                                          << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                                //std::cout << "seen flag (f r t 20) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
                                break;
                                //
                            case '3':
                                i+=4;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distance = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=' ' && input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                direction = atof(value);
                                if(input[i]==')')
                                {
                                    data = new objectData(distance,direction);
                                    seeingObject = new object(&objectType::frt, data);
                                    see::seeingObjects.append(seeingObject);
                                    std::cout << "frt: "
                                              << see::seeingObjects.last()->data->distance << " "
                                              << see::seeingObjects.last()->data->direction << std::endl;
                                    break;
                                }
                                ++i;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distanceChange = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                directionChange = atof(value);
                                data = new objectData(distance,direction,distanceChange,directionChange);
                                seeingObject = new object(&objectType::frt, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "frt:"
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << " "
                                          << see::seeingObjects.last()->data->distChange << " "
                                          << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                                break;
                            }
                            break;
                        }
                        break;
                    case 'b': // (f r b
                        ++i;
                        switch(input[i])
                        {
                        case ')':
                            i+=2;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::frb, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "frb: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::frb, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "frb:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case ' ':
                            ++i;
                            switch(input[i])
                            {
                            case '1': // (f r b 10)
                                i+=4;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                double distance;
                                distance = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=' ' && input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                double direction;
                                direction = atof(value);
                                if(input[i]==')')
                                {
                                    data = new objectData(distance,direction);
                                    seeingObject = new object(&objectType::frb10, data);
                                    see::seeingObjects.append(seeingObject);
                                    std::cout << "frb10: "
                                              << see::seeingObjects.last()->data->distance << " "
                                              << see::seeingObjects.last()->data->direction << std::endl;
                                    break;
                                }
                                ++i;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distanceChange = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                directionChange = atof(value);
                                data = new objectData(distance,direction,distanceChange,directionChange);
                                seeingObject = new object(&objectType::frb10, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "frb10:"
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << " "
                                          << see::seeingObjects.last()->data->distChange << " "
                                          << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                                break;
                            case '2':
                                i+=4;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distance = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=' ' && input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                direction = atof(value);
                                if(input[i]==')')
                                {
                                    data = new objectData(distance,direction);
                                    seeingObject = new object(&objectType::frb20, data);
                                    see::seeingObjects.append(seeingObject);
                                    std::cout << "frb20: "
                                              << see::seeingObjects.last()->data->distance << " "
                                              << see::seeingObjects.last()->data->direction << std::endl;
                                    break;
                                }
                                ++i;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distanceChange = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                directionChange = atof(value);
                                data = new objectData(distance,direction,distanceChange,directionChange);
                                seeingObject = new object(&objectType::frb20, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "frb20:"
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << " "
                                          << see::seeingObjects.last()->data->distChange << " "
                                          << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                                //std::cout << "seen flag (f r b 20) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
                                break;
                                //
                            case '3':
                                i+=4;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distance = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=' ' && input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                direction = atof(value);
                                if(input[i]==')')
                                {
                                    data = new objectData(distance,direction);
                                    seeingObject = new object(&objectType::frb30, data);
                                    see::seeingObjects.append(seeingObject);
                                    std::cout << "frb30: "
                                              << see::seeingObjects.last()->data->distance << " "
                                              << see::seeingObjects.last()->data->direction << std::endl;
                                    break;
                                }
                                ++i;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distanceChange = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                directionChange = atof(value);
                                data = new objectData(distance,direction,distanceChange,directionChange);
                                seeingObject = new object(&objectType::frb30, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "frb30:"
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << " "
                                          << see::seeingObjects.last()->data->distChange << " "
                                          << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                                break;
                            }
                            break;
                        }
                        break;
                    case '0': // (f r 0)
                        i+=3;
                        j=0;
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        distance = atof(value);
                        ++i;
                        j=0;
                        while(input[i]!=' ' && input[i]!=')')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        direction = atof(value);
                        if(input[i]==')')
                        {
                            data = new objectData(distance,direction);
                            seeingObject = new object(&objectType::fr0, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fr0: "
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << std::endl;
                            break;
                        }
                        ++i;
                        j=0;
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        distanceChange = atof(value);
                        ++i;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        directionChange = atof(value);
                        data = new objectData(distance,direction,distanceChange,directionChange);
                        seeingObject = new object(&objectType::fr0, data);
                        see::seeingObjects.append(seeingObject);
                        std::cout << "fr0:"
                                  << see::seeingObjects.last()->data->distance << " "
                                  << see::seeingObjects.last()->data->direction << " "
                                  << see::seeingObjects.last()->data->distChange << " "
                                  << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                        break;
                    }
                    break;
                case 'l':
                    i+=2;
                    j=0;
                    switch(input[i])
                    {
                    case 't': // (f l t
                        ++i;
                        switch(input[i])
                        {
                        case ')':
                            i+=2;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            double distance;
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            double direction;
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::flt, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "flt: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::flt, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "flt:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case ' ':
                            ++i;
                            switch(input[i])
                            {
                            case '1': // (f l t 10)
                                i+=4;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                double distance;
                                distance = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=' ' && input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                double direction;
                                direction = atof(value);
                                if(input[i]==')')
                                {
                                    data = new objectData(distance,direction);
                                    seeingObject = new object(&objectType::flt10, data);
                                    see::seeingObjects.append(seeingObject);
                                    std::cout << "flt10: "
                                              << see::seeingObjects.last()->data->distance << " "
                                              << see::seeingObjects.last()->data->direction << std::endl;
                                    break;
                                }
                                ++i;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distanceChange = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                directionChange = atof(value);
                                data = new objectData(distance,direction,distanceChange,directionChange);
                                seeingObject = new object(&objectType::flt10, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "flt10:"
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << " "
                                          << see::seeingObjects.last()->data->distChange << " "
                                          << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                                break;
                            case '2':
                                i+=4;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distance = atof(value);
                                ++i;
                                j=0;
                                j=0;
                                while(input[i]!=' ' && input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                direction = atof(value);
                                if(input[i]==')')
                                {
                                    data = new objectData(distance,direction);
                                    seeingObject = new object(&objectType::flt20, data);
                                    see::seeingObjects.append(seeingObject);
                                    std::cout << "flt20: "
                                              << see::seeingObjects.last()->data->distance << " "
                                              << see::seeingObjects.last()->data->direction << std::endl;
                                    break;
                                }
                                ++i;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distanceChange = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                directionChange = atof(value);
                                data = new objectData(distance,direction,distanceChange,directionChange);
                                seeingObject = new object(&objectType::flt20, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "flt20:"
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << " "
                                          << see::seeingObjects.last()->data->distChange << " "
                                          << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                                break;
                                //
                            case '3':
                                i+=4;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distance = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=' ' && input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                direction = atof(value);
                                if(input[i]==')')
                                {
                                    data = new objectData(distance,direction);
                                    seeingObject = new object(&objectType::flt30, data);
                                    see::seeingObjects.append(seeingObject);
                                    std::cout << "flt30: "
                                              << see::seeingObjects.last()->data->distance << " "
                                              << see::seeingObjects.last()->data->direction << std::endl;
                                    break;
                                }
                                ++i;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distanceChange = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                directionChange = atof(value);
                                data = new objectData(distance,direction,distanceChange,directionChange);
                                seeingObject = new object(&objectType::flt30, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "flt30:"
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << " "
                                          << see::seeingObjects.last()->data->distChange << " "
                                          << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                                break;
                            }
                            break;
                        }
                        break;
                    case 'b': // (f l b
                        ++i;
                        switch(input[i])
                        {
                        case ')':
                            i+=2;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::flb, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "flb: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::flb, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "flb:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case ' ':
                            ++i;
                            switch(input[i])
                            {
                            case '1': // (f l b 10)
                                i+=4;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                double distance;
                                distance = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=' ' && input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                double direction;
                                direction = atof(value);
                                if(input[i]==')')
                                {
                                    data = new objectData(distance,direction);
                                    seeingObject = new object(&objectType::flb10, data);
                                    see::seeingObjects.append(seeingObject);
                                    std::cout << "flb10: "
                                              << see::seeingObjects.last()->data->distance << " "
                                              << see::seeingObjects.last()->data->direction << std::endl;
                                    break;
                                }
                                ++i;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distanceChange = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                directionChange = atof(value);
                                data = new objectData(distance,direction,distanceChange,directionChange);
                                seeingObject = new object(&objectType::flb10, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "flb10:"
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << " "
                                          << see::seeingObjects.last()->data->distChange << " "
                                          << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                                break;
                            case '2':
                                i+=4;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distance = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=' ' && input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                direction = atof(value);
                                if(input[i]==')')
                                {
                                    data = new objectData(distance,direction);
                                    seeingObject = new object(&objectType::flb20, data);
                                    see::seeingObjects.append(seeingObject);
                                    std::cout << "flb20: "
                                              << see::seeingObjects.last()->data->distance << " "
                                              << see::seeingObjects.last()->data->direction << std::endl;
                                    break;
                                }
                                ++i;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distanceChange = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                directionChange = atof(value);
                                data = new objectData(distance,direction,distanceChange,directionChange);
                                seeingObject = new object(&objectType::flb20, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "flb20:"
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << " "
                                          << see::seeingObjects.last()->data->distChange << " "
                                          << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                                break;
                                //
                            case '3':
                                i+=4;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distance = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=' ' && input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                direction = atof(value);
                                if(input[i]==')')
                                {
                                    data = new objectData(distance,direction);
                                    seeingObject = new object(&objectType::flb30, data);
                                    see::seeingObjects.append(seeingObject);
                                    std::cout << "flb30: "
                                              << see::seeingObjects.last()->data->distance << " "
                                              << see::seeingObjects.last()->data->direction << std::endl;
                                    break;
                                }
                                ++i;
                                j=0;
                                while(input[i]!=' ')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                distanceChange = atof(value);
                                ++i;
                                j=0;
                                while(input[i]!=')')
                                {
                                    value[j] = input[i];
                                    ++i;
                                    ++j;
                                }
                                value[j]='\0';
                                directionChange = atof(value);
                                data = new objectData(distance,direction,distanceChange,directionChange);
                                seeingObject = new object(&objectType::flb30, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "flb30:"
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << " "
                                          << see::seeingObjects.last()->data->distChange << " "
                                          << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                                break;
                            }
                            break;
                        }
                        break;
                    case '0': // (f l 0)
                        i+=3;
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        distance = atof(value);
                        ++i;
                        j=0;
                        while(input[i]!=' ' && input[i]!=')')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        direction = atof(value);
                        if(input[i]==')')
                        {
                            data = new objectData(distance,direction);
                            seeingObject = new object(&objectType::fl0, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fl0: "
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << std::endl;
                            break;
                        }
                        ++i;
                        j=0;
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        distanceChange = atof(value);
                        ++i;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        directionChange = atof(value);
                        data = new objectData(distance,direction,distanceChange,directionChange);
                        seeingObject = new object(&objectType::fl0, data);
                        see::seeingObjects.append(seeingObject);
                        std::cout << "fl0:"
                                  << see::seeingObjects.last()->data->distance << " "
                                  << see::seeingObjects.last()->data->direction << " "
                                  << see::seeingObjects.last()->data->distChange << " "
                                  << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                        break;
                    }
                    break;
                case 'p': //(f p
                    i+=2;
                    switch(input[i])
                    {
                    case 'l': // (f p l
                        i+=2;
                        switch(input[i])
                        {
                        case 't': // ( f p l t
                            i+=3;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fplt, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fplt: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fplt, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fplt:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case 'c':
                            i+=3;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fplc, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fplc: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fplc, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fplc:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case 'b':
                            i+=3;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fplb, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fplb: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fplb, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fplb:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        }
                        break;
                    case 'r': // (f p r
                        i+=2;
                        switch(input[i])
                        {
                        case 't': // ( f p r t
                            i+=3;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fprt, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fprt: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fprt, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fprt:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case 'c':
                            i+=3;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fprc, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fprc: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fprc, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fprc:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case 'b':
                            i+=3;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fprb, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fprb: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fprb, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fprb:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        }
                        break;
                    }
                    break;
                case 'g':
                    i+=2;
                    switch(input[i])
                    {
                    case 'l': // (f g l
                        i+=2;
                        switch(input[i])
                        {
                        case 't': // ( f g l t
                            i+=3;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fglt, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fglt: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fglt, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fglt:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case 'b':
                            i+=3;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fglb, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fglb: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fglb, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fglb:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        }
                        break;
                    case 'r': // (f g r
                        i+=2;
                        switch(input[i])
                        {
                        case 't': // ( f g r t
                            i+=3;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fgrt, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fgrt: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fgrt, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fgrt:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case 'b':
                            i+=3;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fgrb, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fgrb: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fgrb, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fgrb:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        }
                        break;
                    }
                    break;
                case 't': // (f t
                    i+=2;
                    switch(input[i])
                    {
                    case 'l': // (f t l
                        i+=2;
                        switch(input[i])
                        {
                        case '1': // (f t l 10)
                            i+=4;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            double distance;
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            double direction;
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::ftl10, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "ftl10: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::ftl10, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "ftl10:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case '2':
                            i+=4;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::ftl20, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "ftl20: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::ftl20, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "ftl20:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case '3':
                            i+=4;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::ftl30, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "ftl30: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::ftl30, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "ftl30:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case '4':
                            i+=4;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::ftl40, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "ftl40: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::ftl40, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "ftl40:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case '5':
                            i+=4;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::ftl50, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "ftl50: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::ftl50, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "ftl50:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case 'b':
                            break;
                        }
                        break;
                    case 'r': // (f t r
                        i+=2;
                        switch(input[i])
                        {
                        case '1': // (f t r 10)
                            i+=4;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            double distance;
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            double direction;
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::ftr10, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "ftr10: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::ftr10, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "ftr10:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case '2':
                            i+=4;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::ftr20, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "ftr20: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::ftr20, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "ftr20:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case '3':
                            i+=4;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::ftr30, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "ftr30: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::ftr30, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "ftr30:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case '4':
                            i+=4;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::ftr40, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "ftr40: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::ftr40, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "ftr40:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case '5':
                            i+=4;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::ftr50, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "ftr50: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::ftr50, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "ftr50:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        }
                        break;
                    case '0': // (f t 0)
                        i+=3;
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        double distance;
                        distance = atof(value);
                        ++i;
                        j=0;
                        while(input[i]!=' ' && input[i]!=')')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        double direction;
                        direction = atof(value);
                        if(input[i]==')')
                        {
                            data = new objectData(distance,direction);
                            seeingObject = new object(&objectType::ft0, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "ft0: "
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << std::endl;
                            break;
                        }
                        ++i;
                        j=0;
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        distanceChange = atof(value);
                        ++i;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        directionChange = atof(value);
                        data = new objectData(distance,direction,distanceChange,directionChange);
                        seeingObject = new object(&objectType::ft0, data);
                        see::seeingObjects.append(seeingObject);
                        std::cout << "ft0:"
                                  << see::seeingObjects.last()->data->distance << " "
                                  << see::seeingObjects.last()->data->direction << " "
                                  << see::seeingObjects.last()->data->distChange << " "
                                  << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                        break;
                    }
                    break;
                case 'b': // (f b
                    i+=2;
                    switch(input[i])
                    {
                    case 'l': // (f b l
                        i+=2;
                        switch(input[i])
                        {
                        case '1': // (f b l 10)
                            i+=4;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            double distance;
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            double direction;
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fbl10, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fbl10: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fbl10, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fbl10:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case '2':
                            i+=4;
                            j=0;
                            while(input[i]!=' ')
                                value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fbl20, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fbl20: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fbl20, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fbl20:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                            //
                        case '3':
                            i+=4;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fbl30, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fbl30: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fbl30, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fbl30:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case '4':
                            i+=4;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fbl40, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fbl40: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fbl40, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fbl40:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case '5':
                            i+=4;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fbl50, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fbl50: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction);
                            seeingObject = new object(&objectType::fbl50, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fbl50: "
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << std::endl;
                            break;
                        }
                        break;
                    case 'r': // (f b r
                        i+=2;
                        switch(input[i])
                        {
                        case '1': // (f b r 10)
                            i+=4;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            double distance;
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            double direction;
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fbr10, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fbr10: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fbr10, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fbr10:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case '2':
                            i+=4;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fbr20, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fbr20: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fbr20, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fbr20:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                            //
                        case '3':
                            i+=4;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fbr30, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fbr30: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction);
                            seeingObject = new object(&objectType::fbr30, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fbr30: "
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << std::endl;
                            break;
                        case '4':
                            i+=4;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fbr40, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fbr40: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fbr40, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fbr40:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        case '5':
                            i+=4;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distance = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=' ' && input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            direction = atof(value);
                            if(input[i]==')')
                            {
                                data = new objectData(distance,direction);
                                seeingObject = new object(&objectType::fbr50, data);
                                see::seeingObjects.append(seeingObject);
                                std::cout << "fbr50: "
                                          << see::seeingObjects.last()->data->distance << " "
                                          << see::seeingObjects.last()->data->direction << std::endl;
                                break;
                            }
                            ++i;
                            j=0;
                            while(input[i]!=' ')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            distanceChange = atof(value);
                            ++i;
                            j=0;
                            while(input[i]!=')')
                            {
                                value[j] = input[i];
                                ++i;
                                ++j;
                            }
                            value[j]='\0';
                            directionChange = atof(value);
                            data = new objectData(distance,direction,distanceChange,directionChange);
                            seeingObject = new object(&objectType::fbr50, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fbr50:"
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << " "
                                      << see::seeingObjects.last()->data->distChange << " "
                                      << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                            break;
                        }
                        break;
                    case '0': // (f b 0)
                        i+=3;
                        j=0;
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        double distance;
                        distance = atof(value);
                        ++i;
                        j=0;
                        while(input[i]!=' ' && input[i]!=')')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        double direction;
                        direction = atof(value);
                        if(input[i]==')')
                        {
                            data = new objectData(distance,direction);
                            seeingObject = new object(&objectType::fb0, data);
                            see::seeingObjects.append(seeingObject);
                            std::cout << "fb0: "
                                      << see::seeingObjects.last()->data->distance << " "
                                      << see::seeingObjects.last()->data->direction << std::endl;
                            break;
                        }
                        ++i;
                        j=0;
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        distanceChange = atof(value);
                        ++i;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        directionChange = atof(value);
                        data = new objectData(distance,direction,distanceChange,directionChange);
                        seeingObject = new object(&objectType::fb0, data);
                        see::seeingObjects.append(seeingObject);
                        std::cout << "fb0:"
                                  << see::seeingObjects.last()->data->distance << " "
                                  << see::seeingObjects.last()->data->direction << " "
                                  << see::seeingObjects.last()->data->distChange << " "
                                  << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                        break;
                    }
                    break;
                }
                break;
            case 'p':
                ++i;
                switch(input[i])
                {
                case ')': // (p)
                    i+=2;
                    j=0;
                    while(input[i]!=' ')
                    {
                        value[j]=input[i];
                        ++j;
                        ++i;
                    }
                    value[j]='\0';
                    distance = atof(value);
                    ++i;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j]=input[i];
                        ++j;
                        ++i;
                    }
                    value[j]='\0';
                    direction = atof(value);
                    data = new playerData(distance,direction);
                    seeingObject = new object(&objectType::p, data);
                    see::seeingObjects.append(seeingObject);
                    test = ((playerData*)see::seeingObjects.last()->data);
                    std::cout << "p: "
                              << test->distance << " "
                              << test->direction << std::endl;
                    //                    std::cout << "seen player "
                    //                              << "   " << distance
                    //                              << "   " << direction
                    //                              <<std::endl;
                    break;
                case ' ': // (p "teamName"
                    i+=2;
                    while(input[i]!='\"')
                    {
                        teamName[j]=input[i];
                        ++i;
                        ++j;
                    }
                    teamName[j]='\0';
                    ++i;
                    switch(input[i])
                    {
                    case ')': // (p "teamName")
                        i+=2;
                        j=0;
                        while(input[i]!=' ')
                        {
                            value[j]=input[i];
                            ++j;
                            ++i;
                        }
                        value[j]='\0';
                        distance = atof(value);
                        ++i;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j]=input[i];
                            ++j;
                            ++i;
                        }
                        value[j]='\0';
                        direction = atof(value);
                        data = new playerData(teamName,distance,direction);
                        seeingObject = new object(&objectType::p, data);
                        see::seeingObjects.append(seeingObject);
                        test = ((playerData*)see::seeingObjects.last()->data);
                        std::cout << "p: "
                                  << test->teamName << " "
                                  << test->distance << " "
                                  << test->direction << std::endl;
                        break;
                    case ' ': // (p "teamName"
                        ++i;
                        j=0;
                        while(input[i]!=')' && input[i]!=' ')
                        {
                            value[j]=input[i];
                            ++j;
                            ++i;
                        }
                        value[j]='\0';
                        int unum = atoi(value);
                        if(input[i]==' ')
                        {
                            ++i;
                            switch(input[i])
                            {
                            case 'g':
                                i+=6;
                                goalie=true;
                                break;
                            }
                        }
                        else
                        {
                            goalie=false;
                        }
                        i+=2;
                        j=0;
                        // start reading pleyer parameters
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        distance = atof(value);
                        ++i;
                        j=0;
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        direction = atof(value);
                        ++i;
                        j=0;
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        distanceChange = atof(value);
                        ++i;
                        j=0;
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        directionChange = atof(value);
                        ++i;
                        j=0;
                        while(input[i]!=' ')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        bodyFacingDir = atof(value);
                        ++i;
                        j=0;
                        while(input[i]!=')')
                        {
                            value[j] = input[i];
                            ++i;
                            ++j;
                        }
                        value[j]='\0';
                        headFacingDir = atof(value);
                        data = new playerData(teamName,unum,goalie,
                                              distance,direction,
                                              distanceChange, directionChange,bodyFacingDir,headFacingDir);
                        seeingObject = new object(&objectType::p, data);
                        see::seeingObjects.append(seeingObject);
                        break;
                    }
                    break;
                }
                break;
            case 'g':
                i+=2;
                switch(input[i])
                {
                case 'l':
                    i+=3;
                    j=0;
                    while(input[i]!=' ')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    distance = atof(value);
                    ++i;
                    j=0;
                    while(input[i]!=' ' && input[i]!=')')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    direction = atof(value);
                    if(input[i]==')')
                    {
                        data = new objectData(distance,direction);
                        seeingObject = new object(&objectType::gl, data);
                        see::seeingObjects.append(seeingObject);
                        std::cout << "gl: " << see::seeingObjects.last()->data->distance << " " << see::seeingObjects.last()->data->direction << std::endl;
                        break;
                    }
                    ++i;
                    j=0;
                    while(input[i]!=' ')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    distanceChange = atof(value);
                    ++i;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    directionChange = atof(value);
                    data = new objectData(distance,direction,distanceChange,directionChange);
                    seeingObject = new object(&objectType::gl, data);
                    see::seeingObjects.append(seeingObject);
                    std::cout << "gl:" << see::seeingObjects.last()->data->distance << " " << see::seeingObjects.last()->data->direction << " " << see::seeingObjects.last()->data->distChange << " " << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                    break;
                case 'r': // (g r)
                    i+=3;
                    j=0;
                    while(input[i]!=' ')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    distance = atof(value);
                    ++i;
                    j=0;
                    while(input[i]!=' ' && input[i]!=')')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    direction = atof(value);
                    if(input[i]==')')
                    {
                        data = new objectData(distance,direction);
                        seeingObject = new object(&objectType::gr, data);
                        see::seeingObjects.append(seeingObject);
                        std::cout << "gr: " << see::seeingObjects.last()->data->distance << " " << see::seeingObjects.last()->data->direction << std::endl;
                        break;
                    }
                    ++i;
                    j=0;
                    while(input[i]!=' ')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    distanceChange = atof(value);
                    ++i;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    directionChange = atof(value);
                    data = new objectData(distance,direction,distanceChange,directionChange);
                    seeingObject = new object(&objectType::gr, data);
                    see::seeingObjects.append(seeingObject);
                    std::cout << "gr:" << see::seeingObjects.last()->data->distance << " " << see::seeingObjects.last()->data->direction << " " << see::seeingObjects.last()->data->distChange << " " << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                    break;
                }
                break;
            case 'l':
                i+=2;
                switch(input[i])
                {
                case 'l':
                    j=0;
                    while(input[i]!=' ')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    distance = atof(value);
                    ++i;
                    j=0;
                    while(input[i]!=' ' && input[i]!=')')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    direction = atof(value);
                    if(input[i]==')')
                    {
                        data = new objectData(distance,direction);
                        seeingObject = new object(&objectType::ll, data);
                        see::seeingObjects.append(seeingObject);
                        std::cout << "ll: " << see::seeingObjects.last()->data->distance << " " << see::seeingObjects.last()->data->direction << std::endl;
                        break;
                    }
                    ++i;
                    j=0;
                    while(input[i]!=' ')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    distanceChange = atof(value);
                    ++i;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    directionChange = atof(value);
                    data = new objectData(distance,direction,distanceChange,directionChange);
                    seeingObject = new object(&objectType::ll, data);
                    see::seeingObjects.append(seeingObject);
                    std::cout << "ll:" << see::seeingObjects.last()->data->distance << " " << see::seeingObjects.last()->data->direction << " " << see::seeingObjects.last()->data->distChange << " " << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                    break;
                case 'r':
                    j=0;
                    while(input[i]!=' ')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    distance = atof(value);
                    ++i;
                    j=0;
                    while(input[i]!=' ' && input[i]!=')')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    direction = atof(value);
                    if(input[i]==')')
                    {
                        data = new objectData(distance,direction);
                        seeingObject = new object(&objectType::lr, data);
                        see::seeingObjects.append(seeingObject);
                        std::cout << "lr: "
                                  << see::seeingObjects.last()->data->distance << " "
                                  << see::seeingObjects.last()->data->direction << std::endl;
                        break;
                    }
                    ++i;
                    j=0;
                    while(input[i]!=' ')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    distanceChange = atof(value);
                    ++i;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    directionChange = atof(value);
                    data = new objectData(distance,direction,distanceChange,directionChange);
                    seeingObject = new object(&objectType::lr, data);
                    see::seeingObjects.append(seeingObject);
                    std::cout << "lr:"
                              << see::seeingObjects.last()->data->distance << " "
                              << see::seeingObjects.last()->data->direction << " "
                              << see::seeingObjects.last()->data->distChange << " "
                              << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                    break;
                case 't':
                    j=0;
                    while(input[i]!=' ')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    distance = atof(value);
                    ++i;
                    j=0;
                    while(input[i]!=' ' && input[i]!=')')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    direction = atof(value);
                    if(input[i]==')')
                    {
                        data = new objectData(distance,direction);
                        seeingObject = new object(&objectType::lt, data);
                        see::seeingObjects.append(seeingObject);
                        std::cout << "lt: "
                                  << see::seeingObjects.last()->data->distance << " "
                                  << see::seeingObjects.last()->data->direction << std::endl;
                        break;
                    }
                    ++i;
                    j=0;
                    while(input[i]!=' ')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    distanceChange = atof(value);
                    ++i;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    directionChange = atof(value);
                    data = new objectData(distance,direction,distanceChange,directionChange);
                    seeingObject = new object(&objectType::lt, data);
                    see::seeingObjects.append(seeingObject);
                    std::cout << "lt:"
                              << see::seeingObjects.last()->data->distance << " "
                              << see::seeingObjects.last()->data->direction << " "
                              << see::seeingObjects.last()->data->distChange << " "
                              << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                    break;
                case 'b':
                    j=0;
                    while(input[i]!=' ')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    distance = atof(value);
                    ++i;
                    j=0;
                    while(input[i]!=' ' && input[i]!=')')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    direction = atof(value);
                    if(input[i]==')')
                    {
                        data = new objectData(distance,direction);
                        seeingObject = new object(&objectType::lb, data);
                        see::seeingObjects.append(seeingObject);
                        std::cout << "lb: "
                                  << see::seeingObjects.last()->data->distance << " "
                                  << see::seeingObjects.last()->data->direction << std::endl;
                        break;
                    }
                    ++i;
                    j=0;
                    while(input[i]!=' ')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    distanceChange = atof(value);
                    ++i;
                    j=0;
                    while(input[i]!=')')
                    {
                        value[j] = input[i];
                        ++i;
                        ++j;
                    }
                    value[j]='\0';
                    directionChange = atof(value);
                    data = new objectData(distance,direction,distanceChange,directionChange);
                    seeingObject = new object(&objectType::lb, data);
                    see::seeingObjects.append(seeingObject);
                    std::cout << "lb:"
                              << see::seeingObjects.last()->data->distance << " "
                              << see::seeingObjects.last()->data->direction << " "
                              << see::seeingObjects.last()->data->distChange << " "
                              << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                    break;
                }
                break;
            case 'B':
                i+=3;
                j=0;
                while(input[i]!=' ')
                {
                    value[j] = input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                distance = atof(value);
                ++i;
                j=0;
                while(input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                direction = atof(value);
                data = new objectData(distance,direction);
                seeingObject = new object(&objectType::B, data);
                see::seeingObjects.append(seeingObject);
                std::cout << "B: "
                          << see::seeingObjects.last()->data->distance << " "
                          << see::seeingObjects.last()->data->direction << std::endl;
                break;
            case 'F':
                i+=3;
                j=0;
                while(input[i]!=' ')
                {
                    value[j] = input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                distance = atof(value);
                ++i;
                j=0;
                while(input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                direction = atof(value);
                data = new objectData(distance,direction);
                seeingObject = new object(&objectType::F, data);
                see::seeingObjects.append(seeingObject);
                std::cout << "F: "
                          << see::seeingObjects.last()->data->distance << " "
                          << see::seeingObjects.last()->data->direction << std::endl;
                break;
            case 'G':
                i+=3;
                j=0;
                while(input[i]!=' ')
                {
                    value[j] = input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                distance = atof(value);
                ++i;
                j=0;
                while(input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                direction = atof(value);
                data = new objectData(distance,direction);
                seeingObject = new object(&objectType::G, data);
                see::seeingObjects.append(seeingObject);
                std::cout << "G: "
                          << see::seeingObjects.last()->data->distance << " "
                          << see::seeingObjects.last()->data->direction << std::endl;
                break;
            case 'P':
                i+=3;
                j=0;
                while(input[i]!=' ')
                {
                    value[j] = input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                distance = atof(value);
                ++i;
                j=0;
                while(input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                direction = atof(value);
                data = new objectData(distance,direction);
                seeingObject = new object(&objectType::P, data);
                see::seeingObjects.append(seeingObject);
                std::cout << "P: "
                          << see::seeingObjects.last()->data->distance << " "
                          << see::seeingObjects.last()->data->direction << std::endl;
                break;
            case 'b':
                i+=3;
                j=0;
                while(input[i]!=' ')
                {
                    value[j] = input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                distance = atof(value);
                ++i;
                j=0;
                while(input[i]!=' ' && input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                direction = atof(value);
                if(input[i]==')')
                {
                    data = new objectData(distance,direction);
                    seeingObject = new object(&objectType::ball, data);
                    see::seeingObjects.append(seeingObject);
                    std::cout << "ball: "
                              << see::seeingObjects.last()->data->distance << " "
                              << see::seeingObjects.last()->data->direction << std::endl;
                    break;
                }
                ++i;
                j=0;
                while(input[i]!=' ')
                {
                    value[j] = input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                distanceChange = atof(value);
                ++i;
                j=0;
                while(input[i]!=')')
                {
                    value[j] = input[i];
                    ++i;
                    ++j;
                }
                value[j]='\0';
                directionChange = atof(value);
                data = new objectData(distance,direction,distanceChange,directionChange);
                seeingObject = new object(&objectType::ball, data);
                see::seeingObjects.append(seeingObject);
                std::cout << "ball:"
                          << see::seeingObjects.last()->data->distance << " "
                          << see::seeingObjects.last()->data->direction << " "
                          << see::seeingObjects.last()->data->distChange << " "
                          << see::seeingObjects.last()->data->dirChange << " " << std::endl;
                break;
            }
            ++i;
        }
    }
}
