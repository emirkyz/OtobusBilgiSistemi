#ifndef ISLETMEBILGILERI_H
#define ISLETMEBILGILERI_H
#include <Veri/VeriSiniflari/insan.h>

class IsletmeBilgileri : public insan
{
    Q_OBJECT
public:    
    Q_PROPERTY(Metin IsletmeAdi READ IsletmeAdi WRITE setIsletmeAdi NOTIFY IsletmeAdiChanged)
    Q_PROPERTY(Metin KurucuAd READ KurucuAd WRITE setKurucuAd NOTIFY KurucuAdChanged)
    Q_PROPERTY(Metin KurucuSoyad READ KurucuSoyad WRITE setKurucuSoyad NOTIFY KurucuSoyadChanged)
    Q_PROPERTY(Metin VergiNo READ VergiNo WRITE setVergiNo NOTIFY VergiNoChanged)
    Q_PROPERTY(Metin Adres READ Adres WRITE setAdres NOTIFY AdresChanged)
    explicit IsletmeBilgileri(QObject *parent = nullptr);
    const Metin &IsletmeAdi() const;
    const Metin &KurucuAd() const;
    const Metin &KurucuSoyad() const;
    const Metin &VergiNo() const;
    const Metin &Adres() const;


public slots:
    void setIsletmeAdi(const Metin &newIsletmeAdi);
    void setKurucuAd(const Metin &newKurucuAd);
    void setKurucuSoyad(const Metin &newKurucuSoyad);
    void setVergiNo(const Metin &newVergiNo);
    void setAdres(const Metin &newAdres);
signals:
    void IsletmeAdiChanged(const Metin &newIsletmeAdi);

    void KurucuAdChanged(const Metin &newKurucuAd);

    void KurucuSoyadChanged(const Metin &newKurucuSoyad);

    void VergiNoChanged(const Metin &newVergiNo);

    void AdresChanged(const Metin &newAdres);

private:
    Metin _IsletmeAdi;
    Metin _KurucuAd;
    Metin _KurucuSoyad;
    Metin _VergiNo;
    Metin _Adres;
    friend QDataStream &operator<<(QDataStream &stream, const IsletmeBilgileri &veri);
    friend QDataStream &operator>>(QDataStream &stream, IsletmeBilgileri &veri);


};
QDataStream &operator<<(QDataStream &stream, const IsletmeBilgileri &veri);
QDataStream &operator>>(QDataStream &stream, IsletmeBilgileri &veri);

#endif // ISLETMEBILGILERI_H
