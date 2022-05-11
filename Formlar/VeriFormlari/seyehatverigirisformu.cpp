#include "seyehatverigirisformu.h"
#include "ui_seyehatverigirisformu.h"

SeyehatVeriGirisFormu::SeyehatVeriGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeyehatVeriGirisFormu)
{
    ui->setupUi(this);
    connect(ui->btnKaydet, SIGNAL(clicked()),this, SIGNAL(veriKaydet()));
}

SeyehatVeriGirisFormu::~SeyehatVeriGirisFormu()
{
    delete ui;
}


void SeyehatVeriGirisFormu::ekranGuncelle()
{
}

void SeyehatVeriGirisFormu::veriGuncelle()
{
}
