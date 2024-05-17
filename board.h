#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPalette>
#include <QBrush>
#include <QPushButton>
#include <QMessageBox>
#include <QVector>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include "zi.h"
#include "legalpoint.h"

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

private:
    Ui::Board *ui;
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

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();
    void SetEnableUse(bool flag);
    Zi* GetZiAddress(int a);
    LegalPoint* GetLegalPointAddress(int x, int y);

public slots:
    void SelectZi(Zi* zi);
    void UnSelectZi(Zi* zi);
    void MoveZi(LegalPoint* id);
};

#endif // BOARD_H
