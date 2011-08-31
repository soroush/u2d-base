#ifndef BODYSENSOR_H
#define BODYSENSOR_H

#include <QObject>

class BodySensor : public QObject
{
    Q_OBJECT
public:
    explicit BodySensor(QObject *parent = 0);

signals:

public slots:

};

#endif // BODYSENSOR_H
