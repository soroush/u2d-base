#include "agent.h"
#include "connection.h"
#include "cmdline.h"
#include <iostream>

Agent::Agent(int argc, char *argv[]) :
    QCoreApplication(argc, argv),
    teamName(QString("")),
    connection(Connection(this)),
    goalie(false),
    configurationFile(QString())
{
    gengetopt_args_info args_info;
    if (cmdline_parser(argc, argv, &args_info) != 0)
      exit(1) ;
    teamName = QLatin1String(args_info.team_arg);
    configurationFile = QString(args_info.configuration_arg);
    if(args_info.host_given)
        connection.address = QHostAddress(args_info.host_arg);
    else
        connection.address = QHostAddress::LocalHost;
    if(args_info.port_given)
        connection.portNumber = args_info.port_arg;
    else
        connection.portNumber = 6000;

    // Initializing teammate:
    std::cout << "Team name:\t" << teamName.toAscii().data() << std::endl;
    parser.agent = this;
    cmdline_parser_free(&args_info);
    connection.initialize();
}
// add a comment here
