#ifndef FILESTATEDELTA_H
#define FILESTATEDELTA_H

//id have put this inside
//the struct if qt let me

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
