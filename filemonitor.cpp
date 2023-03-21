#include "filemonitor.h"

FileMonitor::FileMonitor(QObject *parent) : QObject(parent)
{
    //
    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &FileMonitor::checkOnFiles);
    timer->start(100);
}

bool FileMonitor::addFile(QString path)
{
    files.push_back(FileState(path));
    return true;
}

bool FileMonitor::delFile(QString path)
{

}

void FileMonitor::checkOnFiles()
{
    for(auto &i: files) {
        i.updateAndDisplayState();
    }
}
/**/
