#include "yolcudeposu.h"

YolcuDeposu::YolcuDeposu(QObject *parent)
    : QObject{parent}, TemelVeriDeposu<Yolcubilgileri>{}
{

}
