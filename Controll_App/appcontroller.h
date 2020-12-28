#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <QVariantList>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class AppController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantList serialPortList READ serialPortList NOTIFY serialPortListChanged)

public:
    explicit AppController(QObject *parent = nullptr);
    ~AppController();

    QVariantList serialPortList() const {return m_serialPortList;};
public slots:
    Q_INVOKABLE void rescanPorts();
    Q_INVOKABLE void connectPort(int index);

signals:
    void serialPortListChanged();

private slots:
    void onSerialReadyRead();

private:

    QSerialPort *m_serialPort;
    QList<QSerialPortInfo> m_ports;
    QVariantList m_serialPortList;

};

#endif // APPCONTROLLER_H
