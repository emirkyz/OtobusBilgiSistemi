#include "yolculistesi.h"
#include "ui_yolculistesi.h"
#include <QStringList>
#include <QTableWidgetItem>
#include <Veri/VeriSiniflari/yolcubilgileri.h>
#include <Veri/VeriDepolari/yolcudeposu.h>

YolcuListesi::YolcuListesi(YolcuDeposu &depo,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YolcuListesi),_depo(depo)
{
    ui->setupUi(this);
}

YolcuListesi::~YolcuListesi()
{
    delete ui;
}

const YolcubilgileriListesi &YolcuListesi::liste() const
{
    return _liste;
}

void YolcuListesi::setListe(const YolcubilgileriListesi &newListe)
{
    _liste = newListe;
    ekranGuncelle();
}

void YolcuListesi::ekranGuncelle()
{
    ui->tblYolcular->clear();
    ui->tblYolcular->setColumnCount(5);
    QStringList Basliklar;
    Basliklar << tr("Ad") << tr("Soyad") << tr("Yas")
              << tr("Hes Kodu") << tr("TC Kimlik NO");
    ui->tblYolcular->setHorizontalHeaderLabels(Basliklar);
    ui->tblYolcular->setRowCount(_liste.size());
    for(int i=0 ; i < _liste.size() ; i++){
        const auto nesne_i = _liste[i];
        QTableWidgetItem *hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Ad());
        ui->tblYolcular->setItem(i,0,hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Soyad());
        ui->tblYolcular->setItem(i,1, hucre);

        hucre = new QTableWidgetItem;
        QString temp = QString::number(nesne_i->Yas());
        hucre->setText(temp);
        ui->tblYolcular->setItem(i,2,hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->HesKodu());
        ui->tblYolcular->setItem(i,3,hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->TcKimlikNo());
        ui->tblYolcular->setItem(i,4,hucre);

    }
}

bool YolcuFiltrelemeFonksiyonu::operator()(YolcubilgileriPtr data)
{
    if(_alanAdi == "tumu"){

    }
    QString deger;
    if(_alanAdi == "Ad"){
        deger = data->Ad();
    }
    if(_alanAdi == "Soyad"){
        deger = data->Soyad();
    }
    if(_alanAdi == "Yas"){
        QString temp = QString::number(data->Yas());
        deger = temp;
    }
    if(_alanAdi == "TcKimlikNo"){
        deger = data->TcKimlikNo();
    }
    if(_alanAdi == "HesKodu"){
        deger = data->HesKodu();
    }

    if(_filtre == FiltreIleBaslayan){
        auto sonuc = deger.toLower().startsWith(_arananDeger);
        return sonuc;
    }
    if(_filtre == FiltreIleBiten){
        auto sonuc = deger.toLower().endsWith(_arananDeger);
        return sonuc;
    }
    if(_filtre == FiltreIceren){
        auto sonuc = deger.toLower().contains(_arananDeger);
        return sonuc;
    }
    return false;

}

void YolcuListesi::on_btnAra_clicked()
{
    YolcuFiltrelemeFonksiyonu f;
    if(ui->rbYolcuAd->isChecked()){
        f.setAlanAdi("Ad");
    }
    if(ui->rbYolcuSoyad->isChecked()){
        f.setAlanAdi("Soyad");
    }
    if(ui->rbYolcuYas->isChecked()){
        f.setAlanAdi("Yas");
    }
    if(ui->rbYolcuTC->isChecked()){
        f.setAlanAdi("TcKimlikNo");
    }
    if(ui->rbYolcuHes->isChecked()){
        f.setAlanAdi("HesKodu");
    }

    if(ui->rbIceren->isChecked()){
        f.setFiltre(YolcuFiltrelemeFonksiyonu::FiltreIceren);
    }
    if(ui->rbBaslayan->isChecked()){
        f.setFiltre(YolcuFiltrelemeFonksiyonu::FiltreIleBaslayan);
    }
    if(ui->rbBiten->isChecked()){
        f.setFiltre(YolcuFiltrelemeFonksiyonu::FiltreIleBiten);
    }

    f.setArananDeger(ui->leAranan->text().toLower());
    auto liste = _depo.tumunuBul(f);
    setListe(liste);


}


const QString &YolcuFiltrelemeFonksiyonu::alanAdi() const
{
    return _alanAdi;
}

void YolcuFiltrelemeFonksiyonu::setAlanAdi(const QString &newAlanAdi)
{
    _alanAdi = newAlanAdi;
}

YolcuFiltrelemeFonksiyonu::FiltrelemeTuru YolcuFiltrelemeFonksiyonu::filtre() const
{
    return _filtre;
}

void YolcuFiltrelemeFonksiyonu::setFiltre(FiltrelemeTuru newFiltre)
{
    _filtre = newFiltre;
}

const QString &YolcuFiltrelemeFonksiyonu::arananDeger() const
{
    return _arananDeger;
}

void YolcuFiltrelemeFonksiyonu::setArananDeger(const QString &newArananDeger)
{
    _arananDeger = newArananDeger;
}



