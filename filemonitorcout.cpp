#include <QFileInfo>

#include "filemonitorcout.h"
#include "filestate.h"

//using namespace std::cout

FileMonitorCout::FileMonitorCout(FileStateTracker &fst) {
    connect(fst, fst.fileAddSuccess, this, fileAddSuccess);
    connect(fst, fst.fileAddFailureAlreadyExists, this, fileAddFailureAlreadyExists);
    connect(fst, fst.fileRemoveSuccess, this, fileRemoveSuccess);
    connect(fst, fst.fileRemoveFailureDoesntExist, this, fileRemoveFailureDoesntExist);
    connect(fst, fst.fileCreated, this, fileCreated);
    connect(fst, fst.fileDeleted, this, fileDeleted);
    connect(fst, fst.fileChanged, this, fileChanged);
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
    cout << fi.fullPath() << " не был добавлен для отслеживания, т.к. уже отслеживается.\n";
}

void FileMonitorCout::fileRemoveSuccess(QFileInfo &fi)
{
    cout << fi.fullPath() << " был снят с отслеживания.\n";
}

void FileMonitorCout::fileRemoveFailureDoesntExist(QFileInfo &fi)
{
    cout << fi.fullPath() << " не был снят с отслеживания, т.к. не был отслеживаем.\n";
}

void FileMonitorCout::fileCreated(FileState &f)
{
    QFileInfo fi = f.QFileInfo();
    cout << fi.fullPath() << " был создан. Размер " << f.size() << ".\n";
}

void FileMonitorCout::fileDeleted(FileState &f)
{
    QFileInfo fi = f.QFileInfo();
    cout << fi.fullPath() << " был удален.\n";
}

void FileMonitorCout::fileChanged(FileState &f)
{
    QFileInfo fi = f.QFileInfo();
    cout << fi.fullPath() << " был изменен. Размер " << f.size() << ".\n";
}
