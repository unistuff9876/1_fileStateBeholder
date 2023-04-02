#include <QCoreApplication>

#include <QTimer>

#include "filemonitor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileMonitor &fileMonitor = FileMonitor::Instance();
    fileMonitor.addFile("C:\\a.txt");
    fileMonitor.addFile("C:\\b.txt");

    QTimer timer_checkFiles;
    timer_checkFiles.connect(&timer_checkFiles, &QTimer::timeout,
                             &fileMonitor, &FileMonitor::updateAndDisplayFileInfo);
    timer_checkFiles.start(200);

    //QTimer timerCloseB;
    //timerCloseB().setSingleShot(true);
    //timerCloseB().connect(&timerCloseB, &QTimer::timeout, &fileMonitor, &FileMonitor::delFile("C:\\b.txt"));
    //timerCloseB().start(3000);

    return a.exec();
}
