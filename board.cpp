#include "board.h"
#include "ui_board.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    QPalette tmp = this -> palette();
    tmp.setBrush(QPalette::Background, QPixmap("://image/board.svg").scaled(
                                                  size(),
                                                  Qt::IgnoreAspectRatio,
                                                  Qt::SmoothTransformation));
    setPalette(tmp);
    tmpFile.setFileName("tmpfile.ccd");
    tmpFile.open(QIODevice::WriteOnly);
    tmpFile.close();
    zi.push_back(new Zi(this, black, jv, 1, 1));
    zi.push_back(new Zi(this, black, jv, 9, 1));
    zi.push_back(new Zi(this, black, ma, 2, 1));
    zi.push_back(new Zi(this, black, ma, 8, 1));
    zi.push_back(new Zi(this, black, xiang, 3, 1));
    zi.push_back(new Zi(this, black, xiang, 7, 1));
    zi.push_back(new Zi(this, black, shi, 4, 1));
    zi.push_back(new Zi(this, black, shi, 6, 1));
    zi.push_back(new Zi(this, black, pao, 2, 3));
    zi.push_back(new Zi(this, black, pao, 8, 3));
    zi.push_back(new Zi(this, black, zu, 1, 4));
    zi.push_back(new Zi(this, black, zu, 3, 4));
    zi.push_back(new Zi(this, black, zu, 5, 4));
    zi.push_back(new Zi(this, black, zu, 7, 4));
    zi.push_back(new Zi(this, black, zu, 9, 4));
    zi.push_back(new Zi(this, black, shuai, 5, 1));

    zi.push_back(new Zi(this, red, jv, 1, 10));
    zi.push_back(new Zi(this, red, jv, 9, 10));
    zi.push_back(new Zi(this, red, ma, 2, 10));
    zi.push_back(new Zi(this, red, ma, 8, 10));
    zi.push_back(new Zi(this, red, xiang, 3, 10));
    zi.push_back(new Zi(this, red, xiang, 7, 10));
    zi.push_back(new Zi(this, red, shi, 4, 10));
    zi.push_back(new Zi(this, red, shi, 6, 10));
    zi.push_back(new Zi(this, red, pao, 2, 8));
    zi.push_back(new Zi(this, red, pao, 8, 8));
    zi.push_back(new Zi(this, red, zu, 1, 7));
    zi.push_back(new Zi(this, red, zu, 3, 7));
    zi.push_back(new Zi(this, red, zu, 5, 7));
    zi.push_back(new Zi(this, red, zu, 7, 7));
    zi.push_back(new Zi(this, red, zu, 9, 7));
    zi.push_back(new Zi(this, red, shuai, 5, 10));
    setFirst(red);
    for(int i = 0; i < zi.size(); ++i){
        connect(zi[i], &Zi::Selected, this, &Board::SelectZi);
        connect(zi[i], &Zi::UnSelected, this, &Board::UnSelectZi);
    }
//    legalPoint.push_back();
//    connect(this, )
//    QPushButton *a = new QPushButton(this);
//    a -> setGeometry(600,760,80,80);
//    a -> setText("a");
//    a -> show();
//    setStyleSheet("border-image:url(:/image/2oavrzzc.png)");
}

Board::~Board()
{
    delete ui;
}

Zi *Board::GetZi(int x, int y)
{
    for(int i = 0; i < zi.size(); ++i){
        if(zi[i] -> GetAlive() && zi[i] -> Getx() == x && zi[i] -> Gety() == y) return zi[i];
    }
    return nullptr;
}

bool Board::IfLegalMove(Zi *zi, int x, int y)
{
    if(x < 1 || x > 9 || y < 1 || y > 10 ||
            (GetZi(x, y) != nullptr && GetZi(x, y) -> GetCountry() == zi -> GetCountry())) return false;
    return true;
}

int Board::GetId(Zi *z)
{
    for(int i = 0; i < zi.size(); ++i){
        if(zi[i] == z) return i;
    }
    return -1;
}

void Board::setFirst(Country c)
{
    for(int i = 0; i < zi.size(); ++i){
        if(zi[i]->GetCountry() == c){
            zi[i]->setEnableSelect(true);
        }
        else{
            zi[i]->setEnableSelect(false);
        }
    }
}

void Board::SetEnableUse(bool flag)
{
    enableUse = flag;
    for(int i = 0; i < zi.size(); ++i){
        zi[i] -> setEnableSelect(flag);
    }
}

Zi *Board::GetZiAddress(int a)
{
    return zi[a];
}

LegalPoint *Board::GetLegalPointAddress(int x, int y)
{
    for(int i = 0; i < legalPoint.size(); ++i){
        if(legalPoint[i] -> Getx() == x && legalPoint[i] -> Gety() == y) return legalPoint[i];
    }
    return nullptr;
}

void Board::SelectZi(Zi *zi)
{
    if(selectedZi != nullptr){
        emit selectedZi -> UnSelected(selectedZi);
    }
    selectedZi = zi;
    int x = selectedZi -> Getx(), y = selectedZi -> Gety();
    for(int i = 0; i < legalPoint.size(); ++i){
        delete legalPoint[i];
    }
    legalPoint.clear();
    switch (selectedZi -> GetArmType()) {
    case jv:
        for(int i = 1; i <= 9; ++i){
            int nx = x + i, ny = y;
            if(IfLegalMove(selectedZi, nx, ny)){
                legalPoint.push_back(new LegalPoint(this, nx, ny));
                if(GetZi(nx, ny) != nullptr) break;
            }
            else break;
        }
        for(int i = 1; i <= 9; ++i){
            int nx = x - i, ny = y;
            if(IfLegalMove(selectedZi, nx, ny)){
                legalPoint.push_back(new LegalPoint(this, nx, ny));
                if(GetZi(nx, ny) != nullptr) break;
            }
            else break;
        }
        for(int i = 1; i <= 9; ++i){
            int nx = x, ny = y + i;
            if(IfLegalMove(selectedZi, nx, ny)){
                legalPoint.push_back(new LegalPoint(this, nx, ny));
                if(GetZi(nx, ny) != nullptr) break;
            }
            else break;
        }
        for(int i = 1; i <= 9; ++i){
            int nx = x, ny = y - i;
            if(IfLegalMove(selectedZi, nx, ny)){
                legalPoint.push_back(new LegalPoint(this, nx, ny));
                if(GetZi(nx, ny) != nullptr) break;
            }
            else break;
        }
        break;
    case ma:
        if(IfLegalMove(selectedZi, x - 1, y - 2) && GetZi(x, y - 1) == nullptr) legalPoint.push_back(new LegalPoint(this, x - 1, y - 2));
        if(IfLegalMove(selectedZi, x + 1, y - 2) && GetZi(x, y - 1) == nullptr) legalPoint.push_back(new LegalPoint(this, x + 1, y - 2));
        if(IfLegalMove(selectedZi, x - 1, y + 2) && GetZi(x, y + 1) == nullptr) legalPoint.push_back(new LegalPoint(this, x - 1, y + 2));
        if(IfLegalMove(selectedZi, x + 1, y + 2) && GetZi(x, y + 1) == nullptr) legalPoint.push_back(new LegalPoint(this, x + 1, y + 2));
        if(IfLegalMove(selectedZi, x - 2, y - 1) && GetZi(x - 1, y) == nullptr) legalPoint.push_back(new LegalPoint(this, x - 2, y - 1));
        if(IfLegalMove(selectedZi, x - 2, y + 1) && GetZi(x - 1, y) == nullptr) legalPoint.push_back(new LegalPoint(this, x - 2, y + 1));
        if(IfLegalMove(selectedZi, x + 2, y - 1) && GetZi(x + 1, y) == nullptr) legalPoint.push_back(new LegalPoint(this, x + 2, y - 1));
        if(IfLegalMove(selectedZi, x + 2, y + 1) && GetZi(x + 1, y) == nullptr) legalPoint.push_back(new LegalPoint(this, x + 2, y + 1));
        break;
    case pao:
        //走
        for(int i = 1; i <= 9; ++i){
            int nx = x + i, ny = y;
            if(IfLegalMove(selectedZi, nx, ny) && GetZi(nx, ny) == nullptr){
                legalPoint.push_back(new LegalPoint(this, nx, ny));
            }
            else break;
        }
        for(int i = 1; i <= 9; ++i){
            int nx = x - i, ny = y;
            if(IfLegalMove(selectedZi, nx, ny) && GetZi(nx, ny) == nullptr){
                legalPoint.push_back(new LegalPoint(this, nx, ny));
            }
            else break;
        }
        for(int i = 1; i <= 9; ++i){
            int nx = x, ny = y + i;
            if(IfLegalMove(selectedZi, nx, ny) && GetZi(nx, ny) == nullptr){
                legalPoint.push_back(new LegalPoint(this, nx, ny));
            }
            else break;
        }
        for(int i = 1; i <= 9; ++i){
            int nx = x, ny = y - i;
            if(IfLegalMove(selectedZi, nx, ny) && GetZi(nx, ny) == nullptr){
                legalPoint.push_back(new LegalPoint(this, nx, ny));
            }
            else break;
        }
        //打
        for(int i = 1; i <= 9; ++i){
            int nx = x + i, ny = y;
            if(nx >= 1 && nx <= 9 && ny >= 1 && ny <= 10 && GetZi(nx, ny) != nullptr){
                for(++i; i <= 9; ++i){
                    nx = x + i, ny = y;
                    if(IfLegalMove(selectedZi, nx, ny) && GetZi(nx, ny) != nullptr){
                        legalPoint.push_back(new LegalPoint(this, nx, ny));
                        break;
                    }
                }
                break;
            }
        }
        for(int i = 1; i <= 9; ++i){
            int nx = x - i, ny = y;
            if(nx >= 1 && nx <= 9 && ny >= 1 && ny <= 10 && GetZi(nx, ny) != nullptr){
                for(++i; i <= 9; ++i){
                    nx = x - i, ny = y;
                    if(IfLegalMove(selectedZi, nx, ny) && GetZi(nx, ny) != nullptr){
                        legalPoint.push_back(new LegalPoint(this, nx, ny));
                        break;
                    }
                }
                break;
            }
        }
        for(int i = 1; i <= 9; ++i){
            int nx = x, ny = y + i;
            if(nx >= 1 && nx <= 9 && ny >= 1 && ny <= 10 && GetZi(nx, ny) != nullptr){
                for(++i; i <= 9; ++i){
                    nx = x, ny = y + i;
                    if(IfLegalMove(selectedZi, nx, ny) && GetZi(nx, ny) != nullptr){
                        legalPoint.push_back(new LegalPoint(this, nx, ny));
                        break;
                    }
                }
                break;
            }
        }
        for(int i = 1; i <= 9; ++i){
            int nx = x, ny = y - i;
            if(nx >= 1 && nx <= 9 && ny >= 1 && ny <= 10 && GetZi(nx, ny) != nullptr){
                for(++i; i <= 9; ++i){
                    nx = x, ny = y - i;
                    if(IfLegalMove(selectedZi, nx, ny) && GetZi(nx, ny) != nullptr){
                        legalPoint.push_back(new LegalPoint(this, nx, ny));
                        break;
                    }
                }
                break;
            }
        }
        break;
    case shi:
        if(IfLegalMove(selectedZi, x + 1, y + 1) && x + 1 >= 4 && x + 1 <= 6 && (y + 1 <= 3 || y + 1 >= 8)) legalPoint.push_back(new LegalPoint(this, x + 1, y + 1));
        if(IfLegalMove(selectedZi, x - 1, y - 1) && x - 1 >= 4 && x - 1 <= 6 && (y - 1 <= 3 || y - 1 >= 8)) legalPoint.push_back(new LegalPoint(this, x - 1, y - 1));
        if(IfLegalMove(selectedZi, x + 1, y - 1) && x + 1 >= 4 && x + 1 <= 6 && (y - 1 <= 3 || y - 1 >= 8)) legalPoint.push_back(new LegalPoint(this, x + 1, y - 1));
        if(IfLegalMove(selectedZi, x - 1, y + 1) && x - 1 >= 4 && x - 1 <= 6 && (y + 1 <= 3 || y + 1 >= 8)) legalPoint.push_back(new LegalPoint(this, x - 1, y + 1));
        break;
    case xiang:
        if(IfLegalMove(selectedZi, x - 2, y - 2) && GetZi(x - 1, y - 1) == nullptr && ((selectedZi -> GetCountry() == black && y - 2 <= 5) || (selectedZi -> GetCountry() == red && y - 2 >= 6))) legalPoint.push_back(new LegalPoint(this, x - 2, y - 2));
        if(IfLegalMove(selectedZi, x + 2, y - 2) && GetZi(x + 1, y - 1) == nullptr && ((selectedZi -> GetCountry() == black && y - 2 <= 5) || (selectedZi -> GetCountry() == red && y - 2 >= 6))) legalPoint.push_back(new LegalPoint(this, x + 2, y - 2));
        if(IfLegalMove(selectedZi, x - 2, y + 2) && GetZi(x - 1, y + 1) == nullptr && ((selectedZi -> GetCountry() == black && y + 2 <= 5) || (selectedZi -> GetCountry() == red && y + 2 >= 6))) legalPoint.push_back(new LegalPoint(this, x - 2, y + 2));
        if(IfLegalMove(selectedZi, x + 2, y + 2) && GetZi(x + 1, y + 1) == nullptr && ((selectedZi -> GetCountry() == black && y + 2 <= 5) || (selectedZi -> GetCountry() == red && y + 2 >= 6))) legalPoint.push_back(new LegalPoint(this, x + 2, y + 2));
        break;
    case zu:
        //没过河1
        if(IfLegalMove(selectedZi, x, y + (selectedZi -> GetCountry() == black ? 1 : -1))) legalPoint.push_back(new LegalPoint(this, x, y + (selectedZi -> GetCountry() == black ? 1 : -1)));
        if(selectedZi -> GetCountry() == black){
            if(selectedZi -> Gety() >= 6){
                if(IfLegalMove(selectedZi, x + 1, y)) legalPoint.push_back(new LegalPoint(this, x + 1, y));
                if(IfLegalMove(selectedZi, x - 1, y)) legalPoint.push_back(new LegalPoint(this, x - 1, y));
            }
        }
        else{
            if(selectedZi -> Gety() <= 5){
                if(IfLegalMove(selectedZi, x + 1, y)) legalPoint.push_back(new LegalPoint(this, x + 1, y));
                if(IfLegalMove(selectedZi, x - 1, y)) legalPoint.push_back(new LegalPoint(this, x - 1, y));
            }
        }
        break;
    case shuai:
        if(IfLegalMove(selectedZi, x + 1, y) && x + 1 >= 4 && x + 1 <= 6 && (y <= 3 || y >= 8)) legalPoint.push_back(new LegalPoint(this, x + 1, y));
        if(IfLegalMove(selectedZi, x - 1, y) && x - 1 >= 4 && x - 1 <= 6 && (y <= 3 || y >= 8)) legalPoint.push_back(new LegalPoint(this, x - 1, y));
        if(IfLegalMove(selectedZi, x, y - 1) && x >= 4 && x <= 6 && (y - 1 <= 3 || y - 1 >= 8)) legalPoint.push_back(new LegalPoint(this, x, y - 1));
        if(IfLegalMove(selectedZi, x, y + 1) && x >= 4 && x <= 6 && (y + 1 <= 3 || y + 1 >= 8)) legalPoint.push_back(new LegalPoint(this, x, y + 1));
        if(GetZi(x, selectedZi -> GetCountry() == black ? 10 : 1) != nullptr && GetZi(x, selectedZi -> GetCountry() == black ? 10 : 1) -> GetArmType() == shuai) legalPoint.push_back(new LegalPoint(this, x, selectedZi -> GetCountry() == black ? 10 : 1));
        break;
    default:
        break;
    }
    for(int i = 0; i < legalPoint.size(); ++i){
        legalPoint[i] -> setEnableClick(enableUse);
        connect(legalPoint[i], &LegalPoint::Selected, this, &Board::MoveZi);
    }
}

void Board::UnSelectZi(Zi *zi)
{
    if(selectedZi != nullptr) selectedZi -> CancelSelected();
    if(selectedZi == zi) selectedZi = nullptr;
    for(int i = 0; i < legalPoint.size(); ++i){
        disconnect(legalPoint[i], &LegalPoint::Selected, this, &Board::MoveZi);
        delete legalPoint[i];
    }
    legalPoint.clear();
}

void Board::MoveZi(LegalPoint *id)
{
    tmpFile.open(QIODevice::Append);
    tmpFile.write(QString("%1\n").arg(con++).toUtf8());
    Zi *zi = GetZi(id -> Getx(), id -> Gety());
    int ziId = GetId(zi), selectedZiId = GetId(selectedZi);
    if(zi != nullptr){
        zi -> BeDead();
        tmpFile.write(QString("100 %1\n").arg(ziId).toUtf8());
    }
    selectedZi -> Move(id -> Getx(), id -> Gety());
    tmpFile.write(QString("101 %1 %2 %3\n\n").arg(selectedZiId).arg(id -> Getx()).arg(id -> Gety()).toUtf8());
    tmpFile.close();
    setFirst(selectedZi->GetCountry() == red ? black : red);
    UnSelectZi(selectedZi);
    if(zi != nullptr && zi -> GetArmType() == shuai){
        if(zi -> GetCountry() == red){
            QMessageBox MyBox(QMessageBox::NoIcon,"结果","黑方胜，是否保存对局？",QMessageBox::Yes|QMessageBox::No);
            MyBox.setIconPixmap(QPixmap("://image/heixiang.svg"));
            MyBox.exec();
            if(MyBox.standardButton(MyBox.clickedButton()) == QMessageBox::Yes){
                QString path = QFileDialog::getSaveFileName(this, "保存为", "/", "Chinese Chess Data, ccd(*.ccd)");
                if(path != ""){
                    if(QFile::exists(path)) QFile::remove(path);
                    tmpFile.copy(path);
                }
            }
        }
        else{
            QMessageBox MyBox(QMessageBox::NoIcon,"结果","红方胜，是否保存对局？",QMessageBox::Yes|QMessageBox::No);
            MyBox.setIconPixmap(QPixmap("://image/hongxiang.svg"));
            MyBox.exec();
            if(MyBox.standardButton(MyBox.clickedButton()) == QMessageBox::Yes){
                QString path = QFileDialog::getSaveFileName(this, "保存为", "/", "Chinese Chess Data, ccd(*.ccd)");
                if(path != ""){
                    if(QFile::exists(path)) QFile::remove(path);
                    tmpFile.copy(path);
                }
            }
        }
    }
}
