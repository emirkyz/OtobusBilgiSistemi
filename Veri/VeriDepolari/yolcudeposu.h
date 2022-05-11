#ifndef YOLCUDEPOSU_H
#define YOLCUDEPOSU_H

#include <QObject>
#include "TemelVeriDeposu.h"
#include <Veri/VeriSiniflari/yolcubilgileri.h>

class YolcuDeposu : public QObject, public TemelVeriDeposu<Yolcubilgileri>{
    Q_OBJECT
public:
    explicit YolcuDeposu(QObject *parent = nullptr);

signals:

};

#endif // YOLCUDEPOSU_H
