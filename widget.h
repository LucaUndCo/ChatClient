#ifndef WIDGET_H
#define WIDGET_H

#include "client.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
signals:
    void connectpressed(QString ip, int port);
private slots:
    void on_PB_Connect_clicked();

    void on_PB_DisConnect_clicked();

    void on_PB_Exit_clicked();

    void on_PB_Send_clicked();

private:
    Client *client;
    Ui::Widget *ui;
    void updateChatBox(QString message);


};
#endif // WIDGET_H
