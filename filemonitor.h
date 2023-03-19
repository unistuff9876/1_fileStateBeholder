#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>

class FileState{

public:
FileState(QString path);

private:
QString name;
qint64 size;
bool exists;

};


class FileMonitor : public QObject
{
    Q_OBJECT
public:
    explicit FileMonitor(QObject *parent = nullptr);

    bool addFile(QString path);
    bool delFile(QString path);

signals:

public slots:
};

#endif // FILEMONITOR_H
