#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server), existServer(false), userName("")
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);
//    receiver = new QUdpSocket(this);
//    if (!->bind(QHostAddress::AnyIPv4, 10088)){
//        qDebug() << "Failed to bind UDP socket!";
//    }
    if (!udpSocket->bind(QHostAddress::AnyIPv4, 10086, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint)){
        qDebug() << "Failed to bind UDP socket!";
    }
    qDebug() << udpSocket->localAddress().toString();
    qDebug() << udpSocket->localPort();
    connect(udpSocket, &QUdpSocket::readyRead, this, &Server::receiveServerMsg);

//    QByteArray datagram("ok");
//    qint64 bytesSent = udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 10086);
//    qDebug() << bytesSent;
    ui->listWidget->setSelectionMode(QAbstractItemView::SingleSelection); //只可以单选
    connect(ui->name, &QPushButton::clicked, this, [=](){
        if(userName != ""){
            boardcastMsg(QString("%1 %2").arg("0").arg(userName).toUtf8());
        }
        boardcastMsg(QString("%1 %2").arg("1").arg(ui->lineEdit->text()).toUtf8());
        userName = ui->lineEdit->text();
//        qint64 bytesSent = udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 10086);
//        qDebug() << bytesSent;
    });
    connect(ui->enter, &QPushButton::clicked, this, [=](){
        QListWidgetItem *currentItem = ui->listWidget->currentItem();
       if (currentItem && (currentItem->text().split('|'))[0] != userName) {
           QByteArray datagram(QString("2").toUtf8());
           udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress(currentItem->text().split('|')[1]), 10086);
       } else {
       }
    });
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
    qDebug() <<  data.data();
//    QString str()
    QStringList msg = QString(data.data()).split(' ');
    qDebug() << msg.count();
    if(msg[0] == "1"){
        ui->listWidget->addItem(QString("%1|%2").arg(msg[1]).arg(data.senderAddress().toString()));
    }
    else if(msg[0] == "0"){
        for(int i = 0; i < ui->listWidget->count(); ++i){
            QListWidgetItem *a = ui->listWidget->item(i);
            if(a->text() == QString("%1|%2").arg(msg[1]).arg(data.senderAddress().toString())){
                qDebug()<<i;
                ui->listWidget->takeItem(i);
                break;
            }
        }
    }
    else if(msg[0] == "2"){ //接受申请
        QMessageBox MyBox(QMessageBox::NoIcon, "主人申请来啦", QString("%1 发起申请，是否同意？").arg(msg[1]), QMessageBox::Yes|QMessageBox::No);
//        MyBox.setIconPixmap(QPixmap("://image/hongxiang.svg"));
        MyBox.exec();
        if(MyBox.standardButton(MyBox.clickedButton()) == QMessageBox::Yes){
            other = data.senderAddress();
            port = (rand() % 10000) + 10000;
            boardcastMsg(QString("3 %1").arg(port));
            Board_online *newPage = new Board_online(udpSocket,other,port,true,nullptr);
            newPage -> setAttribute(Qt::WA_DeleteOnClose);
            newPage -> show();
        }

    }
    else if(msg[0] == "3"){ //同意
        port = msg[1].toInt();
        other = data.senderAddress();
        Board_online *newPage = new Board_online(udpSocket,other,port,false,nullptr);
        newPage -> setAttribute(Qt::WA_DeleteOnClose);
        newPage -> show();
//        Board *newPage = new Board(nullptr);
//        newPage -> setAttribute(Qt::WA_DeleteOnClose);
//        newPage -> show();
    }
}

int Server::boardcastMsg(QString a, int port)
{
    QByteArray datagram(a.toUtf8());
    return udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, port);
}
