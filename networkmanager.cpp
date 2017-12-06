#include "networkmanager.h"
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>

NetworkManager::NetworkManager(QObject *parent) : QObject(parent)
{

    manager= new QNetworkAccessManager();
    connect(manager,SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}


void NetworkManager::loadWebPage(){
    QNetworkRequest request;

    QString apikey = "demo";

    QString urlString = QString("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=MSFT&apikey=%0").arg(apikey);

    QUrl url(urlString);
    request.setUrl(url);

    QNetworkReply *reply = manager->get(request);
}


void NetworkManager::replyFinished(QNetworkReply *reply)
{
    QByteArray webData = reply->readAll();


    QList<QPair<QString,QString>> graphValuesopen;
    QList<QPair<QString,QString>> graphValueshigh;
    QList<QPair<QString,QString>> graphValuesvolume;

    QJsonDocument doc = QJsonDocument::fromJson(webData);

    if(doc.isArray()==true){
        QJsonArray rootArray = doc.array();
    }

    else if (doc.isObject() == true){

        QJsonObject rootObject = doc.object();

        QJsonObject timeSeries = rootObject["Time Series (Daily)"].toObject();
        QStringList keys = timeSeries.keys();

        for (QString k :keys){
            QJsonObject dayValues = timeSeries[k].toObject();
            QString openValue = dayValues["1. open"].toString();
            QString highValue = dayValues["2. high"].toString();
            QString volumeValue = dayValues["5. volume"].toString();

            QPair<QString,QString> dataItem;
            QPair<QString,QString> dataItem2;
            QPair<QString,QString> dataItem3;

            dataItem.first = k;
            dataItem.second = openValue;

            dataItem2.first = k;
            dataItem2.second = highValue;

            dataItem3.first = k;
            dataItem3.second = volumeValue;



            graphValuesopen.append(dataItem);
            graphValueshigh.append(dataItem2);
            graphValuesvolume.append(dataItem3);

            }

    }
    for (int i=0; i<graphValuesopen.size(); i++){
        QPair<QString,QString> data = graphValuesopen[i];
        float list=data.second.toFloat();
        emit valueUpdated(QVariant(i),QVariant(list));
        qDebug()<<data.second;
    }

    for (int i=0; i<graphValueshigh.size(); i++){
        QPair<QString,QString> data = graphValueshigh[i];
        float list=data.second.toFloat();
        emit valueUpdated2(QVariant(i),QVariant(list));
    }

    for (int i=0; i<graphValuesvolume.size(); i++){
        QPair<QString,QString> data = graphValuesvolume[i];
        float list=data.second.toFloat();
        emit valueUpdated3(QVariant(i),QVariant(list));
    }


}

