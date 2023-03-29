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

void FileState::updateState() {
    //this REFUSES to work as static,
    //or via the qstdout function
    //workaround for now
    QTextStream cout(stdout);
    //refreshing file info so we dont read cached
    fi.refresh();
    cout << getName() << ":\n";
    if (!exists()) {
        if (exists_prev) {
            cout << "was deleted\n";
            exists_prev = 0;
        } else {
            cout << "doesn't exist\n";
        }
        return;
    }
    if (!exists_prev) {
        cout << "was created\n";
        exists_prev = 1;
        lastModified_prev = fi.lastModified();
    } else
    if (fi.lastModified() != lastModified_prev) {
        cout << "was changed!\n";
        lastModified_prev = fi.lastModified();
    }
    cout << getSize() << " bytes\n";
}
