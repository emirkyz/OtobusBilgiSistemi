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

