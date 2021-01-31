#ifndef MERE_UTILS_SIGNALUTILS_H
#define MERE_UTILS_SIGNALUTILS_H

#include "global.h"

#include <signal.h>
#include <unistd.h>
#include <sys/socket.h>

#include <QObject>
#include <QSocketNotifier>

namespace Mere
{

namespace Utils
{

static int g_fd[2];

class MERE_UTILS_LIBSPEC SignalUtils : public QObject
{
    Q_OBJECT
public:
    explicit SignalUtils(QObject *parent = nullptr);
    int watch(int signal);
    int ignore(int signal);

private:
    static int setupSignal(int signal);
    static void signalHandler(int signal);
    static void signalHandler(int signal, siginfo_t *si, void *ucontext);

    void watchSIGHUP();
    void watchSIGQUIT();
    void watchSIGTERM();

signals:
    void fired(int);
//    void fired(siginfo_t);

public slots:

private slots:
    void handleSignal();

private:
    QSocketNotifier *socketNotifier;
};

}
}
#endif // MERE_UTILS_SIGNALUTILS_H
