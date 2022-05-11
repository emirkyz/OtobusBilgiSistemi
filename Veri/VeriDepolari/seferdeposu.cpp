#include "seferdeposu.h"

SeferDeposu::SeferDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<Seferbilgileri>{}{}
