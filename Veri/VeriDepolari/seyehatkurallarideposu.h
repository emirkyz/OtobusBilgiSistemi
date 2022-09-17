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
private:
    friend QDataStream &operator<<(QDataStream &stream, const SeyehatKurallariDeposu &veri);
    friend QDataStream &operator>>(QDataStream &stream, SeyehatKurallariDeposu &veri);

};
QDataStream &operator<<(QDataStream &stream, const SeyehatKurallariDeposu &veri);
QDataStream &operator>>(QDataStream &stream, SeyehatKurallariDeposu &veri);

#endif // SEYEHATKURALLARIDEPOSU_H
