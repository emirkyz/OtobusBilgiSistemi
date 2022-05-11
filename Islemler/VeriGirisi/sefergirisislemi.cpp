#include "sefergirisislemi.h"
#include <Veri/data.h>
#include <Formlar/VeriFormlari/seferverigirisformu.h>

SeferGirisIslemi::SeferGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("Yeni Sefer İşlemi"));
    _islem->setIcon(QIcon(":/Resimler/Sefer.png"));
    _islem->setIconText("Yeni Sefer İşlemi");
    connect(_islem,&QAction::triggered, this, &SeferGirisIslemi::main);
}

void SeferGirisIslemi::main()
{
    auto veri =Data::d1().seferler().yeniNesne();
    SeferVeriGirisFormu *form = new SeferVeriGirisFormu;
    connect(form,&SeferVeriGirisFormu::veriKaydet, this, &SeferGirisIslemi::depoEkle);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->setVeri(veri);
    form->show();
     /*
     * BURAYI SIGNAL İLE YAZINCA, KAYDET E BASINCA KAPANMIYOR!!!
     */
}

QAction *SeferGirisIslemi::islem()
{
    return _islem;
}

void SeferGirisIslemi::depoEkle()
{
    SeferVeriGirisFormu *frmx = dynamic_cast<SeferVeriGirisFormu *>(sender());
    auto veri = frmx->veri();
    Data::d1().seferler().nesneEkle(veri);
    frmx->close();
}
