#ifndef BILETGIRISISLEMI_H
#define BILETGIRISISLEMI_H

#include <QObject>
#include <Islemler/TemelKullaniciIslemi.h>
class BiletGirisIslemi : public QObject, public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit BiletGirisIslemi(QObject *parent = nullptr);

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

#endif // BILETGIRISISLEMI_H
