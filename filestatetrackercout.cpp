#include <QDebug>

#include "filestatetrackercout.h"
#include "filestate.h"

FileStateTrackerCout::FileStateTrackerCout(FileStateTracker &fst) {
    connect(&fst, FileStateTracker::fileAddSuccessExists, this, FileStateTrackerCout::fileAddSuccessExists);
    connect(&fst, FileStateTracker::fileAddSuccessDoesntExist, this, FileStateTrackerCout::fileAddSuccessDoesntExist);
    connect(&fst, FileStateTracker::fileAddFailureAlreadyTracked, this, FileStateTrackerCout::fileAddFailureAlreadyTracked);
    connect(&fst, FileStateTracker::fileRemoveSuccess, this, FileStateTrackerCout::fileRemoveSuccess);
    connect(&fst, FileStateTracker::fileRemoveFailureDoesntExist, this, FileStateTrackerCout::fileRemoveFailureDoesntExist);
    connect(&fst, FileStateTracker::fileCreated, this, FileStateTrackerCout::fileCreated);
    connect(&fst, FileStateTracker::fileDeleted, this, FileStateTrackerCout::fileDeleted);
    connect(&fst, FileStateTracker::fileChanged, this, FileStateTrackerCout::fileChanged);
}

FileStateTrackerCout &FileStateTrackerCout::instance(FileStateTracker &fst) {
    static FileStateTrackerCout s(fst);
    return s;
}

void FileStateTrackerCout::fileAddSuccessExists(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "был добавлен для отлеживания и существует, размер" << fi.size() << "байтов.";
}

void FileStateTrackerCout::fileAddSuccessDoesntExist(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "был добавлен для отлеживания и не существует.";
}

void FileStateTrackerCout::fileAddFailureAlreadyTracked(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "не был добавлен для отслеживания, т.к. уже отслеживается.";
}

void FileStateTrackerCout::fileRemoveSuccess(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "был снят с отслеживания.";
}

void FileStateTrackerCout::fileRemoveFailureDoesntExist(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "не был снят с отслеживания, т.к. не был отслеживаем.";
}

void FileStateTrackerCout::fileCreated(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "был создан. Размер" << fi.size() << "байтов.";
}

void FileStateTrackerCout::fileDeleted(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "был удален.";
}

void FileStateTrackerCout::fileChanged(QFileInfo &fi)
{
    qInfo() << fi.absoluteFilePath() << "был изменен. Размер" << fi.size() << "байтов.";
}
