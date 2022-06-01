#include "seferlistelemeislemi.h"
#include <Veri/data.h>
#include <Formlar/ListeFormlari/seferlistesi.h>
SeferListelemeIslemi::SeferListelemeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction;
    _islem->setText(tr("Sefer Listesi"));
    _islem->setIcon(QIcon(":/Resimler/YeniBilet.png"));
    _islem->setIconText(tr("Sefer Listesi"));
    connect(_islem, &QAction::triggered, this, &SeferListelemeIslemi::main);
}

QAction *SeferListelemeIslemi::islem()
{
    return _islem;
}

void SeferListelemeIslemi::main()
{
    auto veri = Data::d1().seferler().tumunuBul([](std::shared_ptr<Seferbilgileri>){
        return true;
    });
    SeferListesi *form = new SeferListesi(Data::d1().seferler());
    form->setListe(veri);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}
