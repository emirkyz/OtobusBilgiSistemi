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
private:
    friend QDataStream &operator<<(QDataStream &stream, const SeferDeposu &veri);
    friend QDataStream &operator>>(QDataStream &stream, SeferDeposu &veri);

};
QDataStream &operator<<(QDataStream &stream, const SeferDeposu &veri);
QDataStream &operator>>(QDataStream &stream, SeferDeposu &veri);

#endif // SEFERDEPOSU_H
