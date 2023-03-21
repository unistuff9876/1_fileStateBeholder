#ifndef FILEMONITOR_H
#define FILEMONITOR_H

//i wanna put these in main before this header
//gets included but i cant get it to work
#include <QObject>
#include <QVector>
#include <QFileInfo>
#include <QDateTime>
#include <QTimer>
#include <QDebug>

class FileState
{
private:
    QFileInfo *fi = nullptr;
    QDateTime lastModified_prev;

public:
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
    void updateAndDisplayState() {
        if (!exists()){
            qInfo() << getName() + " doesn't exist";
            return;
        }
        qInfo() << getName()
                << "size: " + getSize();

        if (fi->metadataChangeTime() != lastModified_prev) {
            qInfo() << "file was changed!";
        }
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
    QTimer *timer;
    QVector<FileState> files;

signals:

public slots:
    void checkOnFiles();
};

#endif // FILEMONITOR_H
