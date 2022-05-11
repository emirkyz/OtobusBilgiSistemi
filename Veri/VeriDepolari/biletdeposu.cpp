#include "biletdeposu.h"

BiletDeposu::BiletDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<Biletbilgileri>{}
{

}
