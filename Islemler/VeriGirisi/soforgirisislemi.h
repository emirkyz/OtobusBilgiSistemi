#ifndef SOFORGIRISISLEMI_H
#define SOFORGIRISISLEMI_H

#include <QObject>
#include <Islemler/TemelKullaniciIslemi.h>
class SoforGirisIslemi : public QObject, public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit SoforGirisIslemi(QObject *parent = nullptr);

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
#endif // SOFORGIRISISLEMI_H
