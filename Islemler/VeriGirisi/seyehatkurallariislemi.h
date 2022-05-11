#ifndef SEYEHATKURALLARIISLEMI_H
#define SEYEHATKURALLARIISLEMI_H

#include <QObject>
#include <Islemler/TemelKullaniciIslemi.h>
class SeyehatKurallariIslemi : public QObject, public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit SeyehatKurallariIslemi(QObject *parent = nullptr);

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

#endif // SEYEHATKURALLARIISLEMI_H
