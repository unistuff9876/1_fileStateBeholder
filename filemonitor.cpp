#include "filemonitor.h"

FileMonitor::FileMonitor(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &FileMonitor::updateAndDisplayFileInfo);
    timer->start(1000);
}

bool FileMonitor::addFile(QString path)
{
    files.push_back(FileState(path));
    return 1;
}

bool FileMonitor::delFile(QString path)
{

}

void FileMonitor::updateAndDisplayFileInfo()
{
    for(auto &i: files) {
        i.updateAndDisplayState();
    }
}
