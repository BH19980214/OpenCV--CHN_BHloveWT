#include "mymodbus.h"
#include <QModbusTcpClient>
#include <QDebug>
#include <QVariant>
#include <QThread>

QString IP;
int Port;
double angle_Pulse;
double OFFX;
extern int PLC_x;
extern int PLC_y;
extern int auto_num;
MyModbus::MyModbus(QObject *parent)
    : QObject{parent}
{
    modbusDevice = new QModbusTcpClient();
}

QList<quint16> q11(QString strValue);
//连接到设备
void MyModbus::connect_device()
{
    if (!modbusDevice)
        return;
    if (modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        //处于非连接状态，进行连接
        //TCP连接,端口502，地址192.168.0.1
        modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter, Port);
        modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter, IP);
        //连接超时设置，2000ms
        modbusDevice->setTimeout(2000);
        //连接失败重试连接，3次
        modbusDevice->setNumberOfRetries(3);
        //调试窗口显示连接状态
        if (modbusDevice->connectDevice())
        {
            qDebug()<< "Connected!";
        }
    }
    else
    {
        //处在连接状态进行断开连接的操作
        modbusDevice->disconnectDevice();
    }
}

void MyModbus::on_writeTor()
{
    QModbusDataUnit writeUnit(QModbusDataUnit::HoldingRegisters, 0, 3); // write 1 value in address 40003
    //QString offX = QString("%1").arg((int)OFFX, 4, 16, QLatin1Char('0'));
    //QString angle = QString("%1").arg((int)angle_Pulse, 4, 16, QLatin1Char('0'));
    writeUnit.setValue(0, q11("15000")[0]);
    writeUnit.setValue(1, q11("20000")[0]);
    writeUnit.setValue(2, q11("1")[0]);

    //这里先建好QModbusDataUnit

    if (auto *reply = modbusDevice->sendWriteRequest(writeUnit, 1))
    //发送写请求
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
            {
                if (reply->error() != QModbusDevice::NoError)
                        // error in reply

                    reply->deleteLater();
                });
        }
        else
        {
            if (reply->error() != QModbusDevice::NoError)
                // error in reply

            // broadcast replies return immediately
            reply->deleteLater();
        }
    }
    else
    {
        // error in request
    }
}

void MyModbus::on_writeTor1()
{
    QModbusDataUnit writeUnit(QModbusDataUnit::HoldingRegisters, 0, 3); // write 1 value in address 40003
    //QString offX = QString("%1").arg((int)OFFX, 4, 16, QLatin1Char('0'));
    //QString angle = QString("%1").arg((int)angle_Pulse, 4, 16, QLatin1Char('0'));
    writeUnit.setValue(0, q11("15000")[0]);
    writeUnit.setValue(1, q11("20000")[0]);
    writeUnit.setValue(2, q11("2")[0]);

    //这里先建好QModbusDataUnit

    if (auto *reply = modbusDevice->sendWriteRequest(writeUnit, 1))
    //发送写请求
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
            {
                if (reply->error() != QModbusDevice::NoError)
                        // error in reply

                    reply->deleteLater();
                });
        }
        else
        {
            if (reply->error() != QModbusDevice::NoError)
                // error in reply

            // broadcast replies return immediately
            reply->deleteLater();
        }
    }
    else
    {
        // error in request
    }
}


void MyModbus::readDevice()
{
    if (!modbusDevice)
    {
        return;
    }

    qDebug()<<"read device";

    QModbusDataUnit readUnit = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, 0, 3);

    if (auto *reply = modbusDevice->sendReadRequest(readUnit, 1))   //1->modbus设备地址
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, &MyModbus::toReadReady);
        }
        else
        {
            delete reply; // broadcast replies return immediately
        }
    }
    else
    {
        //emit statusBar(tr("Read error: ") + modbusDevice->errorString());
    }
     QThread::msleep(1);

}

void MyModbus::toReadReady()
{
//QModbusReply这个类存储了来自client的数据,sender()返回发送信号的对象的指针
    auto reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
    {
        return;
    }

    if (reply->error() == QModbusDevice::NoError)
    {
        //处理成功返回的数据
       const QModbusDataUnit unit = reply->result();
        //quint16 stat = unit.value(1);  //状态（位与关系）
        PLC_x = unit.value(0);
        PLC_y = unit.value(1);
        auto_num = unit.value(2);
       //qDebug()<<a;
    }
}

QList<quint16> q11(QString strValue)
{
    bool isOk;
    QList<quint16> dataList;
    quint16 dataValue = 0;
    qint32  int32Value = 0;
    float   floatValue = 0;
    floatValue = strValue.toFloat(&isOk);   // isOk可以用来判断 QString转成Float是否转换成功
     if(isOk)
     {
       int32Value = floatValue;                //Float 转换为 qint32
       dataValue = int32Value & 0x0000FFFF;   //取低16位
       dataList << dataValue;
       dataValue = int32Value << 16;        //右移16位， 取高16位的数据
       dataList << dataValue;
    }
    return dataList ;

}

