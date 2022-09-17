#ifndef YOLCUBILGILERI_H
#define YOLCUBILGILERI_H

#include "insan.h"

class Yolcubilgileri : public insan
{
    Q_OBJECT
public:

    Q_PROPERTY(Tamsayi SeferID READ SeferID WRITE setSeferID NOTIFY SeferIDChanged)
    Q_PROPERTY(Tamsayi BiletID READ BiletID WRITE setBiletID NOTIFY BiletIDChanged)

    explicit Yolcubilgileri(QObject *parent = nullptr);

    Tamsayi SeferID() const;

    Tamsayi BiletID() const;

public slots:

    void setSeferID(Tamsayi newSeferID);
    void setBiletID(Tamsayi newBiletID);
signals:

    void SeferIDChanged(Tamsayi newSeferID);    
    void BiletIDChanged(Tamsayi newBiletID);

private:
    Tamsayi _BiletID;
    Tamsayi _SeferID;
    friend QDataStream &operator<<(QDataStream &stream, const Yolcubilgileri &veri);
    friend QDataStream &operator>>(QDataStream &stream, Yolcubilgileri &veri);

};
QDataStream &operator<<(QDataStream &stream, const Yolcubilgileri &veri);
QDataStream &operator>>(QDataStream &stream, Yolcubilgileri &veri);

#endif // YOLCUBILGILERI_H
