#include "isletmegirisislemi.h"
#include <Veri/data.h>
#include <Formlar/VeriFormlari/isletmeverigirisformu.h>


IsletmeGirisIslemi::IsletmeGirisIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    _islem->setText(tr("Yeni İşletme Girişi"));
    _islem->setIcon(QIcon(":/Resimler/YeniIsletme.png"));
    _islem->setIconText("Yeni İşletme Girişi");
    _islem->setIconVisibleInMenu(true);
    connect(_islem, &QAction::triggered, this , &IsletmeGirisIslemi::main);
}
void IsletmeGirisIslemi::main(){

    auto veri = Data::d1().isletmeler().yeniNesne();
    IsletmeVeriGirisFormu *form = new IsletmeVeriGirisFormu();
    connect(form,&IsletmeVeriGirisFormu::veriKaydet, this, &IsletmeGirisIslemi::depoEkle );
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->setVeri(veri);
    form->show();
}

QAction *IsletmeGirisIslemi::islem(){
    return _islem;
}

void IsletmeGirisIslemi::depoEkle()
{
    IsletmeVeriGirisFormu *frmx=dynamic_cast<IsletmeVeriGirisFormu *>(sender());
    auto veri = frmx->veri();
    Data::d1().isletmeler().nesneEkle(veri);
    frmx->close();

}
