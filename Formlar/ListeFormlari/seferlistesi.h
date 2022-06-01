#ifndef SEFERLISTESI_H
#define SEFERLISTESI_H

#include <QWidget>
#include <Veri/Tanimlar.h>
namespace Ui {
class SeferListesi;
}

class SeferFiltrelemeFonksiyonu{
public:
    typedef enum{FiltreIleBaslayan = 1,
                   FiltreIleBiten = 2,
                   FiltreIceren = 4,} FiltrelemeTuru;


    bool operator()(SeferbilgileriPtr data);

    const QString &alanAdi() const;
    void setAlanAdi(const QString &newAlanAdi);

    FiltrelemeTuru filtre() const;
    void setFiltre(FiltrelemeTuru newFiltre);

    const QString &arananDeger() const;
    void setArananDeger(const QString &newArananDeger);

private:
    QString _alanAdi;
    FiltrelemeTuru _filtre;
    QString _arananDeger;
};

class SeferListesi : public QWidget
{
    Q_OBJECT

public:
    explicit SeferListesi(SeferDeposu &depo,QWidget *parent = nullptr);
    ~SeferListesi();




    const SeferbilgileriListesi &liste() const;
    void setListe(const SeferbilgileriListesi &newListe);

    SeferDeposu &depo() const;
    void setDepo(const SeferDeposu &newDepo);

private slots:
    void on_btnAra_clicked();

private:
    Ui::SeferListesi *ui;
    SeferbilgileriListesi _liste;
    SeferDeposu& _depo;
    void ekranGuncelle();
};


#endif // SEFERLISTESI_H
