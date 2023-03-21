#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>
#include <QVector>
#include <QFileInfo>
#include <QDateTime>

class FileState
{
private:
    QFileInfo *fi = nullptr;
    QDateTime lastModified_prev;

public:
    //no need for copy or default contstructors here
    FileState(QString path) {
        fi = new QFileInfo(path);
        if(fi->exists(path)) {
            lastModified_prev = fi->metadataChangeTime();
        }
    }
    FileState() {}
    QString getName() {
        if (fi == nullptr) {
            return "";
        }
        return fi->fileName();
    }
    qint64 getSize() {
        if (fi == nullptr) {
            return 0;
        }
        return fi->size();
    }
    bool exists() {
        if (fi == nullptr) {
            return 0;
        }
        return fi->exists();
    }
};


class FileMonitor : public QObject
{
    Q_OBJECT
public:
    explicit FileMonitor(QObject *parent = nullptr);

    bool addFile(QString path);
    bool delFile(QString path);

private:
    QVector<FileState> objects;

signals:

public slots:
};

#endif // FILEMONITOR_H
