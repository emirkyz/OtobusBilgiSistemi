#ifndef ISLETMELISTESI_H
#define ISLETMELISTESI_H

#include <QWidget>
#include <Veri/Tanimlar.h>

namespace Ui {
class IsletmeListesi;
}
class IsletmeFiltrelemeFonksiyonu{
public:
    typedef enum{FiltreIleBaslayan = 1,
                   FiltreIleBiten = 2,
                   FiltreIceren = 4,} FiltrelemeTuru;

    const QString &alanAdi() const;
    void setAlanAdi(const QString &newAlanAdi);

    FiltrelemeTuru filtre() const;
    void setFiltre(FiltrelemeTuru newFiltre);

    const QString &arananDeger() const;
    void setArananDeger(const QString &newArananDeger);

    bool operator()(IsletmeBilgileriPtr data);

private:
    QString _alanAdi;
    FiltrelemeTuru _filtre;
    QString _arananDeger;
};

class IsletmeListesi : public QWidget
{
    Q_OBJECT

public:
    explicit IsletmeListesi(IsletmeDeposu &depo,QWidget *parent = nullptr);
    ~IsletmeListesi();

    const IsletmeBilgileriListesi &liste() const;
    void setListe(const IsletmeBilgileriListesi &newListe);

private slots:
    void on_btnAra_clicked();

private:
    Ui::IsletmeListesi *ui;
    IsletmeBilgileriListesi _liste;
    IsletmeDeposu& _depo;
    void ekranGuncelle();
};

#endif // ISLETMELISTESI_H
