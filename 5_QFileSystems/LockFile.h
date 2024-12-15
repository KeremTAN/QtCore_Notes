#ifndef LOCKFILE_H
#define LOCKFILE_H
#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QLockFile> // locks a file between processes

class LockFile {
public:
    void run() {
        qInfo() << "Attempting to lock a file...";
        QString path { QDir::currentPath() + QDir::separator() + "text.txt" };
       
        QFile file(path);
        QLockFile lock(file.fileName() + "l");
         qInfo() << "Lock Path: " << lock.fileName();
        lock.setStaleLockTime(1500); // lock for 15s

        if(lock.tryLock()) {
            qInfo() << "Putting into files...";
            if(file.open(QIODevice::WriteOnly)) {
                QByteArray data;
                data.append("Hii!");
                file.write(data);
                file.close();
                qInfo() << "Finished with file...";
            }
            // qInfo() << "Unlocking file";
            // lock.unlock();
        }
        else {
            qInfo() << "Could not lock the file!";
            qint64 pid{};
            QString host{};
            QString app{};

            if(lock.getLockInfo(&pid, &host, &app)) {
                qInfo() << "The file is locked by:";
                qInfo() << "Pid:    " << pid;
                qInfo() << "Host:   " << host;
                qInfo() << "App:    " << app;
            }
            else {
                qInfo() << "File is locked, but we can not get the info.";
            }
        }
    }

};

#endif // LOCKFILE_H
