#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <QVariantList>
#include <QtSerialPort/QSerialPort>

class AppController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantList serialPortList READ serialPortList NOTIFY serialPortListChanged)

public:
    explicit AppController(QObject *parent = nullptr);

    QVariantList serialPortList() const {return m_serialPortList;};
public slots:
    Q_INVOKABLE void rescanPorts();

signals:
    void serialPortListChanged();

private:

    QSerialPort *m_serialPort;
    QVariantList m_serialPortList;

};

#endif // APPCONTROLLER_H
