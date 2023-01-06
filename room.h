#ifndef ROOM_H
#define ROOM_H
#include <QString>
#include <QDate>
#include <QTime>


class room
{
private:
    QString spec;
    int id;
    QDate date;
    QTime time;
    bool status;
public:
    room();
    void setSpec(QString x);
    void setId(int x);
    void setDate(QDate x);
    void setTime(QTime x);
    QString getSpec();
    int getId();
    QDate getDate();
    QTime getTime();
    void setStatus(bool b);
    bool getStatus();

};

#endif // ROOM_H
