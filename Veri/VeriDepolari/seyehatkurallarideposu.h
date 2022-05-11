#ifndef SEYEHATKURALLARIDEPOSU_H
#define SEYEHATKURALLARIDEPOSU_H

#include <QObject>
#include "TemelVeriDeposu.h"
#include <Veri/VeriSiniflari/seyehatkurallari.h>
class SeyehatKurallariDeposu : public QObject, public TemelVeriDeposu<Seyehatkurallari>{
    Q_OBJECT
public:
    explicit SeyehatKurallariDeposu(QObject *parent = nullptr);

signals:

};

#endif // SEYEHATKURALLARIDEPOSU_H
