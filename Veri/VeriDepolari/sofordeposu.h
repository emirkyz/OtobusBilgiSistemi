#ifndef SOFORDEPOSU_H
#define SOFORDEPOSU_H

#include <QObject>
#include "TemelVeriDeposu.h"
#include <Veri/VeriSiniflari/soforbilgileri.h>

class SoforDeposu : public QObject, public TemelVeriDeposu<Soforbilgileri>{
    Q_OBJECT
public:
    explicit SoforDeposu(QObject *parent = nullptr);

signals:

};

#endif // SOFORDEPOSU_H
