import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

import App.Controller 1.0

import "qml"

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    AppController{
        id: mainController
    }

    menuBar: MainMenu {}

    GridLayout{
        anchors.fill: parent
        rows: 2
        columns: 2
        Dial{
            id: amplitudeValue
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.margins: 10
            from: 0
            to: 4000
            stepSize: 10
            snapMode: Dial.SnapAlways
            wheelEnabled: true
            onValueChanged: mainController.waveAmplitude = value;

            Text {
                anchors.fill: parent
                anchors.bottomMargin: amplitudeValue.height/5
                horizontalAlignment: Qt.AlignHCenter; verticalAlignment: Qt.AlignBottom
                text: Math.round(amplitudeValue.value)
                font.pointSize: 16
            }
        }

        Dial{
            id: frequencyValue
            Layout.fillHeight: true
            Layout.fillWidth: true
            from: 0
            to: 4000
            stepSize: 10
            snapMode: Dial.SnapAlways
            Text {
                text: qsTr("frequencyValue")
            }

        }


    }

}
