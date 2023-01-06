#include "emergency.h"

emergency::emergency()
{

}
void emergency::setStatus(bool x) {
    status = x;
}
void emergency::setDate(QDate x) {
    date = x;
}
bool emergency::isAvailable() {
    return status;
}
QDate emergency::getDate() {
    return date;
}
