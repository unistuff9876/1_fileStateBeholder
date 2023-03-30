#ifndef FILESTATE_H
#define FILESTATE_H

#include <QFileInfo>
#include <QDateTime>
#include <QVector>

class FileState
{
private:
    QFileInfo fi;
    QDateTime lastModified_prev;
    bool exists_prev = 0;

public:
    FileState(QString path);
    FileState() {}
    QFileInfo getFi();
    QString getName();
    qint64 getSize();
    bool exists();

    friend class FileMonitor;
};

#endif // FILESTATE_H
