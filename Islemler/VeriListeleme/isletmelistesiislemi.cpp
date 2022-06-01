#include "isletmelistesiislemi.h"
#include <Veri/data.h>
#include <Formlar/ListeFormlari/isletmelistesi.h>
IsletmeListesiIslemi::IsletmeListesiIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction;
    _islem->setText(tr("İşletme Listesi"));
    _islem->setIcon(QIcon(":/Resimler/YeniBilet.png"));
    _islem->setIconText(tr("İşletme Listesi"));
    connect(_islem, &QAction::triggered, this, &IsletmeListesiIslemi::main);
}

QAction *IsletmeListesiIslemi::islem()
{
    return _islem;
}

void IsletmeListesiIslemi::main()
{
    auto veri = Data::d1().isletmeler().tumunuBul([](std::shared_ptr<IsletmeBilgileri>){
        return true;
    });
    IsletmeListesi *form = new IsletmeListesi(Data::d1().isletmeler());
    form->setListe(veri);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}
