#ifndef ISLETMESILMEISLEMI_H
#define ISLETMESILMEISLEMI_H

#include <QObject>
#include <Islemler/TemelKullaniciIslemi.h>
#include <Veri/Tanimlar.h>
class IsletmeSilmeIslemi : public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit IsletmeSilmeIslemi(QObject *parent = nullptr);
    QAction *islem() override;
    const IsletmeBilgileriPtr &veri() const;
    void setVeri(const IsletmeBilgileriPtr &newVeri);

signals:
private:
    QAction *_islem;
    IsletmeBilgileriPtr _veri;
    // TemelKullaniciIslemi interface
public slots:
    void main() override;
    // void depoSil();
};

#endif // ISLETMESILMEISLEMI_H
