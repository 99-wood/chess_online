#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QHostAddress>
#include <QThread>
#include <QString>
#include <QListWidget>
#include <QNetworkDatagram>
#include <QtDebug>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();
private slots:
    bool connectToServer();
    void receiveServerMsg();

private:
    enum Identify{SERVER, USER};
    Ui::Server *ui;
    bool existServer;
//    QTcpSocket *tcpSocket;
//    QTcpServer *server;
    QUdpSocket *udpSocket;
//    QUdpSocket boardcast;
signals:
//    void succeedConnect(Identify state, QTcpServer *server, QTcpSocket socket);
};

#endif // SERVER_H
