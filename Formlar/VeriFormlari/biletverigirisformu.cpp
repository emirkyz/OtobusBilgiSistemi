#include "biletverigirisformu.h"
#include "ui_biletverigirisformu.h"

BiletVeriGirisFormu::BiletVeriGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BiletVeriGirisFormu)
{
    ui->setupUi(this);
    connect(ui->btnKaydet,SIGNAL(clicked()), this, SIGNAL(veriKaydet()));
}

BiletVeriGirisFormu::~BiletVeriGirisFormu()
{
    delete ui;
}


void BiletVeriGirisFormu::ekranGuncelle()
{
    ui->spnKoltukNumarasi->setValue(_veri->KoltukNumarasi());
    ui->spnPeronNumarasi->setValue(_veri->PeronNumarasi());

}

void BiletVeriGirisFormu::veriGuncelle()
{
    _veri->setKoltukNumarasi(ui->spnKoltukNumarasi->value());
    _veri->setPeronNumarasi(ui->spnPeronNumarasi->value());
}
