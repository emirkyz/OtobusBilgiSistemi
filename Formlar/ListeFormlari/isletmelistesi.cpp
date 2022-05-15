#include "isletmelistesi.h"
#include "ui_isletmelistesi.h"

IsletmeListesi::IsletmeListesi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IsletmeListesi)
{
    ui->setupUi(this);
}

IsletmeListesi::~IsletmeListesi()
{
    delete ui;
}
