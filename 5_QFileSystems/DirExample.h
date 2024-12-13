#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QStorageInfo>

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

    inline void list(QString path) {
        qInfo() << "List:" << path;

        QDir dir(path);
        QFileInfoList dirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
        QFileInfoList files = dir.entryInfoList(QDir::Files);

        foreach(QFileInfo fi, dirs) {
            qInfo() << fi.fileName();
        }

        foreach(QFileInfo fi, files) {
            qInfo() << '\n' << "..Name: " << fi.fileName();
            qInfo() << "...Size: " << fi.size();
            qInfo() << "...Created: " << fi.birthTime();
            qInfo() << "...Modified: " << fi.lastModified() << '\n';
        }

        foreach(QFileInfo fi, dirs) {
            list(fi.absoluteFilePath());
        }
    }

    inline void storageInfo() {
        QStorageInfo root { QStorageInfo::root() };
        qInfo() << "Root: " << root.rootPath();

        QDir dir(root.rootPath());
        
        foreach(QFileInfo fi, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
            qInfo() << fi.filePath();
        }

        qInfo() << "----------------------";

        foreach(QStorageInfo storage, QStorageInfo::mountedVolumes()) {
            qInfo() << "Name: " << storage.displayName();
            qInfo() << "Type: " << storage.fileSystemType();
            qInfo() << "Total: " << storage.bytesTotal()/1024/1024 << "MB";
            qInfo() << "Available: " << storage.bytesAvailable()/1024/1024 << "MB";
            qInfo() << "Device: " << storage.device();
            qInfo() << "Root: " << storage.isRoot();
            qInfo() << "\n";

        }
    }
public:
    inline void run() {
        QDir dir(QCoreApplication::applicationDirPath());
        // qInfo() << dir.dirName();
        // qInfo() << dir.absolutePath();

        dir.cdUp();
        // qInfo() << dir.absolutePath();
        // list(dir);

        // dir.mkdir("testDir");
        // list(dir);

        // dir.rmdir("testDir"); // if testDir is empty when rm works
        // list(dir);
        // dir.rmpath("testDir"); // It deletes everyting recursively
        
        //listAll(dir);
        //list(QDir::tempPath());
        storageInfo();
        qInfo() << "-- Done --";
    }
};