#include "otobusdeposu.h"

OtobusDeposu::OtobusDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<OtobusBilgileri>{}{

}
