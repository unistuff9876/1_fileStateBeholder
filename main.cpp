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
    timer_checkFiles.start(800);

    QTimer timer_closeB;
    timer_closeB.setSingleShot(true);
    timer_closeB.connect(&timer_closeB, &QTimer::timeout, &fileMonitor,
                         [&fileMonitor]{ fileMonitor.delFile("C:\\b.txt"); });
    timer_closeB.start(4800);

    return a.exec();
}
