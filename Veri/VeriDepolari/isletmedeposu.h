#ifndef ISLETMEDEPOSU_H
#define ISLETMEDEPOSU_H

#include <QObject>
#include "TemelVeriDeposu.h"
#include <Veri/VeriSiniflari/isletmebilgileri.h>

class IsletmeDeposu : public QObject, public TemelVeriDeposu<IsletmeBilgileri>{
    Q_OBJECT
public:
    explicit IsletmeDeposu(QObject *parent = nullptr);

signals:

};

#endif // ISLETMEDEPOSU_H
