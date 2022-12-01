#ifndef MYMODBUS_H
#define MYMODBUS_H

#include <QObject>
#include <QModbusDataUnit> //存储接收和发送数据的类，数据类型为1bit和16bit

#include <QModbusReply> //客户端访问服务器后得到的回复（如客户端读服务器数据时包含数据信息）
class QModbusClient;
class QModbusReply;

class MyModbus : public QObject
{
    Q_OBJECT
public:
    explicit MyModbus(QObject *parent = nullptr);
    QModbusClient *modbusDevice = nullptr;
    void connect_device();
    void readDevice();
    void toReadReady();
    void on_writeTor();
    //测试 后续删
    void on_writeTor1();
signals:

};

#endif // MYMODBUS_H
