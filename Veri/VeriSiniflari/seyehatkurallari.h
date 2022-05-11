#ifndef SEYEHATKURALLARI_H
#define SEYEHATKURALLARI_H

#include "temelverisinifi.h"

class Seyehatkurallari : public temelverisinifi
{
    Q_OBJECT
public:
    Q_PROPERTY(Metin Kural READ Kural WRITE setKural NOTIFY KuralChanged)
    Q_PROPERTY(Tamsayi SeferID READ SeferID WRITE setSeferID NOTIFY SeferIDChanged)

    explicit Seyehatkurallari(QObject *parent = nullptr);

    const Metin &Kural() const;

    Tamsayi SeferID() const;

public slots:
    void setKural(const Metin &newKural);
    void setSeferID(Tamsayi newSeferID);
signals:
    void KuralChanged(const Metin &newKural);

    void SeferIDChanged(Tamsayi newSeferID);

private:
    Metin _Kural;
    Tamsayi _SeferID;

    };


#endif // SEYEHATKURALLARI_H
