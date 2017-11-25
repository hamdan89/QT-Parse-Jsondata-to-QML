#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<networkmanager.h>
#include <QQmlContext>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    NetworkManager manger;

     engine.rootContext()->setContextProperty("manager",&manger);

    return app.exec();
}
