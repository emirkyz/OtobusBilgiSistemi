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
private:
    friend QDataStream &operator<<(QDataStream &stream, const SoforDeposu &veri);
    friend QDataStream &operator>>(QDataStream &stream, SoforDeposu &veri);

};
QDataStream &operator<<(QDataStream &stream, const SoforDeposu &veri);
QDataStream &operator>>(QDataStream &stream, SoforDeposu &veri);

#endif // SOFORDEPOSU_H
