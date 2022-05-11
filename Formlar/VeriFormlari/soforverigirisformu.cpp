#include "soforverigirisformu.h"
#include "ui_soforverigirisformu.h"

SoforVeriGirisFormu::SoforVeriGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SoforVeriGirisFormu)
{
    ui->setupUi(this);
}

SoforVeriGirisFormu::~SoforVeriGirisFormu()
{
    delete ui;
}


void SoforVeriGirisFormu::ekranGuncelle()
{
    ui->leYolcuAd->setText(_veri->Ad());
    ui->leYolcuSoyad->setText(_veri->Soyad());
    ui->leHesKodu->setText(_veri->HesKodu());
    ui->leTcKimlikNo->setText(_veri->TcKimlikNo());
    ui->spnYas->setValue(_veri->Yas());
    ui->leEhliyetSinifi->setText(_veri->EhliyetSinifi());
    ui->leOtobusPlakasi->setText(_veri->OtobusPlakasi());
    ui->spnTecrubeSuresi->setValue(_veri->TecrubeSuresi());

}

void SoforVeriGirisFormu::veriGuncelle()
{
    _veri->setAd(ui->leYolcuAd->text());
    _veri->setSoyad(ui->leYolcuSoyad->text());
    _veri->setHesKodu(ui->leHesKodu->text());
    _veri->setTcKimlikNo(ui->leTcKimlikNo->text());
    _veri->setYas(ui->spnYas->value());
    _veri->setEhliyetSinifi(ui->leEhliyetSinifi->text());
    _veri->setOtobusPlakasi(ui->leOtobusPlakasi->text());
    _veri->setTecrubeSuresi(ui->spnTecrubeSuresi->value());

}
