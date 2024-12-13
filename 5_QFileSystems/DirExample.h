#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>


class DirExample {

    inline void list(QDir& root) {
        qInfo() << "------ Listening ------";
        foreach(QFileInfo fi, root.entryInfoList(QDir::Filter::Dirs, QDir::Name)) {
            if(fi.isDir()) {
                qInfo() << fi.filePath();
            }
        }
    }

    inline void listAll(QDir& root) {
        qInfo() << "------ Listening ------";
        foreach(QFileInfo fi, root.entryInfoList(QDir::Filter::AllEntries | QDir::NoDotAndDotDot, QDir::Name)) {
            if(fi.isDir() | fi.isFile()) {
                qInfo() << fi.filePath();
                if(fi.isDir()) {
                    QDir child(fi.filePath());
                    qInfo() << "Inspecting: " << child.absolutePath();
                    list(child);
                }
            }
        }
    }
public:
    inline void run() {
        QDir dir(QCoreApplication::applicationDirPath());
        // qInfo() << dir.dirName();
        // qInfo() << dir.absolutePath();

        dir.cdUp();
        listAll(dir);
        // qInfo() << dir.absolutePath();
        // list(dir);

        // dir.mkdir("testDir");
        // list(dir);

        // dir.rmdir("testDir"); // if testDir is empty when rm works
        // list(dir);

        // dir.rmpath("testDir"); // It deletes everyting recursively
    }
};