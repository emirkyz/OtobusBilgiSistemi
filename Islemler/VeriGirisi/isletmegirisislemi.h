#ifndef ISLETMEGIRISISLEMI_H
#define ISLETMEGIRISISLEMI_H

#include <QObject>
#include <Islemler/TemelKullaniciIslemi.h>

class IsletmeGirisIslemi : public QObject, public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit IsletmeGirisIslemi(QObject *parent = nullptr);

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

#endif // ISLETMEGIRISISLEMI_H
