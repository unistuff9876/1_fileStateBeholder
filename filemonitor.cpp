#include "filemonitor.h"

FileMonitor::FileMonitor(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &FileMonitor::updateAndDisplayFileInfo);
    timer->start(1000);
}

//if path given is in fileMon returns 1
//and adds it, otherwise returns 0
bool FileMonitor::addFile(QString path)
{
    //check
    QFileInfo fileToAdd(path);
    for(auto it = files.begin(); it < files.end(); it++) {
        if (it->getFi() == fileToAdd) {
            return 0;
        }
    }
    files.push_back(FileState(path));
    return 1;
}

//if path given is in fileMon returns 1
//and removes it, otherwise returns 0
bool FileMonitor::delFile(QString path)
{
    QFileInfo fileToDelete(path);
    for(auto it = files.begin(); it < files.end(); it++) {
        if (it->getFi() == fileToDelete) {
            files.erase(it);
            return 1;
        }
    }
    return 0;
}

void FileMonitor::updateAndDisplayFileInfo()
{
    for(auto &i: files) {
        //i.updateAndDisplayState();
    }
}
