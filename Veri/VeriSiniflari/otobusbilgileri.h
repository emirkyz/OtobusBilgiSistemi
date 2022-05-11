#ifndef OTOBUSBILGILERI_H
#define OTOBUSBILGILERI_H

#include "temelverisinifi.h"

class OtobusBilgileri : public temelverisinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(Metin Model READ Model WRITE setModel NOTIFY ModelChanged)
    Q_PROPERTY(Tamsayi Kapasite READ Kapasite WRITE setKapasite NOTIFY KapasiteChanged)
    Q_PROPERTY(Metin Renk READ Renk WRITE setRenk NOTIFY RenkChanged)
    Q_PROPERTY(Metin Boyut READ Boyut WRITE setBoyut NOTIFY BoyutChanged)
    Q_PROPERTY(Metin OturmaDuzeni READ OturmaDuzeni WRITE setOturmaDuzeni NOTIFY OturmaDuzeniChanged)
    Q_PROPERTY(Metin Plaka READ Plaka WRITE setPlaka NOTIFY PlakaChanged)
    Q_PROPERTY(Tamsayi SoforID READ SoforID WRITE setSoforID NOTIFY SoforIDChanged)
    Q_PROPERTY(Tamsayi SeferID READ SeferID WRITE setSeferID NOTIFY SeferIDChanged)

    explicit OtobusBilgileri(QObject *parent = nullptr);

    const Metin &Model() const;
    Tamsayi Kapasite() const;
    const Metin &Renk() const;
    const Metin &Boyut() const;
    const Metin &OturmaDuzeni() const;
    const Metin &Plaka() const;
    Tamsayi SoforID() const;
    Tamsayi SeferID() const;

public slots:
    void setModel(const Metin &newModel);
    void setKapasite(Tamsayi newKapasite);
    void setRenk(const Metin &newRenk);
    void setBoyut(const Metin &newBoyut);
    void setOturmaDuzeni(const Metin &newOturmaDuzeni);
    void setPlaka(const Metin &newPlaka);
    void setSoforID(Tamsayi newSoforID);
    void setSeferID(Tamsayi newSeferID);
signals:
    void ModelChanged(const Metin &newModel);

    void KapasiteChanged(Tamsayi newKapasite);

    void RenkChanged(const Metin &newRenk);

    void BoyutChanged(const Metin &newBoyut);

    void OturmaDuzeniChanged(const Metin &newOturmaDuzeni);

    void PlakaChanged(const Metin &newPlaka);

    void SoforIDChanged(Tamsayi newSoforID);

    void SeferIDChanged(Tamsayi newSeferID);

private:
    Metin _Model;
    Tamsayi _Kapasite;
    Metin _Renk;
    Metin _Boyut;
    Metin _OturmaDuzeni;
    Metin _Plaka;
    Tamsayi _SoforID;
    Tamsayi _SeferID;

};

#endif // OTOBUSBILGILERI_H
