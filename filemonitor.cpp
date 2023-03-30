#include <QTextStream>

#include "filemonitor.h"
#include "filestatedelta.h"

FileMonitor::FileMonitor(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &FileMonitor::updateAndDisplayFileInfo);
    timer->start(1000);
}

FileStateDelta FileMonitor::updateFileState(FileState &fileState)
{
    FileStateDelta stateDelta;

    stateDelta.name = fileState.getName();

    //refreshing file info so we dont read cached
    fileState.getFi().refresh();

    if (!fileState.exists()) {
        if (fileState.exists_prev()) {
            stateDelta.state = Deleted;
            fileState.exists_prev() = 0;
        } else {
            stateDelta.state = DoesntExist;
        }
        return stateDelta;
    }

    stateDelta.state = Exists;
    if (!fileState.exists_prev()) {
        stateDelta.state = Created;
        fileState.exists_prev() = 1;
        fileState.lastModified_prev()
                = fileState.getFi().lastModified();
    } else
    if (fileState.getFi().lastModified() != fileState.lastModified_prev()) {
        stateDelta.state = Modified;
        fileState.lastModified_prev()
                = fileState.getFi().lastModified();
    }

    stateDelta.size = fileState.getSize();
    return stateDelta;
}

void FileMonitor::displayFileStateDelta(FileStateDelta stateDelta)
{
    //this REFUSES to work as static,
    //or via the qstdout function
    //workaround for now
    QTextStream cout(stdout);

    cout << stateDelta.name << ":\n";

    switch(stateDelta.state) {
        case DoesntExist:
            cout << "doesn't exist\n";
            return;
        case Deleted:
            cout << "was deleted\n";
            return;
        case Created:
            cout << "was created\n";
            break;
        case Modified:
            cout << "was changed!\n";
            break;
        case Exists:
            break;
    }

    cout << stateDelta.size << " bytes\n";
}

//if path given is NOT in fileMon returns 1
//and adds it, otherwise returns 0
bool FileMonitor::addFile(QString path)
{
    QFileInfo fileToAdd(path);
    for(auto it = files.begin(); it < files.end(); it++) {
        if (it->getFi() == fileToAdd) {
            return 0;
        }
    }
    files.push_back(FileState(path));
    return 1;
}

//if path given IS in fileMon returns 1
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
        displayFileStateDelta(updateFileState(i));
    }
}
