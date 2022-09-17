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
private:
    friend QDataStream &operator<<(QDataStream &stream, const OtobusDeposu &veri);
    friend QDataStream &operator>>(QDataStream &stream, OtobusDeposu &veri);

};
QDataStream &operator<<(QDataStream &stream, const OtobusDeposu &veri);
QDataStream &operator>>(QDataStream &stream, OtobusDeposu &veri);

#endif // OTOBUSDEPOSU_H
