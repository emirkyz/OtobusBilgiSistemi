#include "otobusgirisformu.h"
#include "ui_otobusgirisformu.h"

OtobusGirisFormu::OtobusGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OtobusGirisFormu)
{
    ui->setupUi(this);
    connect(ui->btnKaydet,SIGNAL(clicked()),this, SIGNAL(veriKaydet()));
}

OtobusGirisFormu::~OtobusGirisFormu()
{
    delete ui;
}


void OtobusGirisFormu::ekranGuncelle()
{
    ui->leOturmaDuzeni->setText(_veri->OturmaDuzeni());
    ui->leBoyut->setText(_veri->Boyut());
    ui->leModel->setText(_veri->Model());
    ui->lePlaka->setText(_veri->Plaka());
    ui->leRenk->setText(_veri->Renk());
}

void OtobusGirisFormu::veriGuncelle()
{
    _veri->setOturmaDuzeni(ui->leOturmaDuzeni->text());
    _veri->setBoyut(ui->leBoyut->text());
    _veri->setModel(ui->leModel->text());
    _veri->setPlaka(ui->lePlaka->text());
    _veri->setRenk(ui->leRenk->text());
}
