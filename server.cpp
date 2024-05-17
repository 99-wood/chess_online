#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server), existServer(false)
{
    ui->setupUi(this);
//    QHostAddress ;
//    if (!udpSocket.bind(QHostAddress::AnyIPv4, 10086, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint)){
//        qDebug() << "Failed to bind UDP socket!";
//    }
    udpSocket = new QUdpSocket(this);
    if (!udpSocket->bind(QHostAddress::AnyIPv4, 8080, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint)){
        qDebug() << "Failed to bind UDP socket!";
    }
    qDebug() << udpSocket->localAddress().toString();
    qDebug() << udpSocket->localPort();
    connect(udpSocket, &QUdpSocket::readyRead, this, &Server::receiveServerMsg);
//    qDebug() << "ok" << endl;

    QByteArray datagram(udpSocket->localAddress().toString().toUtf8());
    qint64 bytesSent = udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 10086);
    qDebug() << bytesSent;
    ui->listWidget->setSelectionMode(QAbstractItemView::SingleSelection); //只可以单选
//    connect(ui->pushButton, &QPushButton::clicked, this, &Server::connectToServer);
}

Server::~Server()
{
    udpSocket->close();
    qDebug()<<"distruct";
    udpSocket->deleteLater();
    delete ui;
}

bool Server::connectToServer(){

}

void Server::receiveServerMsg(){
    qDebug() << "receive";
    QNetworkDatagram data = udpSocket->receiveDatagram(1024);
//    QString str()
    ui->listWidget->addItem(QString(data.data()));
}
