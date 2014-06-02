#ifndef CITYMANAGER_H
#define CITYMANAGER_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QMutex>
#include <QWaitCondition>
#include <functional>

class QNetworkAccessManager;
class QNetworkReply;

typedef std::function<void (const QStringList &strList)> OnMessage;

class CityManager : public QObject
{
    Q_OBJECT

public:
    CityManager();

    void getSupportProvince(const OnMessage &msg);
    void getSupportCity(const QString &provinceName, const OnMessage &msg);
    void getWeatherbyCityName(const QString &cityName, const OnMessage &msg);

private slots:
    void replyFinished(QNetworkReply *);

private:
    QNetworkAccessManager *net_;
    OnMessage onMessage_;
};

#endif // CITYMANAGER_H
