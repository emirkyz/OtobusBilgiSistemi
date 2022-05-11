#include "seyehatkurallariverigirisformu.h"
#include "ui_seyehatkurallariverigirisformu.h"

SeyehatKurallariVeriGirisFormu::SeyehatKurallariVeriGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeyehatKurallariVeriGirisFormu)
{
    ui->setupUi(this);
    connect(ui->btnKaydet,SIGNAL(clicked()),this,SIGNAL(veriKaydet()));
}

SeyehatKurallariVeriGirisFormu::~SeyehatKurallariVeriGirisFormu()
{
    delete ui;
}


void SeyehatKurallariVeriGirisFormu::ekranGuncelle()
{
    ui->plnKural->setPlainText(_veri->Kural());
}

void SeyehatKurallariVeriGirisFormu::veriGuncelle()
{
    _veri->setKural(ui->plnKural->toPlainText());
}
