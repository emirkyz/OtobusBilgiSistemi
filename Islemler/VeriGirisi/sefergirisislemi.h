#ifndef SEFERGIRISISLEMI_H
#define SEFERGIRISISLEMI_H

#include <QObject>
#include <Islemler/TemelKullaniciIslemi.h>

class SeferGirisIslemi : public QObject, public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit SeferGirisIslemi(QObject *parent = nullptr);

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

#endif // SEFERGIRISISLEMI_H
