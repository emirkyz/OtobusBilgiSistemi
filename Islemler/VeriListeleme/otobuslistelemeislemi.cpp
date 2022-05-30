#include "otobuslistelemeislemi.h"
#include <Veri/data.h>
#include <Formlar/ListeFormlari/otobuslistesi.h>
OtobusListelemeIslemi::OtobusListelemeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction;
    _islem->setText(tr("Otobus Listesi"));
    _islem->setIcon(QIcon(":/Resimler/YeniBilet.png"));
    _islem->setIconText(tr("Otobus Listesi"));
    connect(_islem, &QAction::triggered, this, &OtobusListelemeIslemi::main);
}

QAction *OtobusListelemeIslemi::islem()
{
    return _islem;
}

void OtobusListelemeIslemi::qMain()
{
    auto veri = Data::d1().otobusler().tumunuBul([](std::shared_ptr<OtobusBilgileri>){
        return true;
    });
    OtobusListesi *form = new OtobusListesi(Data::d1().otobusler());
    form->setListe(veri);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}
