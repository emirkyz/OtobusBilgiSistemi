#include "seyehatdeposu.h"

SeyehatDeposu::SeyehatDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<Seyehatbilgileri>{}
{

}
QDataStream &operator<<(QDataStream &stream, const SeyehatDeposu &veri){
    stream << veri._veriler;
    stream << veri._sonId;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, SeyehatDeposu &veri){
    stream >> veri._veriler;
    stream >> veri._sonId;
    return stream;
}
