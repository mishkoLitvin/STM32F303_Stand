#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <QVariantList>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include "protocol.h"

class AppController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantList serialPortList READ serialPortList NOTIFY serialPortListChanged)
    Q_PROPERTY(int waveAmplitude READ waveAmplitude WRITE setWaveAmplitude NOTIFY waveAmplitudeChanged)
    Q_PROPERTY(int waveFrequency READ waveFrequency WRITE setWaveFrequency NOTIFY waveFrequencyChanged)
    Q_PROPERTY(int waveType READ waveType WRITE setWaveType NOTIFY waveTypeChanged)


public:
    explicit AppController(QObject *parent = nullptr);
    ~AppController();

    QVariantList serialPortList() const {return m_serialPortList;};
public slots:
    Q_INVOKABLE void rescanPorts();
    Q_INVOKABLE void connectPort(int index);

    int waveAmplitude() {return m_controlData.bits.amplitude;};
    int waveFrequency() {return m_controlData.bits.frequency;};
    int waveType() {return m_controlData.bits.wave_type;};

    void setWaveAmplitude(int value);
    void setWaveFrequency(int value);
    void setWaveType(int value);

signals:
    void serialPortListChanged();
    void waveAmplitudeChanged();
    void waveFrequencyChanged();
    void waveTypeChanged();

private slots:
    void onSerialReadyRead();

private:

    QSerialPort *m_serialPort;
    QList<QSerialPortInfo> m_ports;
    QVariantList m_serialPortList;

    OutData m_controlData;

};

#endif // APPCONTROLLER_H
