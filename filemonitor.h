#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QFileInfo>
#include <QObject>
#include <QVector>

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

signals:
    void fileAddSuccess(QFileInfo &fi);
    void fileAddFailureAlreadyExists(QFileInfo &fi);
    void fileRemoveSuccess(QFileInfo &fi);
    void fileRemoveFailureDoesntExist(QFileInfo &fi);
    void fileCreated(FileState &f);
    void fileDeleted(FileState &f);
    void fileChanged(FileState &f);

public slots:
    void updateAndDisplay();
};

#endif // FILEMONITOR_H
