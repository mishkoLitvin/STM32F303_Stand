#include "appcontroller.h"

#include <QDebug>

AppController::AppController(QObject *parent) : QObject(parent)
{
    m_serialPort = new QSerialPort(this);

    connect(m_serialPort, &QSerialPort::readyRead, this, &AppController::onSerialReadyRead);

    this->rescanPorts();
}

AppController::~AppController()
{
    if(m_serialPort->isOpen())
        m_serialPort->close();
    qDebug()<<"AppController::~AppController"<<m_serialPort->isOpen();
}

void AppController::rescanPorts()
{
    m_serialPortList.clear();
    m_ports.clear();
    m_ports = QSerialPortInfo::availablePorts();
    for(auto& port: m_ports){
        m_serialPortList.append(port.portName()+"::"+port.description());
    }

    emit serialPortListChanged();
}

void AppController::connectPort(int index)
{
    m_serialPort->setPort(m_ports.at(index));
    m_serialPort->setBaudRate(QSerialPort::Baud115200);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
    m_serialPort->setParity(QSerialPort::NoParity);

    if(m_serialPort->isOpen())
        m_serialPort->close();

    qDebug()<<"AppController::connectPort"<<index<<m_ports.at(index).portName()<<m_serialPort->open(QIODevice::ReadWrite);
}

void AppController::onSerialReadyRead(){
    if(!m_serialPort->isOpen() ||
            !m_serialPort->isReadable())
        return;

    qDebug()<<m_serialPort->readAll();
}

