#include "filestate.h"

FileState::FileState(QString path) {
    fi = QFileInfo(path);
    if(fi.exists(path)) {
        lastModified_prev_ = fi.lastModified();
        exists_prev_ = 1;
    }
}

QFileInfo FileState::getFi()
{
    return fi;
}

QString FileState::getName() {
    return fi.fileName();
}

qint64 FileState::getSize() {
    return fi.size();
}

bool FileState::exists() {
    return fi.exists();
}

QDateTime& FileState::lastModified_prev()
{
    return lastModified_prev_;
}

bool& FileState::exists_prev()
{
    return exists_prev_;
}
