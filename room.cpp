#include "room.h"

room::room()
{

}

void room::setSpec(QString x){
    spec = x;
}
void room::setId(int x){
    id = x;
}
void room::setDate(QDate x){
    date = x;
}
void room::setTime(QTime x){
    time = x;
}
QString room::getSpec(){
    return spec;
}
int room::getId(){
    return id;
}
QDate room::getDate(){
    return date;
}
QTime room::getTime(){
    return time;
}

void room::setStatus(bool b)
{
    status = b;
}
bool room::getStatus()
{
    return status;
}
