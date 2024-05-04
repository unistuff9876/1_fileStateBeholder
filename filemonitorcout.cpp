#include <iostream>
#include <QFileInfo>

#include "filemonitorcout.h"
#include "filestate.h"

FileMonitorCout::FileMonitorCout()
{

}

void FileMonitorCout::fileAddSuccess(FileState &f)
{
    QFileInfo fi = f.getQFileInfo();
    std::cout << fi.getFullPath() << " был добавлен\n";
}

void FileMonitorCout::fileAddFailureAlreadyExists(FileState &f)
{

}

void FileMonitorCout::fileRemoveSuccess(FileState &f)
{

}

void FileMonitorCout::fileRemoveFailureDoesntExist(FileState &f)
{

}

void FileMonitorCout::fileCreated(FileState &f)
{

}

void FileMonitorCout::fileDeleted(FileState &f)
{

}

void FileMonitorCout::fileChanged(FileState &f)
{

}
