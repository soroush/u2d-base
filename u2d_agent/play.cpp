#include "agent.h"
#include "see.h"
#include "sense_body.h"
#include "server_param.h"
#include "init.h"

void Agent::init()
{
    // read configuration file
    // initialize 'Player' data
}

void Agent::play()
{
    switch(Init::playMode)
    {
    case Init::before_kick_off:
        break;
    case Init::play_on:
        break;
    }
}
