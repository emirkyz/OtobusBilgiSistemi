#include "otobusgirisislemi.h"
#include <Veri/data.h>
#include <Formlar/VeriFormlari/otobusgirisformu.h>
OtobusGirisIslemi::OtobusGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("Yeni Otobüs Girişi"));
    _islem->setIcon(QIcon(":/Resimler/Otobus.png"));
    _islem->setIconText("Yeni Otobüs Girişi");
    connect(_islem, &QAction::triggered, this, &OtobusGirisIslemi::main);
}


void OtobusGirisIslemi::main()
{
    auto veri = Data::d1().otobusler().yeniNesne();
    OtobusGirisFormu *form = new OtobusGirisFormu();
    connect(form,&OtobusGirisFormu::veriKaydet, this, &OtobusGirisIslemi::depoEkle);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->setVeri(veri);
    form->show();
}

QAction *OtobusGirisIslemi::islem()
{
    return _islem;
}

void OtobusGirisIslemi::depoEkle()
{
    OtobusGirisFormu *frmx =dynamic_cast<OtobusGirisFormu *>(sender());
    auto veri = frmx->veri();
    Data::d1().otobusler().nesneEkle(veri);
    frmx->close();
}
