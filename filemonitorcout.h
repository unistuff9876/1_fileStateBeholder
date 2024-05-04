#ifndef FILEMONITORCOUT_H
#define FILEMONITORCOUT_H

#include <QObject>

#include "filemonitor.h"

class FileMonitorCout
{
    Q_OBJECT

    explicit FileMonitorCout(FileStateTracker &fst);

public:
    static FileMonitorCout& instance(FileStateTracker &fst);

public slots:
    void fileAddSuccess(QFileInfo &fi);
    void fileAddFailureAlreadyExists(QFileInfo &fi);
    void fileRemoveSuccess(QFileInfo &f);
    void fileRemoveFailureDoesntExist(QFileInfo &fi);
    void fileCreated(FileState &f);
    void fileDeleted(FileState &f);
    void fileChanged(FileState &f);
};

#endif // FILEMONITORCOUT_H
