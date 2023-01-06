#include "salamtak.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Salamtak w;
    w.setRooms();
    w.setEmergency();
    w.show();
    return a.exec();
}
