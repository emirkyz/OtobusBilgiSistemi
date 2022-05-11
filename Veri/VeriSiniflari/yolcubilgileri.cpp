#include "yolcubilgileri.h"

Yolcubilgileri::Yolcubilgileri(QObject *parent)
    : insan{parent}
{

}



Tamsayi Yolcubilgileri::SeferID() const
{
    return _SeferID;
}

void Yolcubilgileri::setSeferID(Tamsayi newSeferID)
{
    if (_SeferID == newSeferID)
        return;
    _SeferID = newSeferID;
    emit SeferIDChanged(_SeferID);
}

Tamsayi Yolcubilgileri::BiletID() const
{
    return _BiletID;
}

void Yolcubilgileri::setBiletID(Tamsayi newBiletID)
{
    if (_BiletID == newBiletID)
        return;
    _BiletID = newBiletID;
    emit BiletIDChanged(_BiletID);
}
