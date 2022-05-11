#include "seferverigirisformu.h"
#include "ui_seferverigirisformu.h"

SeferVeriGirisFormu::SeferVeriGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeferVeriGirisFormu)
{
    ui->setupUi(this);
    connect(ui->btnKaydet,SIGNAL(clicked()),this, SIGNAL(veriKaydet()));
}

SeferVeriGirisFormu::~SeferVeriGirisFormu()
{
    delete ui;
}


void SeferVeriGirisFormu::ekranGuncelle()
{
    ui->leSeferUzunluk->setText(_veri->SeferUzunluk());
    ui->leBaslangicNoktasi->setText(_veri->BaslangicNoktasi());
    ui->leVarisNoktasi->setText(_veri->VarisNoktasi());
    ui->spnMesafe->setValue(_veri->Mesafe());
    ui->spnMolaSayisi->setValue(_veri->MolaSayisi());

}

void SeferVeriGirisFormu::veriGuncelle()
{
    _veri->setSeferUzunluk(ui->leSeferUzunluk->text());
    _veri->setBaslangicNoktasi(ui->leBaslangicNoktasi->text());
    _veri->setVarisNoktasi(ui->leVarisNoktasi->text());
    _veri->setMesafe(ui->spnMesafe->value());
    _veri->setMolaSayisi(ui->spnMolaSayisi->value());

}
