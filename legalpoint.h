#ifndef LEGALPOINT_H
#define LEGALPOINT_H

#include <QWidget>

namespace Ui {
class LegalPoint;
}

class LegalPoint : public QWidget
{
    Q_OBJECT
    const int chessSize = 80;
    bool enableClick = true;

protected:
//    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
public:
    explicit LegalPoint(QWidget *parent = nullptr);
    explicit LegalPoint(QWidget *parent = nullptr, int x = 0, int y = 0);
    ~LegalPoint();
    void Move(const int &x, const int &y);
    int Getx();
    int Gety();
    void setEnableClick(bool flag);
private:
    Ui::LegalPoint *ui;

signals:
    void Selected(LegalPoint *id);
};

#endif // LEGALPOINT_H
