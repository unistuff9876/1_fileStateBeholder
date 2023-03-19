#include <QCoreApplication>
#include "filemonitor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //FileMonitor *monitor = new FileMonitor;
    //monitor->addFile("C:\\A.txt");

    return a.exec();
}
