#ifndef BILETDEPOSU_H
#define BILETDEPOSU_H

#include <QObject>
#include "TemelVeriDeposu.h"
#include <Veri/VeriSiniflari/biletbilgileri.h>

class BiletDeposu : public QObject , public TemelVeriDeposu<Biletbilgileri>
{
    Q_OBJECT
public:
    explicit BiletDeposu(QObject *parent = nullptr);

signals:

};

#endif // BILETDEPOSU_H
