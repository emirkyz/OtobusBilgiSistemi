#include "yolcugirisislemi.h"
#include <Veri/data.h>
#include <Formlar/VeriFormlari/yolcugirisformu.h>
YolcuGirisIslemi::YolcuGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction;
    _islem->setText(tr("Yeni Yolcu Girişi"));
    _islem->setIcon(QIcon(":/Resimler/YeniYolcu.png"));
    _islem->setIconText(tr("Yeni Yolcu Girişi"));
    connect(_islem, &QAction::triggered, this, &YolcuGirisIslemi::main);
}


void YolcuGirisIslemi::main()
{
    auto veri = Data::d1().yolcular().yeniNesne();
    YolcuGirisFormu *form = new YolcuGirisFormu;
    connect(form, &YolcuGirisFormu::veriKaydet,this,&YolcuGirisIslemi::depoEkle);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->setVeri(veri);
    form->show();
}

QAction *YolcuGirisIslemi::islem()
{
    return _islem;
}

void YolcuGirisIslemi::depoEkle()
{
    YolcuGirisFormu *frmx = dynamic_cast<YolcuGirisFormu *>(sender());
    auto veri = frmx->veri();
    Data::d1().yolcular().nesneEkle(veri);
    frmx->close();
}
