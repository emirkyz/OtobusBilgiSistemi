#include "isletmeverigirisformu.h"
#include "ui_isletmeverigirisformu.h"

IsletmeVeriGirisFormu::IsletmeVeriGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IsletmeVeriGirisFormu)
{
    ui->setupUi(this);
    connect(ui->btnKaydet,SIGNAL(clicked()), this, SIGNAL(veriKaydet()));
}

IsletmeVeriGirisFormu::~IsletmeVeriGirisFormu()
{
    delete ui;
}


void IsletmeVeriGirisFormu::ekranGuncelle()
{
    ui->leIsletmeAdi->setText(_veri->IsletmeAdi());
    ui->leKurucuAd->setText(_veri->KurucuAd());
    ui->leKurucuSoyad->setText(_veri->KurucuSoyad());
    ui->leVergiNumarasi->setText(_veri->VergiNo());
    ui->leYerlesmeYeri->setText(_veri->Adres());
}

void IsletmeVeriGirisFormu::veriGuncelle()
{
    _veri->setIsletmeAdi(ui->leIsletmeAdi->text());
    _veri->setKurucuAd(ui->leKurucuAd->text());
    _veri->setKurucuSoyad(ui->leKurucuSoyad->text());
    _veri->setAdres(ui->leYerlesmeYeri->text());
    _veri->setVergiNo(ui->leVergiNumarasi->text());

}
