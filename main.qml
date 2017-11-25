import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Button {
        id: pressbutton
        x: 59
        y: 47
        text: qsTr("Press Here")
        spacing: -1


        onPressed: {


           textarea.append(manager.loadWebPage());

       }
    }

    TextArea {
        id: textarea
        x: 33
        y: 122
        width: 164
        height: 154
        text: qsTr("Text Area")


    }

}
