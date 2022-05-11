#include "otobusbilgileri.h"

OtobusBilgileri::OtobusBilgileri(QObject *parent)
    : temelverisinifi{parent}
{

}

const Metin &OtobusBilgileri::Model() const
{
    return _Model;
}

void OtobusBilgileri::setModel(const Metin &newModel)
{
    if (_Model == newModel)
        return;
    _Model = newModel;
    emit ModelChanged(_Model);
}

Tamsayi OtobusBilgileri::Kapasite() const
{
    return _Kapasite;
}

void OtobusBilgileri::setKapasite(Tamsayi newKapasite)
{
    if (_Kapasite == newKapasite)
        return;
    _Kapasite = newKapasite;
    emit KapasiteChanged(_Kapasite);
}

const Metin &OtobusBilgileri::Renk() const
{
    return _Renk;
}

void OtobusBilgileri::setRenk(const Metin &newRenk)
{
    if (_Renk == newRenk)
        return;
    _Renk = newRenk;
    emit RenkChanged(_Renk);
}

const Metin &OtobusBilgileri::Boyut() const
{
    return _Boyut;
}

void OtobusBilgileri::setBoyut(const Metin &newBoyut)
{
    if (_Boyut == newBoyut)
        return;
    _Boyut = newBoyut;
    emit BoyutChanged(_Boyut);
}

const Metin &OtobusBilgileri::OturmaDuzeni() const
{
    return _OturmaDuzeni;
}

void OtobusBilgileri::setOturmaDuzeni(const Metin &newOturmaDuzeni)
{
    if (_OturmaDuzeni == newOturmaDuzeni)
        return;
    _OturmaDuzeni = newOturmaDuzeni;
    emit OturmaDuzeniChanged(_OturmaDuzeni);
}

const Metin &OtobusBilgileri::Plaka() const
{
    return _Plaka;
}

void OtobusBilgileri::setPlaka(const Metin &newPlaka)
{
    if (_Plaka == newPlaka)
        return;
    _Plaka = newPlaka;
    emit PlakaChanged(_Plaka);
}

Tamsayi OtobusBilgileri::SoforID() const
{
    return _SoforID;
}

void OtobusBilgileri::setSoforID(Tamsayi newSoforID)
{
    if (_SoforID == newSoforID)
        return;
    _SoforID = newSoforID;
    emit SoforIDChanged(_SoforID);
}

Tamsayi OtobusBilgileri::SeferID() const
{
    return _SeferID;
}

void OtobusBilgileri::setSeferID(Tamsayi newSeferID)
{
    if (_SeferID == newSeferID)
        return;
    _SeferID = newSeferID;
    emit SeferIDChanged(_SeferID);
}
