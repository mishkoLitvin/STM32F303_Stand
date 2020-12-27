import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

import App.Controller 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    menuBar: MenuBar {
            Menu {
                title: qsTr("&File")
                Action{
                    id: portList; text: "  "
                }
            }
    }

}
