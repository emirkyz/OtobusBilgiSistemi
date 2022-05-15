#ifndef YOLCUDEPOSU_H
#define YOLCUDEPOSU_H

#include <QObject>
#include "TemelVeriDeposu.h"
#include <Veri/VeriSiniflari/yolcubilgileri.h>

class YolcuDeposu : public QObject, public TemelVeriDeposu<Yolcubilgileri>{
    Q_OBJECT
public:
    explicit YolcuDeposu(QObject *parent = nullptr);

signals:
private:
    friend QDataStream &operator<<(QDataStream &stream, const YolcuDeposu &veri);
    friend QDataStream &operator>>(QDataStream &stream, YolcuDeposu &veri);

};
QDataStream &operator<<(QDataStream &stream, const YolcuDeposu &veri);
QDataStream &operator>>(QDataStream &stream, YolcuDeposu &veri);

#endif // YOLCUDEPOSU_H
