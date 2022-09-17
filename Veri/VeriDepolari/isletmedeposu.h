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
private:
    friend QDataStream &operator<<(QDataStream &stream, const IsletmeDeposu &veri);
    friend QDataStream &operator>>(QDataStream &stream, IsletmeDeposu &veri);

};
QDataStream &operator<<(QDataStream &stream, const IsletmeDeposu &veri);
QDataStream &operator>>(QDataStream &stream, IsletmeDeposu &veri);

#endif // ISLETMEDEPOSU_H
