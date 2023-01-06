#ifndef EMERGENCY_H
#define EMERGENCY_H
#include <QString>
#include <QDate>
#include <QTime>

class emergency
{
    QDate date;
    bool status;
public:
    emergency();
    void setStatus(bool x);
    void setDate(QDate x);
    bool isAvailable();
    QDate getDate();

};

#endif // EMERGENCY_H
