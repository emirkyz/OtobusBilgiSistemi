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
QDataStream &operator<<(QDataStream &stream, const Yolcubilgileri &veri){
    stream << veri._Ad;
    stream << veri._Soyad;
    stream << veri._HesKodu;
    stream << veri._TcKimlikNo;
    stream << veri._Yas;
    stream << veri._id;
    stream << veri._silindiMi;
    stream << veri._BiletID;
    stream << veri._SeferID;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, Yolcubilgileri &veri){
    stream >> veri._Ad;
    stream >> veri._Soyad;
    stream >> veri._HesKodu;
    stream >> veri._TcKimlikNo;
    stream >> veri._Yas;
    stream >> veri._id;
    stream >> veri._silindiMi;
    stream >> veri._BiletID;
    stream >> veri._SeferID;
    return stream;
}
