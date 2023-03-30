#ifndef FILESTATE_H
#define FILESTATE_H

#include <QFileInfo>
#include <QDateTime>

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
    void updateState();
    void updateAndDisplayState();

private:
    void displayState();
};

#endif // FILESTATE_H
