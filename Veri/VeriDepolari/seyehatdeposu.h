#ifndef SEYEHATDEPOSU_H
#define SEYEHATDEPOSU_H

#include <QObject>
#include "TemelVeriDeposu.h"
#include <Veri/VeriSiniflari/seyehatbilgileri.h>

class SeyehatDeposu : public QObject, public TemelVeriDeposu<Seyehatbilgileri>
{
    Q_OBJECT
public:
    explicit SeyehatDeposu(QObject *parent = nullptr);

signals:

};

#endif // SEYEHATDEPOSU_H
