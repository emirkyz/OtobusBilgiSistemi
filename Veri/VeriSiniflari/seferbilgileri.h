#ifndef SEFERBILGILERI_H
#define SEFERBILGILERI_H

#include "temelverisinifi.h"

class Seferbilgileri : public temelverisinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(Metin SeferUzunluk READ SeferUzunluk WRITE setSeferUzunluk NOTIFY SeferUzunlukChanged)
    Q_PROPERTY(Tamsayi MolaSayisi READ MolaSayisi WRITE setMolaSayisi NOTIFY MolaSayisiChanged)
    Q_PROPERTY(Tamsayi Mesafe READ Mesafe WRITE setMesafe NOTIFY MesafeChanged)
    Q_PROPERTY(Metin VarisNoktasi READ VarisNoktasi WRITE setVarisNoktasi NOTIFY VarisNoktasiChanged)
    Q_PROPERTY(Metin BaslangicNoktasi READ BaslangicNoktasi WRITE setBaslangicNoktasi NOTIFY BaslangicNoktasiChanged)
    Q_PROPERTY(Tamsayi OtobusID READ OtobusID WRITE setOtobusID NOTIFY OtobusIDChanged)

    explicit Seferbilgileri(QObject *parent = nullptr);

    const Metin &SeferUzunluk() const;

    Tamsayi Mesafe() const;

    const Metin &VarisNoktasi() const;

    const Metin &BaslangicNoktasi() const;

    Tamsayi OtobusID() const;

    Tamsayi MolaSayisi() const;


public slots:
    void setSeferUzunluk(const Metin &newSeferUzunluk);
    void setMolaSayisi(Tamsayi newMolaSayisi);
    void setMesafe(Tamsayi newMesafe);
    void setVarisNoktasi(const Metin &newVarisNoktasi);
    void setBaslangicNoktasi(const Metin &newBaslangicNoktasi);
    void setOtobusID(Tamsayi newOtobusID);

signals:
    void SeferUzunlukChanged(const Metin &newSeferUzunluk);
    void MesafeChanged(Tamsayi newMesafe);
    void VarisNoktasiChanged(const Metin &newVarisNoktasi);
    void BaslangicNoktasiChanged(const Metin &newBaslangicNoktasi);
    void OtobusIDChanged(Tamsayi newOtobusID);    
    void MolaSayisiChanged(Tamsayi newMolaSayisi);

private:
    Metin _SeferUzunluk;
    Tamsayi _MolaSayisi = 0;
    Tamsayi _Mesafe = 0;
    Metin _VarisNoktasi;
    Metin _BaslangicNoktasi;
    Tamsayi _OtobusID;
    friend QDataStream &operator<<(QDataStream &stream, const Seferbilgileri &veri);
    friend QDataStream &operator>>(QDataStream &stream, Seferbilgileri &veri);

};
QDataStream &operator<<(QDataStream &stream, const Seferbilgileri &veri);
QDataStream &operator>>(QDataStream &stream, Seferbilgileri &veri);

#endif // SEFERBILGILERI_H
