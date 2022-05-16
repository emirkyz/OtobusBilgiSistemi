#include "biletbilgileri.h"

Biletbilgileri::Biletbilgileri(QObject *parent)
    : temelverisinifi{parent}
{

}

Tamsayi Biletbilgileri::KoltukNumarasi() const
{
    return _KoltukNumarasi;
}

void Biletbilgileri::setKoltukNumarasi(Tamsayi newKoltukNumarasi)
{
    if (_KoltukNumarasi == newKoltukNumarasi)
        return;
    _KoltukNumarasi = newKoltukNumarasi;
    emit KoltukNumarasiChanged(_KoltukNumarasi);
}

Tamsayi Biletbilgileri::SeyehatId() const
{
    return _SeyehatId;
}

void Biletbilgileri::setSeyehatId(Tamsayi newSeyehatId)
{
    if (_SeyehatId == newSeyehatId)
        return;
    _SeyehatId = newSeyehatId;
    emit SeyehatIdChanged(_SeyehatId);
}

Tamsayi Biletbilgileri::YolcuId() const
{
    return _YolcuId;
}

void Biletbilgileri::setYolcuId(Tamsayi newYolcuId)
{
    if (_YolcuId == newYolcuId)
        return;
    _YolcuId = newYolcuId;
    emit YolcuIdChanged(_YolcuId);
}

Tamsayi Biletbilgileri::PeronNumarasi() const
{
    return _PeronNumarasi;
}

void Biletbilgileri::setPeronNumarasi(Tamsayi newPeronNumarasi)
{
    if (_PeronNumarasi == newPeronNumarasi)
        return;
    _PeronNumarasi = newPeronNumarasi;
    emit PeronNumarasiChanged(_PeronNumarasi);
}

QDataStream &operator<<(QDataStream &stream, const Biletbilgileri &veri){
    stream << veri._id;
    stream << veri._silindiMi;
    stream << veri._KoltukNumarasi;
    stream << veri._YolcuId;
    stream << veri._SeyehatId;
    stream << veri._PeronNumarasi;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, Biletbilgileri &veri){
    stream >> veri._id;
    stream >> veri._silindiMi;
    stream >> veri._KoltukNumarasi;
    stream >> veri._YolcuId;
    stream >> veri._SeyehatId;
    stream >> veri._PeronNumarasi;
    return stream;
}
