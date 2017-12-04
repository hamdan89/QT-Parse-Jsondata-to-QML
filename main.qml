import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.2

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
            thechart.visible = false;

       }
    }

    TextArea {
        id: textarea
        x: 33
        y: 122
        width: 538
        height: 268
        text: qsTr("Text Area")


    }

    Button {
        id: btnchart
        x: 417
        y: 47
        text: qsTr("Show Chart")

        onPressed: {

             thechart.visible = true;
        }
    }

    ChartView{

        id: thechart
        x: 40
        y: 122
        width: 538
        height: 268
        clip: false
        visible: false

    }

}
