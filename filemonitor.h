#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>
#include <QVector>
#include <QTimer>
#include "filestate.h"
#include "filestatedelta.h"

class FileMonitor : public QObject
{
    Q_OBJECT
public:
    //explicit FileMonitor(QObject *parent = nullptr);
    static FileMonitor& Instance() {
        static FileMonitor s;
        return s;
    }

    bool addFile(QString path);
    bool delFile(QString path);

private:
    explicit FileMonitor(QObject *parent = nullptr);

    QTimer *timer;
    QVector<FileState> files;

    FileStateDelta updateFileState(FileState& fileState);

    void displayFileStateDelta(FileStateDelta stateDelta);

signals:

public slots:
    void updateAndDisplayFileInfo();
};

#endif // FILEMONITOR_H
