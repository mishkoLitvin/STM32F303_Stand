import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

import App.Controller 1.0

MenuBar {
    Menu {
        title: qsTr("&File")
        Menu {
            title: qsTr("Avariable ports:")
            enabled: mainController.serialPortList.length
            Repeater{
                model: mainController.serialPortList
                ToolButton{
                    text: mainController.serialPortList[index]
                    onClicked: mainController.connectPort(index)
                }
            }
        }
    }
}
