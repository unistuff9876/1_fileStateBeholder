#include "filemonitor.h"

FileMonitor::FileMonitor(QObject *parent) : QObject(parent)
{

}

bool FileMonitor::addFile(QString path)
{
    objects.push_back(FileState(path));
    return true;
}

bool FileMonitor::delFile(QString path)
{

}
/**/
