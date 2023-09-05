#include "client.h"

Client::Client(QObject *parent)
    : QObject{parent}
{

}

void Client::connectToServer(QString adress, int port)
{
    socket->connectToHost(adress,port);
}

void Client::disconnectFromServer()
{
    socket->disconnectFromHost();
}

void Client::readData()
{
    QByteArray data;
    while (socket->canReadLine()) {
        data = socket->readLine();
        emit chatChanged(data);
        data.clear();
    }
}

void Client::sendData(QByteArray text)
{
    socket->write(text);
}
