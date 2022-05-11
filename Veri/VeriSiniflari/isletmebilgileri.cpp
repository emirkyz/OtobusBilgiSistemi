#include "isletmebilgileri.h"

IsletmeBilgileri::IsletmeBilgileri(QObject *parent)
    : insan{parent}
{

}

const Metin &IsletmeBilgileri::IsletmeAdi() const
{
    return _IsletmeAdi;
}

void IsletmeBilgileri::setIsletmeAdi(const Metin &newIsletmeAdi)
{
    if (_IsletmeAdi == newIsletmeAdi)
        return;
    _IsletmeAdi = newIsletmeAdi;
    emit IsletmeAdiChanged(_IsletmeAdi);
}

const Metin &IsletmeBilgileri::KurucuAd() const
{
    return _KurucuAd;
}

void IsletmeBilgileri::setKurucuAd(const Metin &newKurucuAd)
{
    if (_KurucuAd == newKurucuAd)
        return;
    _KurucuAd = newKurucuAd;
    emit KurucuAdChanged(_KurucuAd);
}

const Metin &IsletmeBilgileri::KurucuSoyad() const
{
    return _KurucuSoyad;
}

void IsletmeBilgileri::setKurucuSoyad(const Metin &newKurucuSoyad)
{
    if (_KurucuSoyad == newKurucuSoyad)
        return;
    _KurucuSoyad = newKurucuSoyad;
    emit KurucuSoyadChanged(_KurucuSoyad);
}

const Metin &IsletmeBilgileri::VergiNo() const
{
    return _VergiNo;
}

void IsletmeBilgileri::setVergiNo(const Metin &newVergiNo)
{
    if (_VergiNo == newVergiNo)
        return;
    _VergiNo = newVergiNo;
    emit VergiNoChanged(_VergiNo);
}

const Metin &IsletmeBilgileri::Adres() const
{
    return _Adres;
}

void IsletmeBilgileri::setAdres(const Metin &newAdres)
{
    if (_Adres == newAdres)
        return;
    _Adres = newAdres;
    emit AdresChanged(_Adres);
}
