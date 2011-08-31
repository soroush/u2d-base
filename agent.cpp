#include "agent.h"
#include "connection.h"

Agent::Agent(int argc, char *argv[]) :
    QCoreApplication(argc, argv),
    teamName(QLatin1String("")),
    connection(Connection(this))
{
    if(argc > 1)
        teamName = QLatin1String(argv[1]);
    if(argc > 2)
        connection.address = QHostAddress(argv[2]);
    if(argc > 3)
        connection.portNumber = atoi(argv[3]);
    // Initializing teammate:
    qDebug()<<"Team name:\t"<<teamName;
    connection.initialize();
}
// add a comment here
