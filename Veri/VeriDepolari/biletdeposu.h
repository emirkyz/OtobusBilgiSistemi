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
private:
    friend QDataStream &operator<<(QDataStream &stream, const BiletDeposu &veri);
    friend QDataStream &operator>>(QDataStream &stream, BiletDeposu &veri);

};
QDataStream &operator<<(QDataStream &stream, const BiletDeposu &veri);
QDataStream &operator>>(QDataStream &stream, BiletDeposu &veri);

#endif // BILETDEPOSU_H
