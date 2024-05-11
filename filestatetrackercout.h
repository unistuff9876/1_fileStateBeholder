#ifndef FILESTATETRACKERCOUT_H
#define FILESTATETRACKERCOUT_H

#include <QObject>
#include <QFileInfo>

#include "filestatetracker.h"

class FileStateTrackerCout : public QObject
{
    Q_OBJECT

    explicit FileStateTrackerCout(FileStateTracker &fst);

public:
    static FileStateTrackerCout& instance(FileStateTracker &fst);

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

#endif // FILESTATETRACKERCOUT_H
