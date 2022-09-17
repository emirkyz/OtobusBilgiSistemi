#include "isletmedeposu.h"

IsletmeDeposu::IsletmeDeposu(QObject *parent)
    : QObject{parent} , TemelVeriDeposu<IsletmeBilgileri>{}{

}
QDataStream &operator<<(QDataStream &stream, const IsletmeDeposu &veri){
    stream << veri._sonId;
    stream << veri._veriler;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, IsletmeDeposu &veri){
    stream >> veri._sonId;
    stream >> veri._veriler;
    return stream;

}
