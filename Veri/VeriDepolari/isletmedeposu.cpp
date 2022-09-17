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
<<<<<<< HEAD

=======
>>>>>>> 7f78d91219ebfbbc0b73569f7f2d25b13014eeb5
}
