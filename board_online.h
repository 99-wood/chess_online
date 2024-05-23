#ifndef BOARD_ONLINE_H
#define BOARD_ONLINE_H

#include <QWidget>
#include <QUdpSocket>
#include <QWidget>
#include <QPalette>
#include <QBrush>
#include <QPushButton>
#include <QMessageBox>
#include <QVector>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QNetworkDatagram>
#include "zi.h"
#include "legalpoint.h"


class Board_online : public QWidget
{
    Q_OBJECT

private:
    bool redFirst = true;
    const int posx[10] = {0, 40, 120, 200, 280, 360, 440, 520, 600, 680},
        posy[11] = {0, 120, 200, 280, 360, 440, 520, 600, 680, 760, 840};
    QVector<Zi*> zi;
    QVector<LegalPoint*> legalPoint;
    Zi *selectedZi = nullptr;
    QFile tmpFile;
    int con = 1;
    bool enableUse = true;
    Zi* GetZi(int x, int y);
    bool IfLegalMove(Zi* zi, int x, int y);
    int GetId(Zi *zi);
    void setFirst(Country c);
    QUdpSocket *my;
    QHostAddress other;
    int port;
    bool enable;


public:
    explicit Board_online(QUdpSocket *my, QHostAddress other, int port, bool enable, QWidget *parent = nullptr);
    ~Board_online();
    void SetEnableUse(bool flag);
    Zi* GetZiAddress(int a);
    LegalPoint* GetLegalPointAddress(int x, int y);
    int sentMsg(QString msg);

public slots:
    void SelectZi(Zi* zi);
    void UnSelectZi(Zi* zi);
    void MoveZi(LegalPoint* id);
    void process();
};

#endif // BOARD_ONLINE_H
