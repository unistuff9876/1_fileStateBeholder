#include <QDebug>

#include "filemonitorcout.h"
#include "filestate.h"

FileMonitorCout::FileMonitorCout(FileStateTracker &fst) {
    connect(&fst, FileStateTracker::fileAddSuccessExists, this, FileMonitorCout::fileAddSuccessExists);
    connect(&fst, FileStateTracker::fileAddSuccessDoesntExist, this, FileMonitorCout::fileAddSuccessDoesntExist);
    connect(&fst, FileStateTracker::fileAddFailureAlreadyTracked, this, FileMonitorCout::fileAddFailureAlreadyTracked);
    connect(&fst, FileStateTracker::fileRemoveSuccess, this, FileMonitorCout::fileRemoveSuccess);
    connect(&fst, FileStateTracker::fileRemoveFailureDoesntExist, this, FileMonitorCout::fileRemoveFailureDoesntExist);
    connect(&fst, FileStateTracker::fileCreated, this, FileMonitorCout::fileCreated);
    connect(&fst, FileStateTracker::fileDeleted, this, FileMonitorCout::fileDeleted);
    connect(&fst, FileStateTracker::fileChanged, this, FileMonitorCout::fileChanged);
}

FileMonitorCout &FileMonitorCout::instance(FileStateTracker &fst) {
    static FileMonitorCout s(fst);
    return s;
}

void FileMonitorCout::fileAddSuccessExists(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "был добавлен для отлеживания и существует, размер" << fi.size() << "байтов.";
}

void FileMonitorCout::fileAddSuccessDoesntExist(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "был добавлен для отлеживания и не существует.";
}

void FileMonitorCout::fileAddFailureAlreadyTracked(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "не был добавлен для отслеживания, т.к. уже отслеживается.";
}

void FileMonitorCout::fileRemoveSuccess(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "был снят с отслеживания.";
}

void FileMonitorCout::fileRemoveFailureDoesntExist(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "не был снят с отслеживания, т.к. не был отслеживаем.";
}

void FileMonitorCout::fileCreated(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "был создан. Размер" << fi.size() << "байтов.";
}

void FileMonitorCout::fileDeleted(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "был удален.";
}

void FileMonitorCout::fileChanged(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "был изменен. Размер" << fi.size() << "байтов.";
}
