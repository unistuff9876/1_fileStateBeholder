#include <QCoreApplication>
#include "filemonitor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileMonitor *fileMonitor = new FileMonitor;
    fileMonitor->addFile("C:\\a.txt");
    fileMonitor->addFile("C:\\b.txt");

    //QTimer timerCloseB();
    //timerCloseB().setSingleShot(true);
    //timerCloseB().connect(timerCloseB, &QTimer::timeout, fileMonitor, &FileMonitor::delFile("C:\\b.txt"));
    //timerCloseB().start(3000);

    return a.exec();
}
