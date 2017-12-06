import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtCharts 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    id: window

    Connections {
        target: Manager
        onValueUpdated: {
            series.append(x, y)
            if (x > xAxis.max) {
                xAxis.max = x
            }
            if (y > yAxis.max) {
                yAxis.max = y
            }
        }

        onValueUpdated2: {
            series2.append(x, y)
            if (x > xAxis2.max) {
                xAxis2.max = x
            }
            if (y > yAxis2.max) {
                yAxis2.max = y
            }
        }

        onValueUpdated3: {
            y = y/1000000
            series3.append(x, y)
            if (x > xAxis3.max) {
                xAxis3.max = x
            }
            if (y > yAxis3.max) {
                yAxis3.max = y
            }
        }
    }

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent
        anchors.topMargin: 100
        visible: false

        RowLayout {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 10
            Text {
                id: text1
                color: "#e91e1e"
                text: qsTr("Open Values")
                z: 1
                font.italic: true
                font.pointSize: 20
            }
        }
    }

    ChartView {
        id: chartView
        title: "Open Values chart"
        anchors.fill: parent
        anchors.topMargin: 100
        theme: ChartView.ChartThemeLight
        visible: false
        ValueAxis {
            id: yAxis
            titleText: "y"
            titleVisible: true
            gridVisible: true
            tickCount: 11
            min: 0
            max: 87
        }

        ValueAxis{
            id: xAxis
            min: 0
            max: 100
        }

        LineSeries {
            id: series
            axisX: xAxis
            axisY: yAxis
            name: "Open values series"
            visible: true
        }

    }

    ColumnLayout {
        id: columnLayout2
        anchors.fill: parent
        anchors.topMargin: 100
        visible: false

        RowLayout {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 10
            Text {
                id: text2
                color: "#e91e1e"
                text: qsTr("High Values")
                z: 1
                font.italic: true
                font.pointSize: 20
            }
        }
    }

    ChartView {
        id: chartView2
        title: "high Values chart"
        anchors.fill: parent
        anchors.topMargin: 100
        theme: ChartView.ChartThemeLight
        visible: false
        ValueAxis {
            id: yAxis2
            titleText: "y"
            titleVisible: true
            gridVisible: true
            tickCount: 11
            min: 0
            max: 87
        }

        ValueAxis{
            id: xAxis2
            min: 0
            max: 100
        }

        LineSeries {
            id: series2
            axisX: xAxis2
            axisY: yAxis2
            name: "high values series"
            visible: true
        }

    }

    ColumnLayout {
        id: columnLayout3
        anchors.fill: parent
        anchors.topMargin: 100
        visible: false

        RowLayout {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 10
            Text {
                id: text3
                color: "#e91e1e"
                text: qsTr("High Values")
                z: 1
                font.italic: true
                font.pointSize: 20
            }
        }
    }

    ChartView {
        id: chartView3
        title: "volume Values chart"
        anchors.fill: parent
        anchors.topMargin: 100
        theme: ChartView.ChartThemeLight
        visible: false
        ValueAxis {
            id: yAxis3
            titleText: "y"
            titleVisible: true
            gridVisible: true
            tickCount: 11
            min: 0
            max: 87
        }

        ValueAxis{
            id: xAxis3
            min: 0
            max: 100
        }

        LineSeries {
            id: series3
            axisX: xAxis3
            axisY: yAxis3
            name: "Volume values series"
            visible: true
        }

    }

    Button {
        id: button
        x: 61
        y: 27
        text: qsTr("show open values")

        onClicked: {
            chartView.visible = true
            columnLayout.visible = true
            chartView2.visible = false
            columnLayout2.visible = false
            chartView3.visible = false
            columnLayout3.visible = false
        }
    }

    Button {
        id: button1
        x: 263
        y: 27
        text: qsTr("show high values")

        onClicked: {
            chartView.visible = false
            columnLayout.visible = false
            chartView2.visible = true
            columnLayout2.visible = true
            chartView3.visible = false
            columnLayout3.visible = false
        }
    }

    Button {
        id: button2
        x: 461
        y: 27
        text: qsTr("Show volume values")

        onClicked: {
            chartView.visible = false
            columnLayout.visible = false
            chartView2.visible = false
            columnLayout2.visible = false
            chartView3.visible = true
            columnLayout3.visible = true
        }
    }
}
