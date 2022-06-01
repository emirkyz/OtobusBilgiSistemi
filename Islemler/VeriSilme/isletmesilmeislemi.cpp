#include "isletmesilmeislemi.h"
#include <Veri/data.h>
#include <QMessageBox>
IsletmeSilmeIslemi::IsletmeSilmeIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction();
    connect(_islem, &QAction::triggered,this, &IsletmeSilmeIslemi::main  );
}


void IsletmeSilmeIslemi::main()
{
    auto cevap = QMessageBox::question
        (nullptr,tr("İşletme Silme Onayı"),tr("%1 İsimli İşletmeyi silmek istediğinizden eminmisiniz?").arg(_veri->IsletmeAdi()));

    if(cevap==QMessageBox::Yes){
        Data::d1().isletmeler().nesneSil(_veri);
    }


}

QAction *IsletmeSilmeIslemi::islem()
{
    return _islem;
}

const IsletmeBilgileriPtr &IsletmeSilmeIslemi::veri() const
{
    return _veri;
}

void IsletmeSilmeIslemi::setVeri(const IsletmeBilgileriPtr &newVeri)
{
    _veri = newVeri;
}
