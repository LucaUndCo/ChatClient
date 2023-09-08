#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    void connectToServer(QString adress, int port);
    void disconnectFromServer();

    void sendData(QByteArray text);
private:
    QTcpSocket* socket;
signals:
    void chatChanged(QString text);
public slots:
    void readData();
};

#endif // CLIENT_H
