#ifndef YOLCULISTESI_H
#define YOLCULISTESI_H

#include <QWidget>
#include <Veri/Tanimlar.h>

namespace Ui {
class YolcuListesi;
}
class YolcuFiltrelemeFonksiyonu{
public:
    typedef enum{FiltreIleBaslayan = 1,
                   FiltreIleBiten = 2,
                   FiltreIceren = 4,} FiltrelemeTuru;


    bool operator()(YolcubilgileriPtr data);



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

class YolcuListesi : public QWidget
{
    Q_OBJECT

public:
    explicit YolcuListesi(YolcuDeposu &depo,QWidget *parent = nullptr);
    ~YolcuListesi();

    const YolcubilgileriListesi &liste() const;
    void setListe(const YolcubilgileriListesi &newListe);

private slots:
    void on_btnAra_clicked();

private:
    Ui::YolcuListesi *ui;
    YolcubilgileriListesi _liste;
    YolcuDeposu& _depo;
    void ekranGuncelle();
};

#endif // YOLCULISTESI_H
