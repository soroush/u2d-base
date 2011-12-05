#include <iostream>
#include <QString>
#include "parserbase.h"
#include "agent.h"

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
    int time;
    time = atoi(value);
    std::cout << "time: " << time << std::endl;
    while(input[i]!=')')
        ss_readParameter();
}

void ParserBase::ss_readParameter()
{
    ++i; // pass the ' '
    int j=0;
    double distance=0, direction=0, distanceChange=0, directionChange=0, bodyFacingDir=0, HeadFacingDir=0;
    bool goalie = false;
    char value[5];
    char teamName[50];
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
                            std::cout << "seen flag (f c) "<< distance << "   " << direction << std::endl;
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
                        std::cout << "seen flag (f c) "<< distance << "   " << direction<< distanceChange << "   " << directionChange << std::endl;
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
                                std::cout << "seen flag (f c t) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f c t) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f c b) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f c b) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f r t) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f r t) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f r t 10) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f r t 10) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f r t 20) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f r t 20) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f r t 30) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f r t 30) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f r t 40) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f r t 40) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f r t 50) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f r t 50) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f r b) "<< distance << "   " << direction << "   " <<std::endl;
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
                            std::cout << "seen flag (f r b) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f r b 10) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f r b 10) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f r b 20) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f r b 20) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f r b 30) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f r b 30) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f r b 40) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f r b 40) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f r b 50) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f r b 50) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                            std::cout << "seen flag (f r 0) "<< distance << "   " << direction << "   " <<std::endl;
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
                        std::cout << "seen flag (f r 0) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f l t) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f l t) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f l t 10) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f l t 10) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f l t 20) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f l t 20) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f l t 30) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f l t 30) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f l t 40) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f l t 40) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f l t 50) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f l t 50) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f l b) "<< distance << "   " << direction << "   " <<std::endl;
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
                            std::cout << "seen flag (f l b) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f l b 10) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f l b 10) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f l b 20) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f l b 20) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f l b 30) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f l b 30) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f l b 40) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f l b 40) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                    std::cout << "seen flag (f l b 50) "<< distance << "   " << direction << std::endl;
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
                                std::cout << "seen flag (f l b 50) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                            std::cout << "seen flag (f l 0) "<< distance << "   " << direction << "   " <<std::endl;
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
                        std::cout << "seen flag (f l 0) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f p l t) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f p l t) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f p l c) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f p l c) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;

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
                                std::cout << "seen flag (f p l b) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f p l b) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f p r t) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f p r t) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f p r c) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f p r c) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;

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
                                std::cout << "seen flag (f p r b) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f p r b) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f g l t) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f g l t) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f g l b) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f g l b) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f g r t) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f g r t) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f g r b) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f g r b) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f t l 10) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f t l 10) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f t l 20) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f t l 20) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
                            break;
                            //
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
                                std::cout << "seen flag (f t l 30) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f t l 30) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f t l 40) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f t l 40) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f t l 50) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f t l 50) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f t r 10) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f t r 10) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f t r 20) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f t r 20) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
                            break;
                            //
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
                                std::cout << "seen flag (f t r 30) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f t r 30) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f t r 40) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f t r 40) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f t r 50) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f t r 50) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
                            break;
                        case 'b':
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
                            std::cout << "seen flag (f t 0) "<< distance << "   " << direction << std::endl;
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
                        std::cout << "seen flag (f t 0) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f b l 10) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f b l 10) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f b l 20) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f b l 20) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f b l 30) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f b l 30) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f b l 40) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f b l 40) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f b l 50) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f b l 50) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
                            break;
                        case 'b':
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
                                std::cout << "seen flag (f b r 10) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f b r 10) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f b r 20) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f b r 20) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f b r 30) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f b r 30) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f b r 40) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f b r 40) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                                std::cout << "seen flag (f b r 50) "<< distance << "   " << direction << std::endl;
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
                            std::cout << "seen flag (f b r 50) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
                            break;
                        case 'b':
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
                            std::cout << "seen flag (f b 0) "<< distance << "   " << direction << std::endl;
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
                        std::cout << "seen flag (f b 0) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
                        break;
                    }
                    break;
                default:
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
                    std::cout << "seen player "
                              << "   " << distance
                              << "   " << direction
                              <<std::endl;
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
                        std::cout << "seen player "
                                  << teamName
                                  << "   " << distance
                                  << "   " << direction
                                  <<std::endl;
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
                        HeadFacingDir = atof(value);
                        std::cout << "seen player "
                                  << teamName
                                  << "   " << unum
                                  << "   " << distance
                                  << "   " << direction
                                  << "   " << distanceChange
                                  << "   " << directionChange
                                  << "   " << bodyFacingDir
                                  << "   " << HeadFacingDir
                                  << "   " << (goalie ? "goalie" : "player")
                                  <<std::endl;
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
                        std::cout << "seen flag (g l) "<< distance << "   " << direction << std::endl;
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
                    std::cout << "seen flag (g l) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                        std::cout << "seen flag (g r) "<< distance << "   " << direction << std::endl;
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
                    std::cout << "seen flag (g r) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                        std::cout << "seen flag (l l) "<< distance << "   " << direction << std::endl;
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
                    std::cout << "seen flag (l l) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                        std::cout << "seen flag (l r) "<< distance << "   " << direction << std::endl;
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
                    std::cout << "seen flag (l r) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                        std::cout << "seen flag (l t) "<< distance << "   " << direction << std::endl;
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
                    std::cout << "seen flag (l t) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                        std::cout << "seen flag (l b) "<< distance << "   " << direction << std::endl;
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
                    std::cout << "seen flag (l b) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                    std::cout << "seen flag (B) "<< distance << "   " << direction << std::endl;
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
                std::cout << "seen flag (B) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                    std::cout << "seen flag (F) "<< distance << "   " << direction << std::endl;
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
                std::cout << "seen flag (F) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                    std::cout << "seen flag (G) "<< distance << "   " << direction << std::endl;
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
                std::cout << "seen flag (G) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                    std::cout << "seen flag (P) "<< distance << "   " << direction << std::endl;
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
                std::cout << "seen flag (P) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
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
                    std::cout << "seen flag (b) "<< distance << "   " << direction << std::endl;
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
                std::cout << "seen flag (b) "<< distance << "   " << direction << "   " << distanceChange << "   " << directionChange <<std::endl;
                break;
            }
            ++i;
        }
    }
}
