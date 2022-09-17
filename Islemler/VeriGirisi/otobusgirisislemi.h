#ifndef OTOBUSGIRISISLEMI_H
#define OTOBUSGIRISISLEMI_H

#include <QObject>
#include "../tumkullaniciislemleri.h"

class OtobusGirisIslemi : public QObject, public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit OtobusGirisIslemi(QObject *parent = nullptr);

signals:


    // TemelKullaniciIslemi interface
public:

    QAction *islem() override;

public slots:
    void main() override;
    void depoEkle();
private:
    QAction *_islem;

};

#endif // OTOBUSGIRISISLEMI_H
