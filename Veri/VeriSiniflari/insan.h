#ifndef INSAN_H
#define INSAN_H

#include "temelverisinifi.h"

class insan : public temelverisinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(Metin Ad READ Ad WRITE setAd NOTIFY AdChanged)
    Q_PROPERTY(Metin Soyad READ Soyad WRITE setSoyad NOTIFY SoyadChanged)
    Q_PROPERTY(Tamsayi Yas READ Yas WRITE setYas NOTIFY YasChanged)
    Q_PROPERTY(Metin TcKimlikNo READ TcKimlikNo WRITE setTcKimlikNo NOTIFY TcKimlikNoChanged)
    Q_PROPERTY(Metin HesKodu READ HesKodu WRITE setHesKodu NOTIFY HesKoduChanged)
    explicit insan(QObject *parent = nullptr);


    const Metin &Ad() const;
    const Metin &Soyad() const;
    Tamsayi Yas() const;
    const Metin &TcKimlikNo() const;
    const Metin &HesKodu() const;

public slots:
    void setAd(const Metin &newAd);
    void setYas(Tamsayi newYas);
    void setSoyad(const Metin &newSoyad);
    void setTcKimlikNo(const Metin &newTcKimlikNo);
    void setHesKodu(const Metin &newHesKodu);

signals:
    void AdChanged(const Metin &newAd);

    void SoyadChanged(const Metin &newSoyad);

    void YasChanged(Tamsayi newYas);

    void TcKimlikNoChanged(const Metin &newTcKimlikNo);

    void HesKoduChanged(const Metin &newHesKodu);

protected:
    Metin _Ad;
    Metin _Soyad;
    Tamsayi _Yas = 0;
    Metin _TcKimlikNo;
    Metin _HesKodu;

};

#endif // INSAN_H
