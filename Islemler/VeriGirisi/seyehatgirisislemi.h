#ifndef SEYEHATGIRISISLEMI_H
#define SEYEHATGIRISISLEMI_H

#include <QObject>
#include <Islemler/TemelKullaniciIslemi.h>
class SeyehatGirisIslemi : public QObject, public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit SeyehatGirisIslemi(QObject *parent = nullptr);

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

#endif // SEYEHATGIRISISLEMI_H
