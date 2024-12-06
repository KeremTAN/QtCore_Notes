#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QRandomGenerator>

void info(QSettings& settings) {
    qInfo() << "File:           " << settings.fileName();
    qInfo() << "Company Name:   " << settings.organizationName();
    qInfo() << "App Name:       " << settings.applicationName();
}

void saveSpecs(QSettings& settings, const QString& group, const QString& specName, QVariant&& specValue) {
    settings.beginGroup(group);
    settings.setValue(specName, specValue);
    settings.endGroup();
}

QVariant getSpecs(QSettings& settings, const QString& group, const QString& specName) {

    settings.beginGroup(group);

    if(!settings.contains(specName)) {
        qWarning() << "Does not contain " << specName << " in " << group;
        settings.endGroup();
        return 0;
    }

    QVariant ret { settings.value(specName) };

    settings.endGroup();
    return ret;

}

void navigateExample(QSettings& settings) {
    QStringList people{};
    QString group {"test"};
    people << "A" << "B" << "C" << "D" << "E";

    foreach (QString person, people) {
        int val = QRandomGenerator::global()->bounded(100);
        saveSpecs(settings, group, person, val);
    }
    settings.sync();
    info(settings);

    //Navigation
    foreach (QString group, settings.childGroups()) {
        settings.beginGroup(group);
        qInfo() << "Group: " << group;

        foreach (QString key, settings.childKeys()) {
            qInfo() << "... key: " << key << " = " << settings.value(key).toString();
        }

        settings.endGroup();
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("TACompany");
    QCoreApplication::setOrganizationDomain("tacompany.com");
    QCoreApplication::setApplicationName("SettingApp");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName()); // Default Os

    QString fileName = a.applicationDirPath() + "/settings.ini";
    QSettings settingSpecial(fileName, QSettings::Format::IniFormat);

    navigateExample(settingSpecial);

    return a.exec();
}
