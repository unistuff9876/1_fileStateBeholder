#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>
#include <QVector>
#include "filestate.h"
#include "filestatedelta.h"

class FileStateTracker : public QObject
{
    Q_OBJECT
public:
    static FileStateTracker& Instance() {
        static FileStateTracker s;
        return s;
    }

    bool addFile(QString path);
    bool delFile(QString path);

private:
    explicit FileStateTracker(QObject *parent = nullptr);

    QVector<FileState> files;

signals:

public slots:
    FileStateDelta updateFileState(FileState& fileState);

    void displayFileStateDelta(FileStateDelta stateDelta);

    void updateAndDisplayFileInfo();
};

#endif // FILEMONITOR_H
