#include "filestate.h"
#include "filestatedelta.h"
#include <QDebug>

FileState::FileState(QFileInfo fi) {
    this->fi = fi;
    if(fi.exists()) {
        lastModified_prev = fi.lastModified();
        exists_prev = true;
    }
    else {
        exists_prev = false;
    }
}

FILESTATEDELTA FileState::update()
{
    fi.refresh();

    if (fi.exists()) {
        //got created
        if (!exists_prev) {
            exists_prev = true;
            lastModified_prev
                = fi.lastModified();

            return FILESTATEDELTA::Created;
        }
        else
        //exists and existed - we check for change
        if (fi.lastModified() != lastModified_prev) {
            lastModified_prev = fi.lastModified();
            return FILESTATEDELTA::Changed;
        }
    }
    else
    //got deleted
    if (exists_prev) {
        exists_prev = false;
        lastModified_prev
            = fi.lastModified();

        return FILESTATEDELTA::Deleted;
    }

    //exists and existed without change
    //OR didnt exist and hasnt existed - no change
    return FILESTATEDELTA::NoChange;
}
