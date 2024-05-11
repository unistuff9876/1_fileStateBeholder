#ifndef FILEMONITORCOUT_H
#define FILEMONITORCOUT_H

#include <QObject>
#include <QFileInfo>

#include "filestatetracker.h"

class FileMonitorCout : public QObject
{
    Q_OBJECT

    explicit FileMonitorCout(FileStateTracker &fst);

public:
    static FileMonitorCout& instance(FileStateTracker &fst);

public slots:
    void fileAddSuccessExists(QFileInfo &fi);
    void fileAddSuccessDoesntExist(QFileInfo &fi);
    void fileAddFailureAlreadyTracked(QFileInfo &fi);
    void fileRemoveSuccess(QFileInfo &f);
    void fileRemoveFailureDoesntExist(QFileInfo &fi);
    void fileCreated(QFileInfo &fi);
    void fileDeleted(QFileInfo &fi);
    void fileChanged(QFileInfo &fi);
};

#endif // FILEMONITORCOUT_H
