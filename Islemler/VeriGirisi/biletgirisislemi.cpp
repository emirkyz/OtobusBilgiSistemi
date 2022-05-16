#include "biletgirisislemi.h"
#include <Veri/data.h>
#include <Formlar/VeriFormlari/biletverigirisformu.h>

BiletGirisIslemi::BiletGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction;
    _islem->setText(tr("Yeni Bilet İşlemi"));
    _islem->setIcon(QIcon(":/Resimler/YeniBilet.png"));
    _islem->setIconText(tr("Yeni Bilet İşlemi"));
    connect(_islem, &QAction::triggered, this, &BiletGirisIslemi::main);
}


void BiletGirisIslemi::main()
{
    auto veri = Data::d1().biletler().yeniNesne();
    BiletVeriGirisFormu *form = new BiletVeriGirisFormu();
    connect(form,&BiletVeriGirisFormu::veriKaydet,this, &BiletGirisIslemi::depoEkle);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->setVeri(veri);
    form->show();
}

QAction *BiletGirisIslemi::islem()
{
    return _islem;
}

void BiletGirisIslemi::depoEkle()
{
    BiletVeriGirisFormu *frmx = dynamic_cast<BiletVeriGirisFormu *>(sender());
    auto veri = frmx->veri();
    Data::d1().biletler().nesneEkle(veri);
    frmx->close();
}
