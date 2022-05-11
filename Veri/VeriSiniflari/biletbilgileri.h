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

    explicit Biletbilgileri(QObject *parent = nullptr);

    Tamsayi KoltukNumarasi() const;
    Tamsayi SeyehatId() const;
    Tamsayi YolcuId() const;

public slots:
    void setKoltukNumarasi(Tamsayi newKoltukNumarasi);
    void setSeyehatId(Tamsayi newSeyehatId);
    void setYolcuId(Tamsayi newYolcuId);

signals:
    void KoltukNumarasiChanged(Tamsayi newKoltukNumarasi);
    void SeyehatIdChanged(Tamsayi newSeyehatId);
    void YolcuIdChanged(Tamsayi newYolcuId);

private:
    Tamsayi _KoltukNumarasi;
    Tamsayi _SeyehatId;
    Tamsayi _YolcuId;




};

#endif // BILETBILGILERI_H
