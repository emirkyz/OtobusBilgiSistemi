#ifndef SOFORBILGILERI_H
#define SOFORBILGILERI_H

#include "insan.h"

class Soforbilgileri : public insan
{
    Q_OBJECT
public:
    Q_PROPERTY(Metin EhliyetSinifi READ EhliyetSinifi WRITE setEhliyetSinifi NOTIFY EhliyetSinifiChanged)
    Q_PROPERTY(Metin OtobusPlakasi READ OtobusPlakasi WRITE setOtobusPlakasi NOTIFY OtobusPlakasiChanged)
    Q_PROPERTY(Tamsayi TecrubeSuresi READ TecrubeSuresi WRITE setTecrubeSuresi NOTIFY TecrubeSuresiChanged)
    Q_PROPERTY(Tamsayi OtobusID READ OtobusID WRITE setOtobusID NOTIFY OtobusIDChanged)
    Q_PROPERTY(Tamsayi IsletmeID READ IsletmeID WRITE setIsletmeID NOTIFY IsletmeIDChanged)
    Q_PROPERTY(Tamsayi SeferID READ SeferID WRITE setSeferID NOTIFY SeferIDChanged)
    explicit Soforbilgileri(QObject *parent = nullptr);

    const Metin &EhliyetSinifi() const;

    const Metin &OtobusPlakasi() const;

    Tamsayi TecrubeSuresi() const;

    Tamsayi OtobusID() const;

    Tamsayi IsletmeID() const;

    Tamsayi SeferID() const;

public slots:
    void setEhliyetSinifi(const Metin &newEhliyetSinifi);
    void setOtobusPlakasi(const Metin &newOtobusPlakasi);
    void setTecrubeSuresi(Tamsayi newTecrubeSuresi);
    void setOtobusID(Tamsayi newOtobusID);
    void setIsletmeID(Tamsayi newIsletmeID);
    void setSeferID(Tamsayi newSeferID);
signals:
    void EhliyetSinifiChanged(const Metin &newEhliyetSinifi);
    void OtobusPlakasiChanged(const Metin &newOtobusPlakasi);
    void TecrubeSuresiChanged(Tamsayi newTecrubeSuresi);
    void OtobusIDChanged(Tamsayi newOtobusID);

    void IsletmeIDChanged(Tamsayi newIsletmeID);

    void SeferIDChanged(Tamsayi newSeferID);

private:

    Metin _EhliyetSinifi;
    Metin _OtobusPlakasi;
    Tamsayi _TecrubeSuresi = 0;
    Tamsayi _OtobusID;
    Tamsayi _IsletmeID;
    Tamsayi _SeferID;

    friend QDataStream &operator<<(QDataStream &stream, const Soforbilgileri &veri);
    friend QDataStream &operator>>(QDataStream &stream, Soforbilgileri &veri);


};
QDataStream &operator<<(QDataStream &stream, const Soforbilgileri &veri);
QDataStream &operator>>(QDataStream &stream, Soforbilgileri &veri);

#endif // SOFORBILGILERI_H
