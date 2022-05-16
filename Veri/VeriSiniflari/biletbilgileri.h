#ifndef BILETBILGILERI_H
#define BILETBILGILERI_H

#include "temelverisinifi.h"

class Biletbilgileri : public temelverisinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(Tamsayi KoltukNumarasi READ KoltukNumarasi WRITE setKoltukNumarasi NOTIFY KoltukNumarasiChanged)
    Q_PROPERTY(Tamsayi SeyehatId READ SeyehatId WRITE setSeyehatId NOTIFY SeyehatIdChanged)
    Q_PROPERTY(Tamsayi YolcuId READ YolcuId WRITE setYolcuId NOTIFY YolcuIdChanged)
    Q_PROPERTY(Tamsayi PeronNumarasi READ PeronNumarasi WRITE setPeronNumarasi NOTIFY PeronNumarasiChanged)

    explicit Biletbilgileri(QObject *parent = nullptr);

    Tamsayi KoltukNumarasi() const;
    Tamsayi SeyehatId() const;
    Tamsayi YolcuId() const;

    Tamsayi PeronNumarasi() const;


public slots:
    void setKoltukNumarasi(Tamsayi newKoltukNumarasi);
    void setSeyehatId(Tamsayi newSeyehatId);
    void setYolcuId(Tamsayi newYolcuId);
    void setPeronNumarasi(Tamsayi newPeronNumarasi);
signals:
    void KoltukNumarasiChanged(Tamsayi newKoltukNumarasi);
    void SeyehatIdChanged(Tamsayi newSeyehatId);
    void YolcuIdChanged(Tamsayi newYolcuId);

    void PeronNumarasiChanged(Tamsayi PeronNumarasi);

private:
    Tamsayi _KoltukNumarasi = 0;
    Tamsayi _PeronNumarasi = 0;
    Tamsayi _SeyehatId;
    Tamsayi _YolcuId;

    friend QDataStream &operator<<(QDataStream &stream, const Biletbilgileri &veri);
    friend QDataStream &operator>>(QDataStream &stream, Biletbilgileri &veri);


};
QDataStream &operator<<(QDataStream &stream, const Biletbilgileri &veri);
QDataStream &operator>>(QDataStream &stream, Biletbilgileri &veri);

#endif // BILETBILGILERI_H
