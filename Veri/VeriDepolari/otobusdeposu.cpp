#include "otobusdeposu.h"

OtobusDeposu::OtobusDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<OtobusBilgileri>{}{

}
QDataStream &operator<<(QDataStream &stream, const OtobusDeposu &veri){
    stream << veri._sonId;
    stream << veri._veriler;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, OtobusDeposu &veri){
    stream >> veri._sonId;
    stream >> veri._veriler;
    return stream;
}
