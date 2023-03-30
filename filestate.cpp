#include "filestate.h"
#include "qstdout.h"

FileState::FileState(QString path) {
    fi = QFileInfo(path);
    if(fi.exists(path)) {
        lastModified_prev = fi.lastModified();
        exists_prev = 1;
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
