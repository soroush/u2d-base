#ifndef VISUALSENSOR_H
#define VISUALSENSOR_H

#include <QObject>
#include <QPoint>

class VisualSensor : public QObject
{
    Q_OBJECT
public:
    explicit VisualSensor(QObject *parent = 0);
    enum Flag
    {
        c,
        prt,
        prc,
        prb,
        rt,
        grt,
        r,
        grb,
        rb,
        cb,
        ct,
        b0,
        t0,
        tr10,
        br10,
        tr20,
        br20,
        tr30,
        br30,
        tr40,
        br40,
        tr50,
        br50,
        plt,
        plc,
        plb,
        lt,
        glt,
        l,
        glb,
        lb,
        tl10,
        bl10,
        tl20,
        bl20,
        tl30,
        bl30,
        tl40,
        bl40,
        tl50,
        bl50
    };
    struct FlagData
    {
        FlagData(Flag _flagName, double _x, double _y)
            :flagName(_flagName), position(QPoint(_x,_y))
        {}
        Flag flagName;
        QPoint position;
    };
    /*  There are not any setter function here
    *   this class provides data holders for visual sensor information
    *   the parser will be able to set flags directly
    */
private:
    QList<FlagData> flags;
signals:
public slots:

};

#endif // VISUALSENSOR_H
