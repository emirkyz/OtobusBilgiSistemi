#include "seyehatdeposu.h"

SeyehatDeposu::SeyehatDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<Seyehatbilgileri>{}
{

}
