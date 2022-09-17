#include "seyehatkurallari.h"

Seyehatkurallari::Seyehatkurallari(QObject *parent)
    : temelverisinifi{parent}
{

}

const Metin &Seyehatkurallari::Kural() const
{
    return _Kural;
}

void Seyehatkurallari::setKural(const Metin &newKural)
{
    if (_Kural == newKural)
        return;
    _Kural = newKural;
    emit KuralChanged(_Kural);
}

Tamsayi Seyehatkurallari::SeferID() const
{
    return _SeferID;
}

void Seyehatkurallari::setSeferID(Tamsayi newSeferID)
{
    if (_SeferID == newSeferID)
        return;
    _SeferID = newSeferID;
    emit SeferIDChanged(_SeferID);
}
QDataStream &operator<<(QDataStream &stream, const Seyehatkurallari &veri){
    stream << veri._id;
    stream << veri._silindiMi;
    stream << veri._Kural;
    stream << veri._SeferID;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, Seyehatkurallari &veri){
    stream >> veri._id;
    stream >> veri._silindiMi;
    stream >> veri._Kural;
    stream >> veri._SeferID;
    return stream;
}
