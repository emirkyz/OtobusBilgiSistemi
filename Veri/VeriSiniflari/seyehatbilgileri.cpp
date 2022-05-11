#include "seyehatbilgileri.h"

Seyehatbilgileri::Seyehatbilgileri(QObject *parent)
    : temelverisinifi{parent}
{

}

const Tarih &Seyehatbilgileri::SeyehatTarihi() const
{
    return _SeyehatTarihi;
}

void Seyehatbilgileri::setSeyehatTarihi(const Tarih &newSeyehatTarihi)
{
    if (_SeyehatTarihi == newSeyehatTarihi)
        return;
    _SeyehatTarihi = newSeyehatTarihi;
    emit SeyehatTarihiChanged(_SeyehatTarihi);
}

Tamsayi Seyehatbilgileri::SeferId() const
{
    return _SeferId;
}

void Seyehatbilgileri::setSeferId(Tamsayi newSeferId)
{
    if (_SeferId == newSeferId)
        return;
    _SeferId = newSeferId;
    emit SeferIdChanged(_SeferId);
}

Tamsayi Seyehatbilgileri::OtobusId() const
{
    return _OtobusId;
}

void Seyehatbilgileri::setOtobusId(Tamsayi newOtobusId)
{
    if (_OtobusId == newOtobusId)
        return;
    _OtobusId = newOtobusId;
    emit OtobusIdChanged(_OtobusId);
}

const Saat &Seyehatbilgileri::SeyehatSaati() const
{
    return _SeyehatSaati;
}

void Seyehatbilgileri::setSeyehatSaati(const Saat &newSeyehatSaati)
{
    if (_SeyehatSaati == newSeyehatSaati)
        return;
    _SeyehatSaati = newSeyehatSaati;
    emit SeyehatSaatiChanged(_SeyehatSaati);
}
