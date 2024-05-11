#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>
#include <QVector>
#include <QFileInfo>

#include "filestate.h"

class FileStateTracker : public QObject
{
    Q_OBJECT

    explicit FileStateTracker(QObject *parent = nullptr);

    QVector<FileState> files;

public:
    static FileStateTracker& instance() {
        static FileStateTracker s;
        return s;
    }

    bool addFile(QString path);
    bool removeFile(QString path);

    void updateAndDisplay();

signals:
    void fileAddSuccessExists(QFileInfo &fi);
    void fileAddSuccessDoesntExist(QFileInfo &fi);
    void fileAddFailureAlreadyTracked(QFileInfo &fi);
    void fileRemoveSuccess(QFileInfo &fi);
    void fileRemoveFailureDoesntExist(QFileInfo &fi);
    void fileCreated(QFileInfo &fi);
    void fileDeleted(QFileInfo &fi);
    void fileChanged(QFileInfo &fi);

};

#endif // FILEMONITOR_H
