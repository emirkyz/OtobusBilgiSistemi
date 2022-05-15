#include "soforgirisislemi.h"
#include "Veri/data.h"
#include <Formlar/VeriFormlari/soforverigirisformu.h>

SoforGirisIslemi::SoforGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction;
    _islem->setText(tr("Yeni Sofor Girişi"));
    _islem->setIcon(QIcon(":/Resimler/YeniSofor.png"));
    _islem->setIconText("Yeni Sofor Girişi");
    connect(_islem,&QAction::triggered, this, &SoforGirisIslemi::main);
}


void SoforGirisIslemi::main()
{
    auto veri=Data::d1().soforler().yeniNesne();
    SoforVeriGirisFormu *form = new SoforVeriGirisFormu;
    connect(form, &SoforVeriGirisFormu::veriKaydet,this, &SoforGirisIslemi::depoEkle );
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->setVeri(veri);
    form->show();
}

QAction *SoforGirisIslemi::islem()
{
    return _islem;
}

void SoforGirisIslemi::depoEkle()
{
    SoforVeriGirisFormu *frmx = dynamic_cast<SoforVeriGirisFormu *>(sender());
    auto veri = frmx->veri();
    Data::d1().soforler().nesneEkle(veri);
    frmx->close();
}
