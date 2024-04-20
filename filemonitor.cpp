#include <QTextStream>

#include "filemonitor.h"
#include "filestatedelta.h"
#include "consoleoutput.h"

FileStateTracker::FileStateTracker(QObject *parent) : QObject(parent)
{

}

FileStateDelta FileStateTracker::updateFileState(FileState &fileState)
{
    FileStateDelta stateDelta;

    stateDelta.name = fileState.getName();

    //refreshing so we don't read stale data
    fileState.getQFileInfo().refresh();

    if (!fileState.exists()) {
        if (fileState.exists_prev()) {
            stateDelta.state = Deleted;
            fileState.exists_prev() = false;
        } else {
            stateDelta.state = DoesntExist;
        }
        return stateDelta;
    }

    stateDelta.state = Exists;
    if (!fileState.exists_prev()) {
        stateDelta.state = Created;
        fileState.exists_prev() = true;
        fileState.lastModified_prev()
                = fileState.getQFileInfo().lastModified();
    } else
    if (fileState.getQFileInfo().lastModified() != fileState.lastModified_prev()) {
        stateDelta.state = Modified;
        fileState.lastModified_prev()
                = fileState.getQFileInfo().lastModified();
    }

    stateDelta.size = fileState.getSize();
    return stateDelta;
}

void FileStateTracker::displayFileStateDelta(FileStateDelta stateDelta)
{
    cout() << stateDelta.name << ":\n";

    switch(stateDelta.state) {
        case DoesntExist:
            cout() << "doesn't exist\n";
            return;
        case Deleted:
            cout() << "was deleted\n";
            return;
        case Created:
            cout() << "was created\n";
            break;
        case Modified:
            cout() << "was changed!\n";
            break;
        case Exists:
            break;
    }

    cout() << stateDelta.size << " bytes\n";
    cout().flush();
}

//if path given is NOT in fileMon returns true
//and adds it, otherwise returns false
bool FileStateTracker::addFile(QString path)
{
    QFileInfo fileToAdd(path);
    for(auto it = files.begin(); it < files.end(); it++) {
        if (it->getQFileInfo() == fileToAdd) {
            return false;
        }
    }
    files.push_back(FileState(path));
    return true;
}

//if path given IS in fileMon returns true
//and removes it, otherwise returns false
bool FileStateTracker::delFile(QString path)
{
    QFileInfo fileToDelete(path);
    for(auto it = files.begin(); it < files.end(); it++) {
        if (it->getQFileInfo() == fileToDelete) {
            files.erase(it);
            return true;
        }
    }
    return false;
}

void FileStateTracker::updateAndDisplayFileInfo()
{
    for(auto &i: files) {
        displayFileStateDelta(updateFileState(i));
    }
}
