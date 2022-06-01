#include "seferlistesi.h"
#include "ui_seferlistesi.h"
#include <QStringList>
#include <QTableWidgetItem>
#include <Veri/VeriSiniflari/seferbilgileri.h>
#include <Veri/VeriDepolari/seferdeposu.h>

SeferListesi::SeferListesi(SeferDeposu &depo,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeferListesi),_depo(depo)
{
    ui->setupUi(this);
}

bool SeferFiltrelemeFonksiyonu::operator()(SeferbilgileriPtr data)
{

    if(_alanAdi == "tumu"){

    }
    QString deger;
    if(_alanAdi == "SeferUzunluk"){
        deger = data->SeferUzunluk();
    }
    if(_alanAdi == "MolaSayisi"){
        QString temp = QString::number(data->MolaSayisi());
        deger = temp;
    }
    if(_alanAdi == "Mesafe"){
        QString temp2 = QString::number(data->Mesafe());
        deger = temp2;
    }
    if(_alanAdi == "VarisNoktasi"){
        deger = data->VarisNoktasi();
    }
    if(_alanAdi == "BaslangicNoktasi"){
        deger = data->BaslangicNoktasi();
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
SeferListesi::~SeferListesi()
{
    delete ui;
}

const SeferbilgileriListesi &SeferListesi::liste() const
{
    return _liste;
}

void SeferListesi::setListe(const SeferbilgileriListesi &newListe)
{
    _liste = newListe;
    ekranGuncelle();
}

void SeferListesi::on_btnAra_clicked()
{
    SeferFiltrelemeFonksiyonu f;
    if(ui->rbSeferUzunlugu->isChecked()){
        f.setAlanAdi("SeferUzunluk");
    }
    if(ui->rbMolaSayisi->isChecked()){
        f.setAlanAdi("MolaSayisi");
    }
    if(ui->rbMesafe->isChecked()){
        f.setAlanAdi("Mesafe");
    }
    if(ui->rbVarisNoktasi->isChecked()){
        f.setAlanAdi("VarisNoktasi");
    }
    if(ui->rbBaslangicNoktasi->isChecked()){
        f.setAlanAdi("BaslangicNoktasi");

    }
    if(ui->rbIceren->isChecked()){
        f.setFiltre(SeferFiltrelemeFonksiyonu::FiltreIceren);
    }
    if(ui->rbBaslayan->isChecked()){
        f.setFiltre(SeferFiltrelemeFonksiyonu::FiltreIleBaslayan);
    }
    if(ui->rbBiten->isChecked()){
        f.setFiltre(SeferFiltrelemeFonksiyonu::FiltreIleBiten);
    }

    f.setArananDeger(ui->leAranan->text().toLower());
    auto liste = _depo.tumunuBul(f);
    setListe(liste);
}

void SeferListesi::ekranGuncelle()
{

    ui->tblSeferler->clear();
    ui->tblSeferler->setColumnCount(5);
    QStringList Basliklar;
    Basliklar << tr("Sefer Uzunluğu") << tr("Mola sayısı") << tr("Mesafe(KM)")
              << tr("Varış noktası") << tr("Başlangıç noktası");
    ui->tblSeferler->setHorizontalHeaderLabels(Basliklar);
    ui->tblSeferler->setRowCount(_liste.size());
    for(int i=0 ; i < _liste.size() ; i++){
        const auto nesne_i = _liste[i];
        QTableWidgetItem *hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->SeferUzunluk());
        ui->tblSeferler->setItem(i,0,hucre);

        hucre = new QTableWidgetItem;
        QString temp = QString::number(nesne_i->MolaSayisi());
        hucre->setText(temp);
        ui->tblSeferler->setItem(i,1, hucre);

        hucre = new QTableWidgetItem;
        QString temp2 = QString::number(nesne_i->Mesafe());
        hucre->setText(temp2);
        ui->tblSeferler->setItem(i,2,hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->VarisNoktasi());
        ui->tblSeferler->setItem(i,3,hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->BaslangicNoktasi());
        ui->tblSeferler->setItem(i,4,hucre);

    }
}


const QString &SeferFiltrelemeFonksiyonu::alanAdi() const
{
    return _alanAdi;
}

void SeferFiltrelemeFonksiyonu::setAlanAdi(const QString &newAlanAdi)
{
    _alanAdi = newAlanAdi;
}

SeferFiltrelemeFonksiyonu::FiltrelemeTuru SeferFiltrelemeFonksiyonu::filtre() const
{
    return _filtre;
}

void SeferFiltrelemeFonksiyonu::setFiltre(FiltrelemeTuru newFiltre)
{
    _filtre = newFiltre;
}

const QString &SeferFiltrelemeFonksiyonu::arananDeger() const
{
    return _arananDeger;
}

void SeferFiltrelemeFonksiyonu::setArananDeger(const QString &newArananDeger)
{
    _arananDeger = newArananDeger;
}
