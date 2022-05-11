#include "insan.h"

insan::insan(QObject *parent)
    : temelverisinifi{parent}
{

}

const Metin &insan::Ad() const
{
    return _Ad;
}

void insan::setAd(const Metin &newAd)
{
    if (_Ad == newAd)
        return;
    _Ad = newAd;
    emit AdChanged(_Ad);
}

const Metin &insan::Soyad() const
{
    return _Soyad;
}

void insan::setSoyad(const Metin &newSoyad)
{
    if (_Soyad == newSoyad)
        return;
    _Soyad = newSoyad;
    emit SoyadChanged(_Soyad);
}

Tamsayi insan::Yas() const
{
    return _Yas;
}

void insan::setYas(Tamsayi newYas)
{
    if (_Yas == newYas)
        return;
    _Yas = newYas;
    emit YasChanged(_Yas);
}

const Metin &insan::TcKimlikNo() const
{
    return _TcKimlikNo;
}

void insan::setTcKimlikNo(const Metin &newTcKimlikNo)
{
    if (_TcKimlikNo == newTcKimlikNo)
        return;
    _TcKimlikNo = newTcKimlikNo;
    emit TcKimlikNoChanged(_TcKimlikNo);
}

const Metin &insan::HesKodu() const
{
    return _HesKodu;
}

void insan::setHesKodu(const Metin &newHesKodu)
{
    if (_HesKodu == newHesKodu)
        return;
    _HesKodu = newHesKodu;
    emit HesKoduChanged(_HesKodu);
}

