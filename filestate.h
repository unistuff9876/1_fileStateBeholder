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
    bool exists_prev_ = 0;

public:
    FileState(QString path);
    FileState() {}
    QFileInfo& getQFileInfo();
    QString getName();
    qint64 getSize();
    bool exists();
    bool& exists_prev();
    QDateTime& lastModified_prev();
};

#endif // FILESTATE_H
