#ifndef FILESTATEDELTA_H
#define FILESTATEDELTA_H

enum FileStateDelta_State {
    Exists = 0,
    DoesntExist,
    Created,
    Deleted,
    Modified
};

struct FileStateDelta {

    FileStateDelta_State state;

    QString name;
    qint64 size;
};

#endif // FILESTATEDELTA_H
