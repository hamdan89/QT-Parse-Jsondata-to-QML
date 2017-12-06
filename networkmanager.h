#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QNetworkAccessManager>
#include <QObject>
#include <QVariant>

class NetworkManager : public QObject
{
    Q_OBJECT

    QNetworkAccessManager* manager; //create a pointer
public:
    explicit NetworkManager(QObject *parent = nullptr);
    void loadWebPage();
signals:
    void valueUpdated(QVariant x, QVariant y);
    void valueUpdated2(QVariant x, QVariant y);
    void valueUpdated3(QVariant x, QVariant y);

public slots:
    void replyFinished(QNetworkReply *reply);

};

#endif
