#ifndef QSTDOUT_H
#define QSTDOUT_H

#include <QTextStream>

//this gets called but just doesn't work

QTextStream& cout()
{
    static QTextStream out(stdout);
    return out;
}

#endif // QSTDOUT_H
