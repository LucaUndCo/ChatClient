#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    client = new Client(this);
    connect(client, &Client::chatChanged, this, &Widget::updateChatBox);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_PB_Connect_clicked()
{
    qDebug() << "button for connection pressed";
    QString port = ui->TE_Port->toPlainText();
    QString ip = ui->TE_IP->toPlainText();
    qDebug() << port.toInt();
    qDebug() << ip;

    try {
        client->connectToServer(ip, port.toInt());
        qDebug() << "variable called";
        ui->TE_IP->clear();
        ui->TE_Port->clear();
    } catch (const std::exception& e) {
        qDebug() << "Error: " << e.what();
        // Hier kannst du weitere Fehlerbehandlung hinzufügen.
    }
}


void Widget::on_PB_DisConnect_clicked()
{
    client->disconnectFromServer();
}

void Widget::updateChatBox(QString message)
{
    qDebug() << "funtion for chat box started";
    ui->TB_Chat->append(message);
    qDebug() << "message appended";
}


void Widget::on_PB_Exit_clicked()
{
    QApplication::quit();
}


void Widget::on_PB_Send_clicked()
{
    QByteArray message = ui->TE_Send->toPlainText().toUtf8();
    client->sendData(message);
    message.clear();
    ui->TE_Send->clear();
}

