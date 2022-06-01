#include "yolculistelemeislemi.h"
#include <Veri/data.h>
#include <Formlar/ListeFormlari/yolculistesi.h>
YolcuListelemeIslemi::YolcuListelemeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction;
    _islem->setText(tr("Yolcu Listesi"));
    _islem->setIcon(QIcon(":/Resimler/YeniBilet.png"));
    _islem->setIconText(tr("Yolcu Listesi"));
    connect(_islem, &QAction::triggered, this, &YolcuListelemeIslemi::main);
}

QAction *YolcuListelemeIslemi::islem()
{
    return _islem;
}

void YolcuListelemeIslemi::main()
{
    auto veri = Data::d1().yolcular().tumunuBul([](std::shared_ptr<Yolcubilgileri>){
        return true;
    });
    YolcuListesi *form = new YolcuListesi(Data::d1().yolcular());
    form->setListe(veri);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->show();
}


