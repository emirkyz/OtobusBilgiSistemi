#include "sofordeposu.h"

SoforDeposu::SoforDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<Soforbilgileri>{}{}
