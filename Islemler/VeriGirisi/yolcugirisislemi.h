#ifndef YOLCUGIRISISLEMI_H
#define YOLCUGIRISISLEMI_H

#include <QObject>
#include <Islemler/TemelKullaniciIslemi.h>
class YolcuGirisIslemi : public QObject, public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit YolcuGirisIslemi(QObject *parent = nullptr);

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

#endif // YOLCUGIRISISLEMI_H
