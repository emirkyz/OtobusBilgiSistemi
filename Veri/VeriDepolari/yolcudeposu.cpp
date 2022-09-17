#include "yolcudeposu.h"

YolcuDeposu::YolcuDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<Yolcubilgileri>{}
{

}
QDataStream &operator<<(QDataStream &stream, const YolcuDeposu &veri){
    stream << veri._veriler;
    stream << veri._sonId;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, YolcuDeposu &veri){
    stream >> veri._veriler;
    stream >> veri._sonId;
    return stream;
}
