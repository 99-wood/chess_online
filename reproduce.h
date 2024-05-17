#ifndef REPRODUCE_H
#define REPRODUCE_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QVector>
#include <QString>
#include <QByteArray>
#include <QTextStream>
#include <QDebug>

namespace Ui {
class Reproduce;
}

class Reproduce : public QWidget
{
    Q_OBJECT

public:
    explicit Reproduce(QWidget *parent = nullptr);
    ~Reproduce();
    bool IfSuccessBuild();

public slots:
    void Nxt();
    void Pre();

private:
    Ui::Reproduce *ui;
    QVector<int> killZi;
    QVector<int> selecedZi;
    QVector<int> moveTox;
    QVector<int> moveToy;
    int now = 0;
    bool ifSuccess = true;
};

#endif // REPRODUCE_H
