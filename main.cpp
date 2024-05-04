#include <QCoreApplication>

#include <QTimer>

#include "filemonitor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileStateTracker &fileMonitor = FileStateTracker::instance();
    fileMonitor.addFile("C:\\a.txt");
    fileMonitor.addFile("C:\\b.txt");

    QTimer timer_checkFiles;
    timer_checkFiles.connect(&timer_checkFiles, &QTimer::timeout,
                             &fileMonitor, &FileStateTracker::updateAndDisplay);
    timer_checkFiles.start(500);

    QTimer timer_closeB;
    timer_closeB.setSingleShot(true);
    timer_closeB.connect(&timer_closeB, &QTimer::timeout, &fileMonitor,
                         [&fileMonitor]{ fileMonitor.removeFile("C:\\b.txt"); });
    timer_closeB.start(10000);

    return a.exec();
}
