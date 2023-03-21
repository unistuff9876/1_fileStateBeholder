#include <QCoreApplication>
#include "filemonitor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileMonitor *fileMonitor = new FileMonitor;
    fileMonitor->addFile("C:\\a.txt");

    return a.exec();
}
