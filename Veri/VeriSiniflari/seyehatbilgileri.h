#ifndef SEYEHATBILGILERI_H
#define SEYEHATBILGILERI_H

#include "temelverisinifi.h"

class Seyehatbilgileri : public temelverisinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(Tarih SeyehatTarihi READ SeyehatTarihi WRITE setSeyehatTarihi NOTIFY SeyehatTarihiChanged)
    Q_PROPERTY(Tamsayi SeferId READ SeferId WRITE setSeferId NOTIFY SeferIdChanged)
    Q_PROPERTY(Tamsayi OtobusId READ OtobusId WRITE setOtobusId NOTIFY OtobusIdChanged)
    Q_PROPERTY(Saat SeyehatSaati READ SeyehatSaati WRITE setSeyehatSaati NOTIFY SeyehatSaatiChanged)

    explicit Seyehatbilgileri(QObject *parent = nullptr);

    const Tarih &SeyehatTarihi() const;
    Tamsayi SeferId() const;
    Tamsayi OtobusId() const;
    const Saat &SeyehatSaati() const;

public slots:
    void setSeyehatTarihi(const Tarih &newSeyehatTarihi);
    void setSeferId(Tamsayi newSeferId);
    void setOtobusId(Tamsayi newOtobusId);
    void setSeyehatSaati(const Saat &newSeyehatSaati);

signals:
    void SeyehatTarihiChanged(const Tarih &newSeyehatTarihi);
    void SeferIdChanged(Tamsayi newSeferId);
    void OtobusIdChanged(Tamsayi newOtobusId);
    void SeyehatSaatiChanged(const Saat &newSeyehatSaati);

private:
    Tarih _SeyehatTarihi;
    Tamsayi _SeferId;
    Tamsayi _OtobusId;
    Saat _SeyehatSaati;

};

#endif // SEYEHATBILGILERI_H
