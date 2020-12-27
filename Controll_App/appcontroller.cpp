#include "appcontroller.h"

#include <QtSerialPort/QSerialPortInfo>

AppController::AppController(QObject *parent) : QObject(parent)
{
    m_serialPort = new QSerialPort(this);

    this->rescanPorts();
}

void AppController::rescanPorts()
{
    m_serialPortList.clear();
    QList<QSerialPortInfo> port_list = QSerialPortInfo::availablePorts();
    for(auto& port: port_list){
        m_serialPortList.append(port.portName()+"::"+port.description());
    }

    emit serialPortListChanged();
}
