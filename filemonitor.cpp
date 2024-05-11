#include <QTextStream>

#include "filemonitor.h"
#include "filestatedelta.h"

FileStateTracker::FileStateTracker(QObject *parent) : QObject(parent)
{

}

//if path given is NOT in fileMon returns true
//and adds it, otherwise returns false
bool FileStateTracker::addFile(QString path)
{
    QFileInfo fileToAdd(path);
    for(auto it = files.begin(); it < files.end(); it++) {
        if (it->fi == fileToAdd) {
            emit fileAddFailureAlreadyTracked(fileToAdd);
            return false;
        }
    }

    if (fileToAdd.exists()) {
        emit fileAddSuccessExists(fileToAdd);
    } else {
        emit fileAddSuccessDoesntExist(fileToAdd);
    }

    files.push_back(fileToAdd);
    return true;
}

//if path given IS in fileMon returns true
//and removes it, otherwise returns false
bool FileStateTracker::removeFile(QString path)
{
    QFileInfo fileToRemove(path);
    for(auto it = files.begin(); it < files.end(); it++) {
        if (it->fi == fileToRemove) {
            emit fileRemoveSuccess(fileToRemove);
            files.erase(it);
            return true;
        }
    }
    emit fileRemoveFailureDoesntExist(fileToRemove);
    return false;
}

void FileStateTracker::updateAndDisplay()
{
    for(auto &i: files) {
        FILESTATEDELTA result = i.update();
        switch (result) {
        case FILESTATEDELTA::Created:
            emit fileCreated(i.fi);
        break;
        case FILESTATEDELTA::Deleted:
            emit fileDeleted(i.fi);
        break;
        case FILESTATEDELTA::Changed:
            emit fileChanged(i.fi);
        break;
        default:
        break;
        }
    }
}
