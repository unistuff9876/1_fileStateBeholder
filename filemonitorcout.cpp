#include <iostream>
#include <QFileInfo>

#include "filemonitorcout.h"
#include "filestate.h"

FileMonitorCout::FileMonitorCout(FileStateTracker &fst) {
    connect();
}

FileMonitorCout &FileMonitorCout::instance(FileStateTracker &fst) {
    static FileMonitorCout s;
    return s;
}

void FileMonitorCout::fileAddSuccess(QFileInfo &fi)
{
    std::cout << fi.fullPath() << " был добавлен для отлеживания.\n";
}

void FileMonitorCout::fileAddFailureAlreadyExists(QFileInfo &fi)
{
    std::cout << fi.fullPath() << " не был добавлен для отслеживания, т.к. уже отслеживается.\n";
}

void FileMonitorCout::fileRemoveSuccess(QFileInfo &fi)
{
    std::cout << fi.fullPath() << " был снят с отслеживания.\n";
}

void FileMonitorCout::fileRemoveFailureDoesntExist(QFileInfo &fi)
{
    std::cout << fi.fullPath() << " не был снят с отслеживания, т.к. не был отслеживаем.\n";
}

void FileMonitorCout::fileCreated(FileState &f)
{
    QFileInfo fi = f.QFileInfo();
    std::cout << fi.fullPath() << " был создан. Размер " << f.size() << ".\n";
}

void FileMonitorCout::fileDeleted(FileState &f)
{
    QFileInfo fi = f.QFileInfo();
    std::cout << fi.fullPath() << " был удален.\n";
}

void FileMonitorCout::fileChanged(FileState &f)
{
    QFileInfo fi = f.QFileInfo();
    std::cout << fi.fullPath() << " был изменен. Размер " << f.size() << ".\n";
}
