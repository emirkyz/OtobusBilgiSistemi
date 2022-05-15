#include "seyehatkurallarideposu.h"

SeyehatKurallariDeposu::SeyehatKurallariDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<Seyehatkurallari>{}{}
QDataStream &operator<<(QDataStream &stream, const SeyehatKurallariDeposu &veri){
    stream << veri._veriler;
    stream << veri._sonId;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, SeyehatKurallariDeposu &veri){
    stream >> veri._veriler;
    stream >> veri._sonId;
    return stream;
}
