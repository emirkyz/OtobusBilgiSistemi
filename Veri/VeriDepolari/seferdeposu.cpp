#include "seferdeposu.h"

SeferDeposu::SeferDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<Seferbilgileri>{}{}
QDataStream &operator<<(QDataStream &stream, const SeferDeposu &veri){
    stream << veri._veriler;
    stream << veri._sonId;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, SeferDeposu &veri){
    stream >> veri._veriler;
    stream >> veri._sonId;
    return stream;
}
