#include "filestate.h"
#include "filestatedelta.h"

FileState::FileState(QString path) {
    fi = QFileInfo(path);
    if(fi.exists(path)) {
        lastModified_prev_ = fi.lastModified();
        exists_prev_ = true;
    }
}

QFileInfo& FileState::getQFileInfo()
{
    return fi;
}

QString FileState::getName() {
    return fi.fileName();
}

QString FileState::getFullPath() {
    return fi.absolutePath();
}

qint64 FileState::getSize() {
    return fi.size();
}

bool FileState::exists() {
    return fi.exists();
}

FILESTATEDELTA FileState::update()
{
    if (exists()) {
        if (!exists_prev()) {
            exists_prev_ = true;
            lastModified_prev_
                = fi.lastModified();

            return FILESTATEDELTA.Created;
        }
        else
        if
    }
    else
    if (exists_prev()) {
        exists_prev_ = true;
        lastModified_prev_
            = fi.lastModified();

        return FILESTATEDELTA.Created;
    }
}

bool& FileState::exists_prev()
{
    return exists_prev_;
}
