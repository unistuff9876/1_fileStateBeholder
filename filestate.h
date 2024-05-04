#ifndef FILESTATE_H
#define FILESTATE_H

#include "filestatedelta.h"

#include <QDateTime>
#include <QVector>

class FileState
{
private:
    QFileInfo fi;
    QDateTime lastModified_prev_;
    bool exists_prev_ = false;

public:
    FileState(QString path);
    FileState() {}
    QFileInfo& QFileInfo();
    QString name();
    QString fullPath();
    qint64 size();
    bool exists();
    bool& exists_prev();
    QDateTime& lastModified_prev();

    FILESTATEDELTA update();

    friend class FileStateTracker;
};

#endif // FILESTATE_H
