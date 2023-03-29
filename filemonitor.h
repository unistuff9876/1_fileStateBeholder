#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>
#include <QVector>
#include <QTimer>
#include "filestate.h"

class FileMonitor : public QObject
{
    Q_OBJECT
public:
    explicit FileMonitor(QObject *parent = nullptr);

    bool addFile(QString path);
    bool delFile(QString path);

private:
    QTimer *timer;
    QVector<FileState> files;

signals:

public slots:
    void updateAndDisplayFileInfo();
};

#endif // FILEMONITOR_H
