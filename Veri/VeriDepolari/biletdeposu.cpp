#include "biletdeposu.h"

BiletDeposu::BiletDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<Biletbilgileri>{}
{

}
QDataStream &operator<<(QDataStream &stream, const BiletDeposu &veri){
    stream << veri._veriler;
    stream << veri._sonId;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, BiletDeposu &veri){
    stream >> veri._veriler;
    stream >> veri._sonId;
    return stream;
}
