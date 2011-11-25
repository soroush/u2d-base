#include "sensor.h"

Sensor::Sensor(QObject *parent) :
    QObject(parent),
    body(sense_body())
{
}
