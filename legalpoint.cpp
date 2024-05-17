#include "legalpoint.h"
#include "ui_legalpoint.h"

void LegalPoint::mouseReleaseEvent(QMouseEvent *event)
{
    if(enableClick)emit Selected(this);
}

LegalPoint::LegalPoint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LegalPoint)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    QPalette tmp = this -> palette();
    tmp.setBrush(QPalette::Background, QBrush(QPixmap("://image/point.svg").scaled(
                                                  this -> size(),
                                                  Qt::IgnoreAspectRatio,
                                                  Qt::SmoothTransformation)));
    setPalette(tmp);
    show();
}

LegalPoint::LegalPoint(QWidget *parent, int x, int y) :
QWidget(parent),
ui(new Ui::LegalPoint)
{
    ui->setupUi(this);
    Move(x, y);
    setAutoFillBackground(true);
    QPalette tmp = this -> palette();
    tmp.setBrush(QPalette::Background, QBrush(QPixmap("://image/point.svg").scaled(
                                                  this -> size(),
                                                  Qt::IgnoreAspectRatio,
                                                  Qt::SmoothTransformation)));
    setPalette(tmp);
    show();
}
LegalPoint::~LegalPoint()
{
    delete ui;
}

void LegalPoint::Move(const int &x, const int &y)
{
    setGeometry(x * 80 - 40 - chessSize / 2, y * 80 + 40 - chessSize / 2, chessSize, chessSize);
}

int LegalPoint::Getx()
{
    return (this -> pos().x() + chessSize / 2 + 40) / 80;
}

int LegalPoint::Gety()
{
    return (this -> pos().y() + chessSize / 2 - 40) / 80;
}

void LegalPoint::setEnableClick(bool flag)
{
    enableClick = flag;
}
