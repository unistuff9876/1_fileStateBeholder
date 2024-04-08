#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H

#include <QTextStream>

QTextStream& cout()
{
    static QTextStream out(stdout);
    out.flush();
    return out;
}

#endif // CONSOLEOUTPUT_H
