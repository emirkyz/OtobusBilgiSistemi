#include "seferbilgileri.h"

Seferbilgileri::Seferbilgileri(QObject *parent)
    : temelverisinifi{parent}
{

}

const Metin &Seferbilgileri::SeferUzunluk() const
{
    return _SeferUzunluk;
}

void Seferbilgileri::setSeferUzunluk(const Metin &newSeferUzunluk)
{
    if (_SeferUzunluk == newSeferUzunluk)
        return;
    _SeferUzunluk = newSeferUzunluk;
    emit SeferUzunlukChanged(_SeferUzunluk);
}


Tamsayi Seferbilgileri::Mesafe() const
{
    return _Mesafe;
}

void Seferbilgileri::setMesafe(Tamsayi newMesafe)
{
    if (_Mesafe == newMesafe)
        return;
    _Mesafe = newMesafe;
    emit MesafeChanged(_Mesafe);
}

const Metin &Seferbilgileri::VarisNoktasi() const
{
    return _VarisNoktasi;
}

void Seferbilgileri::setVarisNoktasi(const Metin &newVarisNoktasi)
{
    if (_VarisNoktasi == newVarisNoktasi)
        return;
    _VarisNoktasi = newVarisNoktasi;
    emit VarisNoktasiChanged(_VarisNoktasi);
}

const Metin &Seferbilgileri::BaslangicNoktasi() const
{
    return _BaslangicNoktasi;
}

void Seferbilgileri::setBaslangicNoktasi(const Metin &newBaslangicNoktasi)
{
    if (_BaslangicNoktasi == newBaslangicNoktasi)
        return;
    _BaslangicNoktasi = newBaslangicNoktasi;
    emit BaslangicNoktasiChanged(_BaslangicNoktasi);
}

Tamsayi Seferbilgileri::OtobusID() const
{
    return _OtobusID;
}

void Seferbilgileri::setOtobusID(Tamsayi newOtobusID)
{
    if (_OtobusID == newOtobusID)
        return;
    _OtobusID = newOtobusID;
    emit OtobusIDChanged(_OtobusID);
}

Tamsayi Seferbilgileri::MolaSayisi() const
{
    return _MolaSayisi;
}

void Seferbilgileri::setMolaSayisi(Tamsayi newMolaSayisi)
{
    if (_MolaSayisi == newMolaSayisi)
        return;
    _MolaSayisi = newMolaSayisi;
    emit MolaSayisiChanged(_MolaSayisi);
}
