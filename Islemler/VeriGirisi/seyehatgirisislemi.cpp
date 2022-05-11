#include "seyehatgirisislemi.h"
#include <Veri/data.h>
#include <Formlar/VeriFormlari/seyehatverigirisformu.h>
SeyehatGirisIslemi::SeyehatGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("Yeni Seyehat Girişi"));
    _islem->setIcon(QIcon(":/Resimler/Seyehat.png"));
    _islem->setIconText(tr("Yeni Seyehat Girişi"));
    connect(_islem, &QAction::triggered, this, &SeyehatGirisIslemi::main);

}


void SeyehatGirisIslemi::main()
{
    auto veri = Data::d1().seyehatler().yeniNesne();
    SeyehatVeriGirisFormu *form = new SeyehatVeriGirisFormu;
    connect(form, &SeyehatVeriGirisFormu::veriKaydet,this, &SeyehatGirisIslemi::depoEkle);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->setVeri(veri);
    form->show();
}

QAction *SeyehatGirisIslemi::islem()
{
    return _islem;
}

void SeyehatGirisIslemi::depoEkle()
{
    SeyehatVeriGirisFormu *frmx=dynamic_cast<SeyehatVeriGirisFormu *>(sender());
    auto veri = frmx->veri();
    Data::d1().seyehatler().nesneEkle(veri);
    frmx->close();
}
