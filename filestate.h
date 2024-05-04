#ifndef FILESTATE_H
#define FILESTATE_H

#include <QFileInfo>
#include <QDateTime>
#include <QVector>

class FileState
{
private:
    QFileInfo fi;
    QDateTime lastModified_prev_;
    bool exists_prev_ = false;

public:
    FileState(QString path);
    FileState() {}
    QFileInfo& getQFileInfo();
    QString getName();
    QString getPath();
    qint64 getSize();
    bool exists();
    bool& exists_prev();
    QDateTime& lastModified_prev();

    friend class FileStateTracker;
};

#endif // FILESTATE_H
