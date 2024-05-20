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
#include <QMessageBox>

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
    QUdpSocket *udpSocket;
    QUdpSocket *receiver;
    QMap<QString, QHostAddress> mapp; //用户名，
    QString userName;
    QHostAddress other;
    int port;
    int boardcastMsg(QString a, int port = 10086);
signals:
//    void succeedConnect(Identify state, QTcpServer *server, QTcpSocket socket);
};

#endif // SERVER_H
