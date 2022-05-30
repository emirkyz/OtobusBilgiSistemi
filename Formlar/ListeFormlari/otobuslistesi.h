#ifndef OTOBUSLISTESI_H
#define OTOBUSLISTESI_H

#include <QWidget>
#include <Veri/Tanimlar.h>
namespace Ui {
class OtobusListesi;
}
class OtobusFiltrelemeFonksiyonu{
public:
    typedef enum{FiltreIleBaslayan = 1,
                   FiltreIleBiten = 2,
                   FiltreIceren = 4,} FiltrelemeTuru;


    bool operator()(OtobusBilgileriPtr data);

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

class OtobusListesi : public QWidget
{
    Q_OBJECT

public:
    explicit OtobusListesi(OtobusDeposu &depo,QWidget *parent = nullptr);
    ~OtobusListesi();

    const OtobusBilgileriListesi &liste() const;
    void setListe(const OtobusBilgileriListesi &newListe);

private slots:
    void on_btnAra_clicked();

private:
    Ui::OtobusListesi *ui;
    OtobusBilgileriListesi _liste;
    OtobusDeposu& _depo;
    void ekranGuncelle();
};

#endif // OTOBUSLISTESI_H
