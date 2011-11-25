#include "agent.h"
#include "connection.h"
#include <iostream>

Agent::Agent(int argc, char *argv[]) :
    QCoreApplication(argc, argv),
    teamName(QString("")),
    connection(Connection(this))
{
    if(argc > 1)
        teamName = QLatin1String(argv[1]);
    if(argc > 2)
        connection.address = QHostAddress(argv[2]);
    if(argc > 3)
        connection.portNumber = atoi(argv[3]);
    // Initializing teammate:
    std::cout << "Team name:\t" << teamName.toAscii().data() << std::endl;
    parser.agent = this;
    connection.initialize();
}
// add a comment here
