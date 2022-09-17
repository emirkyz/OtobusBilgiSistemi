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
private:
    friend QDataStream &operator<<(QDataStream &stream, const SeyehatDeposu &veri);
    friend QDataStream &operator>>(QDataStream &stream, SeyehatDeposu &veri);

};
QDataStream &operator<<(QDataStream &stream, const SeyehatDeposu &veri);
QDataStream &operator>>(QDataStream &stream, SeyehatDeposu &veri);

#endif // SEYEHATDEPOSU_H
