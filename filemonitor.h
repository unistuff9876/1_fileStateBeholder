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
    QFileInfo fi;
    QDateTime lastModified_prev;
    bool exists_prev = 0;

public:
    FileState(QString path) {
        fi = QFileInfo(path);
        if(fi.exists(path)) {
            lastModified_prev = fi.lastModified();
            exists_prev = 1;
        }
    }
    FileState() {}
    QString getName() {
        return fi.fileName();
    }
    qint64 getSize() {
        return fi.size();
    }
    bool exists() {
        return fi.exists();
    }
    void updateAndDisplayState() {
        //refreshing file info so we dont read cached
        fi.refresh();
        qInfo() << getName() + ":";
        if (!exists()){
            if (exists_prev) {
                qInfo() << "was deleted" << "";
                exists_prev = 0;
            } else {
                qInfo() << "doesn't exist" << "";
            }
            return;
        }
        if (!exists_prev) {
            qInfo() << "was created";
            exists_prev = 1;
            lastModified_prev = fi.lastModified();
        } else
        if (fi.lastModified() != lastModified_prev) {
            qInfo() << "was changed!";
            lastModified_prev = fi.lastModified();
        }
        //this does not work via qInfo, much peculiar
        printf("%llu bytes\n", getSize());
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
    void updateAndDisplayFileInfo();
};

#endif // FILEMONITOR_H
