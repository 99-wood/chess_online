#include "reproduce.h"
#include "ui_reproduce.h"

Reproduce::Reproduce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reproduce)
{
    ui->setupUi(this);
    ui -> board -> SetEnableUse(false);
    QString path = QFileDialog::getOpenFileName(this, "选择要复盘的对局文件（ccd）", "/", "中国象棋对局文件(*.ccd)");
    if(!QFile::exists(path)){
        QMessageBox::warning(this, "错误", "路径无效，请重新选择", QMessageBox::Yes);
        ifSuccess = false;
        return;
    }
    killZi.push_back(-1);
    selecedZi.push_back(-1);
    moveTox.push_back(-1);
    moveToy.push_back(-1);
    QFile lastGameFile(path);
    lastGameFile.open(QIODevice::ReadOnly);
    QTextStream in(&lastGameFile);
    while(!in.atEnd()){
        int cnt, op;
        in >> cnt;
        in >> op;
        if(op == 100){
            int a; in >> a;
            killZi.push_back(a);
            in >> op;
        }
        else killZi.push_back(-1);
        if(op == 101){
            int a, x, y; in >> a >> x >> y;
            selecedZi.push_back(a);
            moveTox.push_back(x);
            moveToy.push_back(y);
        }
    }
    lastGameFile.close();
    connect(ui -> preButton, &QPushButton::clicked, this, &Reproduce::Pre);
    connect(ui -> nxtButton, &QPushButton::clicked, this, &Reproduce::Nxt);
}

Reproduce::~Reproduce()
{
    delete ui;
}

bool Reproduce::IfSuccessBuild()
{
    return ifSuccess;
}

void Reproduce::Nxt()
{
    if(now == selecedZi.size() - 1) return;
    ++now;
    if(killZi[now] != -1){
        Zi *kzi = ui -> board ->GetZiAddress(killZi[now]);
        kzi -> BeDead();
    }
    Zi *zi = ui -> board ->GetZiAddress(selecedZi[now]);
    int x = zi -> Getx(), y = zi -> Gety();
    zi -> Move(moveTox[now], moveToy[now]);
    moveTox[now] = x; moveToy[now] = y;
}

void Reproduce::Pre()
{
    if(now == 0) return;
    if(killZi[now] != -1){
        Zi *kzi = ui -> board ->GetZiAddress(killZi[now]);
        qDebug() << killZi[now];
        kzi -> BeAlive();
    }
    Zi *zi = ui -> board ->GetZiAddress(selecedZi[now]);
    qDebug() << selecedZi[now];
    int x = zi -> Getx(), y = zi -> Gety();
    zi -> Move(moveTox[now], moveToy[now]);
    moveTox[now] = x; moveToy[now] = y;
    --now;
}

