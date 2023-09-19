#include "client.h"

Client::Client(QObject *parent)
    : QObject{parent}
{
    socket = new QTcpSocket(this);
    qDebug() << socket;
    connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

void Client::connectToServer(QString adress, int port)
{
    qDebug() << "trying to connect" << port;
    if (socket) {
        socket->connectToHost(adress, port);
        if (socket->waitForConnected()) {
            qDebug() << "Connected to server";
        } else {
            qDebug() << "Connection failed: " << socket->errorString();
        }
    } else {
        qDebug() << "Socket not initialized.";
    }
}

void Client::disconnectFromServer()
{
    socket->disconnectFromHost();
}

void Client::readData()
{
    while (socket->canReadLine()) {
        QByteArray data = socket->readLine();
        qDebug() << data;
        emit chatChanged(data);
        qDebug() << "signal emited";
        data.clear();
    }
}

void Client::sendData(QByteArray text)
{
    if(text == nullptr || text == "")
        return;
    qDebug() << text;
    text.append("\r\n");
    socket->write(text);
}
