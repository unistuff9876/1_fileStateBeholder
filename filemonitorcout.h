#ifndef FILEMONITORCOUT_H
#define FILEMONITORCOUT_H

#include <QObject>

#include <iostream>

#include "filemonitor.h"

class FileMonitorCout
{
    Q_OBJECT

    explicit FileMonitorCout(FileStateTracker &fst) {
        connect();
    }

public:
    static FileMonitorCout& instance(FileStateTracker &fst) {
        static FileMonitorCout s;
        return s;
    }

public slots:
    void fileAddSuccess(FileState &f);
    void fileAddFailureAlreadyExists(FileState &f);
    void fileRemoveSuccess(FileState &f);
    void fileRemoveFailureDoesntExist(FileState &f);
    void fileCreated(FileState &f);
    void fileDeleted(FileState &f);
    void fileChanged(FileState &f);
};

#endif // FILEMONITORCOUT_H
