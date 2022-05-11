#include "isletmedeposu.h"

IsletmeDeposu::IsletmeDeposu(QObject *parent)
    : QObject{parent} , TemelVeriDeposu<IsletmeBilgileri>{}{

}
