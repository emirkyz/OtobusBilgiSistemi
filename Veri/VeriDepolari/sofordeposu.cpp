#include "sofordeposu.h"

SoforDeposu::SoforDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<Soforbilgileri>{}{}
QDataStream &operator<<(QDataStream &stream, const SoforDeposu &veri){
    stream << veri._veriler;
    stream << veri._sonId;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, SoforDeposu &veri){
    stream >> veri._veriler;
    stream >> veri._sonId;
    return stream;
}
