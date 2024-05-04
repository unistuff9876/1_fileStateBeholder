#include "filestate.h"
#include "filestatedelta.h"

FileState::FileState(QString path) {
    QFileInfo fi(path);
    if(fi.exists(path)) {
        lastModified_prev_ = fi.lastModified();
        exists_prev_ = true;
    }
}

QFileInfo& FileState::QFileInfo()
{
    return fi;
}

QString FileState::name() {
    return fi.fileName();
}

QString FileState::fullPath() {
    return fi.absolutePath();
}

qint64 FileState::size() {
    return fi.size();
}

bool FileState::exists() {
    return fi.exists();
}

FILESTATEDELTA FileState::update()
{
    if (exists()) {
        //got created
        if (!exists_prev()) {
            exists_prev_ = true;
            lastModified_prev_
                = fi.lastModified();

            return FILESTATEDELTA::Created;
        }
        else
        //exists and existed - we check for change
        if (fi.lastModified() != lastModified_prev_) {
            lastModified_prev_ = fi.lastModified();
            return FILESTATEDELTA::Changed;
        }
    }
    else
    //got deleted
    if (exists_prev()) {
        exists_prev_ = true;
        lastModified_prev_
            = fi.lastModified();

        return FILESTATEDELTA::Created;
    }

    //exists and existed without change
    //OR didnt exist and hasnt existed - no change
    return FILESTATEDELTA::NoChange;
}

bool& FileState::exists_prev()
{
    return exists_prev_;
}
