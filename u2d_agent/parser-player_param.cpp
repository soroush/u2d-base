#include <iostream>
#include <stdlib.h>
#include "parserbase.h"
#include <player_param.h>

void ParserBase::pp_startRead()
{
    int j;
    char value[20];
    while(input[i]=='(')
    {
        ++i;
        switch(input[i])
        {
        case 'a':
            i+=24;
            j=0;
            while(input[i]!=')')
            {
                value[j] = input[i];
                ++i;
                ++j;
            }
            value[j]='\0';
            player_param::allow_mult_default_type = atoi(value) > 0? true : false;
            break;
        case 'c':
            i+=26;
            switch(input[i])
            {
            case 'a':
                break;
            case 'i':
                break;
            }
            break;
        case 'd':
            break;
        case 'e':
            break;
        case 'f':
            break;
        case 'i':
            break;
        case 'k':
            break;
        case 'n':
            break;
        case 'p':
            break;
        case 'r':
            break;
        case 's':
            break;
        }
        ++i;
    }
}
