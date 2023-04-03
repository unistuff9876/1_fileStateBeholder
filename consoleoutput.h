#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H

#include <QTextStream>

QTextStream& cout()
{
    static QTextStream out(stdout);
    return out;
}

#endif // CONSOLEOUTPUT_H
