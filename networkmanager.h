#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>

class NetworkManager : public QObject
{
    Q_OBJECT

    QNetworkAccessManager* manager;

public:
    explicit NetworkManager(QObject *parent = nullptr);

      Q_INVOKABLE  QString loadWebPage();

signals:

public slots:
    QString  replyFinished(QNetworkReply* reply);
};

#endif // NETWORKMANAGER_H
