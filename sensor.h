#ifndef SENSOR_H
#define SENSOR_H

#include <QObject>
#include "server_param.h"
#include "sense_body.h"

class Sensor : public QObject
{
    Q_OBJECT
public:
    explicit Sensor(QObject *parent = 0);
    server_param server;
    sense_body body;
signals:

public slots:

};

#endif // SENSOR_H
