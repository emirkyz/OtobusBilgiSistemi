#include "yolcugirisformu.h"
#include "ui_yolcugirisformu.h"

YolcuGirisFormu::YolcuGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YolcuGirisFormu)
{
    ui->setupUi(this);
    connect(ui->btnKaydet, SIGNAL(clicked()),this, SIGNAL(veriKaydet()));
}

YolcuGirisFormu::~YolcuGirisFormu()
{
    delete ui;
}


void YolcuGirisFormu::ekranGuncelle()
{
    ui->leYolcuAd->setText(_veri->Ad());
    ui->leYolcuSoyad->setText(_veri->Soyad());
    ui->leHesKodu->setText(_veri->HesKodu());
    ui->leTcKimlikNo->setText(_veri->TcKimlikNo());
    ui->spnYas->setValue(_veri->Yas());
}

void YolcuGirisFormu::veriGuncelle()
{
    _veri->setAd(ui->leYolcuAd->text());
    _veri->setSoyad(ui->leYolcuSoyad->text());
    _veri->setHesKodu(ui->leHesKodu->text());
    _veri->setTcKimlikNo(ui->leTcKimlikNo->text());
    _veri->setYas(ui->spnYas->value());

}
