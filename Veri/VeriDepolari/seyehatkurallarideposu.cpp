#include "seyehatkurallarideposu.h"

SeyehatKurallariDeposu::SeyehatKurallariDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<Seyehatkurallari>{}{}
