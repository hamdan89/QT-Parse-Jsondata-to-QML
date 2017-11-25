#include "networkmanager.h"
#include "QNetworkAccessManager"
#include <QtNetwork>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>

NetworkManager::NetworkManager(QObject *parent) : QObject(parent)
{


}

QString NetworkManager ::loadWebPage(){
    // Now parse this JSON according to your needs !
   manager = new QNetworkAccessManager(this);

   manager->setNetworkAccessible(QNetworkAccessManager::Accessible);
    QNetworkRequest request;
   QEventLoop eventloop;

   QString apiKey ="demo";

   QString urlstring = QString ("https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=MSFT&interval=1min&apikey=%0").arg(apiKey);

   QUrl url(urlstring);

   request.setUrl(url);

   QNetworkReply *reply = manager->get(request);

   connect(reply, SIGNAL(finished()), &eventloop, SLOT(quit()));

   eventloop.exec();

    return replyFinished(reply);

}


QString NetworkManager :: replyFinished(QNetworkReply *reply){


  //QByteArray webData= reply->readAll();
 // QString webDataString = QString(webData);
  // qDebug()<<webDataString;

  // QStringList propertyNames;
   //QStringList propertyKeys;
   QString strReply = (QString)reply->readAll();
   QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

   QJsonObject jsonObject = jsonResponse.object();


   QJsonObject jsondataObject = jsonObject["Meta Data"].toObject();
   qDebug() << "some info" << jsondataObject["1. Information"].toString();

 //  QJsonObject jsontimeobject = jsonObject["Time Series (1min)"].toObject();
 //  QJsonObject jsondayobject = jsontimeobject["2017-11-24 10:33:00"].toObject();
  // qDebug() << "some info" << jsondayobject["1. open"].toString();


   //QByteArray webDatatwo = reply->readAll();

      QList<QPair<QString,QString>> graphValues;

       QPair<QString,QString> data;

      //QString webDataString = QString(webData);

      QJsonDocument documenttwo = QJsonDocument::fromJson(strReply.toUtf8());

      if(documenttwo.isArray() == true){
          //retreive the array
          QJsonArray rootArray = documenttwo.array();
      }

      else if(documenttwo.isObject() == true)
      {

          QJsonObject rootObject = documenttwo.object();

          QJsonObject timeSeries = rootObject["Time Series (1min)"].toObject();
          QStringList keys = timeSeries.keys();
          for (QString k : keys){
              QJsonObject dayValues = timeSeries[k].toObject();
              QString openValue =  dayValues["2. high"].toString();

              QPair<QString,QString> dataItem;
              dataItem.first = k;
              dataItem.second = openValue;

              graphValues.append(dataItem);
          }
      }



      //write data to file
      QString filename="D:\\Data.txt";
      QFile file( filename );
      if ( file.open(QIODevice::ReadWrite) )
      {
          for (int i=0; i<graphValues.size(); i++){
                  data = graphValues[i];
                  QTextStream stream( &file );
                  stream << data.first <<" - "<<data.second << "\r\n";
            //      qDebug()<<data.first <<" - "<<data.second;
              }

      }

      return strReply;
}
