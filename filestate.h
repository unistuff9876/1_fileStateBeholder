#ifndef FILESTATE_H
#define FILESTATE_H

#include <QFileInfo>
#include <QDateTime>
#include <QVector>

#include "filestatedelta.h"

class FileState
{
private:
    QFileInfo fi;
    QDateTime lastModified_prev;
    bool exists_prev;

public:
    FileState(QFileInfo fileToAdd);
    FileState() {}

    FILESTATEDELTA update();

    friend class FileStateTracker;
    friend class FileMonitorCout;
};

#endif // FILESTATE_H
