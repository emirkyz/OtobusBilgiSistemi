#include "soforbilgileri.h"

Soforbilgileri::Soforbilgileri(QObject *parent)
    : insan{parent}
{

}

const Metin &Soforbilgileri::EhliyetSinifi() const
{
    return _EhliyetSinifi;
}

void Soforbilgileri::setEhliyetSinifi(const Metin &newEhliyetSinifi)
{
    if (_EhliyetSinifi == newEhliyetSinifi)
        return;
    _EhliyetSinifi = newEhliyetSinifi;
    emit EhliyetSinifiChanged(_EhliyetSinifi);
}

const Metin &Soforbilgileri::OtobusPlakasi() const
{
    return _OtobusPlakasi;
}

void Soforbilgileri::setOtobusPlakasi(const Metin &newOtobusPlakasi)
{
    if (_OtobusPlakasi == newOtobusPlakasi)
        return;
    _OtobusPlakasi = newOtobusPlakasi;
    emit OtobusPlakasiChanged(_OtobusPlakasi);
}

Tamsayi Soforbilgileri::TecrubeSuresi() const
{
    return _TecrubeSuresi;
}

void Soforbilgileri::setTecrubeSuresi(Tamsayi newTecrubeSuresi)
{
    if (_TecrubeSuresi == newTecrubeSuresi)
        return;
    _TecrubeSuresi = newTecrubeSuresi;
    emit TecrubeSuresiChanged(_TecrubeSuresi);
}

Tamsayi Soforbilgileri::OtobusID() const
{
    return _OtobusID;
}

void Soforbilgileri::setOtobusID(Tamsayi newOtobusID)
{
    if (_OtobusID == newOtobusID)
        return;
    _OtobusID = newOtobusID;
    emit OtobusIDChanged(_OtobusID);
}

Tamsayi Soforbilgileri::IsletmeID() const
{
    return _IsletmeID;
}

void Soforbilgileri::setIsletmeID(Tamsayi newIsletmeID)
{
    if (_IsletmeID == newIsletmeID)
        return;
    _IsletmeID = newIsletmeID;
    emit IsletmeIDChanged(_IsletmeID);
}

Tamsayi Soforbilgileri::SeferID() const
{
    return _SeferID;
}

void Soforbilgileri::setSeferID(Tamsayi newSeferID)
{
    if (_SeferID == newSeferID)
        return;
    _SeferID = newSeferID;
    emit SeferIDChanged(_SeferID);
}
QDataStream &operator<<(QDataStream &stream, const Soforbilgileri &veri){
    stream << veri._Ad;
    stream << veri._Soyad;
    stream << veri._HesKodu;
    stream << veri._TcKimlikNo;
    stream << veri._Yas;
    stream << veri._id;
    stream << veri._silindiMi;
    stream << veri._EhliyetSinifi;
    stream << veri._OtobusPlakasi;
    stream << veri._TecrubeSuresi;
    stream << veri._SeferID;
    stream << veri._IsletmeID;
    stream << veri._OtobusID;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, Soforbilgileri &veri){
    stream >> veri._Ad;
    stream >> veri._Soyad;
    stream >> veri._HesKodu;
    stream >> veri._TcKimlikNo;
    stream >> veri._Yas;
    stream >> veri._id;
    stream >> veri._silindiMi;
    stream >> veri._EhliyetSinifi;
    stream >> veri._OtobusPlakasi;
    stream >> veri._TecrubeSuresi;
    stream >> veri._SeferID;
    stream >> veri._IsletmeID;
    stream >> veri._OtobusID;
    return stream;
}
