#ifndef OTOBUSDEPOSU_H
#define OTOBUSDEPOSU_H

#include <QObject>
#include "TemelVeriDeposu.h"
#include <Veri/VeriSiniflari/otobusbilgileri.h>

class OtobusDeposu : public QObject, public TemelVeriDeposu<OtobusBilgileri>{
    Q_OBJECT
public:
    explicit OtobusDeposu(QObject *parent = nullptr);

signals:

};

#endif // OTOBUSDEPOSU_H
