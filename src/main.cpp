#include <iostream>
#include <string>

#include "agent.h"
#include "model/sense_body.h"

using namespace std;

int main()
{
    Agent x;
    x.setTeamName("FC_Urmia");
    x.setAddress("127.0.0.1");
    x.setPort(6000);
    x.setVersion(15);
    x.setGoalie(false);
    x.start();
    return 0;
}

