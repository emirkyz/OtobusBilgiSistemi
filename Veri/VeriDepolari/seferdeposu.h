#ifndef SEFERDEPOSU_H
#define SEFERDEPOSU_H

#include <QObject>
#include "TemelVeriDeposu.h"
#include <Veri/VeriSiniflari/seferbilgileri.h>
class SeferDeposu : public QObject, public TemelVeriDeposu<Seferbilgileri>{
    Q_OBJECT
public:
    explicit SeferDeposu(QObject *parent = nullptr);

signals:

};

#endif // SEFERDEPOSU_H
