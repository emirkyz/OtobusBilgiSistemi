#include "otobuslistesi.h"
#include "ui_otobuslistesi.h"
#include <QStringList>
#include <QTableWidgetItem>
#include <Veri/VeriSiniflari/otobusbilgileri.h>
#include <Veri/VeriDepolari/otobusdeposu.h>

OtobusListesi::OtobusListesi(OtobusDeposu &depo,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OtobusListesi),_depo(depo)
{
    ui->setupUi(this);
}

OtobusListesi::~OtobusListesi()
{
    delete ui;
}

const OtobusBilgileriListesi &OtobusListesi::liste() const
{
    return _liste;
}

void OtobusListesi::setListe(const OtobusBilgileriListesi &newListe)
{
    _liste = newListe;
    ekranGuncelle();
}

void OtobusListesi::ekranGuncelle()
{
    ui->tblOtobusler->clear();
    ui->tblOtobusler->setColumnCount(6);
    QStringList Basliklar;
    Basliklar << tr("Model") << tr("Kapasite") << tr("Renk")
              << tr("Boyut") << tr("Oturma Düzeni") << tr("Plaka");
    ui->tblOtobusler->setHorizontalHeaderLabels(Basliklar);
    ui->tblOtobusler->setRowCount(_liste.size());
    for(int i=0 ; i < _liste.size() ; i++){
        const auto nesne_i = _liste[i];
        QTableWidgetItem *hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Model());
        ui->tblOtobusler->setItem(i,0,hucre);

        hucre = new QTableWidgetItem;
        QString temp = QString::number(nesne_i->Kapasite());
        hucre->setText(temp);
        ui->tblOtobusler->setItem(i,1, hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Renk());
        ui->tblOtobusler->setItem(i,2,hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Boyut());
        ui->tblOtobusler->setItem(i,3,hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->OturmaDuzeni());
        ui->tblOtobusler->setItem(i,4,hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Plaka());
        ui->tblOtobusler->setItem(i,5,hucre);
 }
}


const QString &OtobusFiltrelemeFonksiyonu::alanAdi() const
{
    return _alanAdi;
}

void OtobusFiltrelemeFonksiyonu::setAlanAdi(const QString &newAlanAdi)
{
    _alanAdi = newAlanAdi;
}

OtobusFiltrelemeFonksiyonu::FiltrelemeTuru OtobusFiltrelemeFonksiyonu::filtre() const
{
    return _filtre;
}

void OtobusFiltrelemeFonksiyonu::setFiltre(FiltrelemeTuru newFiltre)
{
    _filtre = newFiltre;
}

const QString &OtobusFiltrelemeFonksiyonu::arananDeger() const
{
    return _arananDeger;
}

void OtobusFiltrelemeFonksiyonu::setArananDeger(const QString &newArananDeger)
{
    _arananDeger = newArananDeger;
}

bool OtobusFiltrelemeFonksiyonu::operator()(OtobusBilgileriPtr data)
{
    if(_alanAdi == "tumu"){

    }
    QString deger;
    if(_alanAdi == "Model"){
        deger = data->Model();
    }
    if(_alanAdi == "Renk"){
        deger = data->Renk();
    }
    if(_alanAdi == "Kapasite"){
        QString temp = QString::number(data->Kapasite());
        deger = temp;
    }
    if(_alanAdi == "Boyut"){
        deger = data->Boyut();
    }
    if(_alanAdi == "OturmaDuzeni"){
        deger = data->OturmaDuzeni();
    }
    if(_alanAdi == "Plaka"){
        deger = data->Plaka();
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

void OtobusListesi::on_btnAra_clicked()
{
    OtobusFiltrelemeFonksiyonu f;
    if(ui->rbOtobusBoyut->isChecked()){
        f.setAlanAdi("Boyut");
    }
    if(ui->rbOtobusRenk->isChecked()){
        f.setAlanAdi("Renk");
    }
    if(ui->rbOtobusKapasite->isChecked()){
        f.setAlanAdi("Kapasite");
    }
    if(ui->rbOtobusModel->isChecked()){
        f.setAlanAdi("Model");
    }
    if(ui->rbOtobusOturmaDuzeni->isChecked()){
        f.setAlanAdi("OturmaDuzeni");
    }
    if(ui->rbOtobusPlaka->isChecked()){
        f.setAlanAdi("Plaka");
    }
    if(ui->rbIceren->isChecked()){
        f.setFiltre(OtobusFiltrelemeFonksiyonu::FiltreIceren);
    }
    if(ui->rbBaslayan->isChecked()){
        f.setFiltre(OtobusFiltrelemeFonksiyonu::FiltreIleBaslayan);
    }
    if(ui->rbBiten->isChecked()){
        f.setFiltre(OtobusFiltrelemeFonksiyonu::FiltreIleBiten);
    }

    f.setArananDeger(ui->leAranan->text().toLower());
    auto liste = _depo.tumunuBul(f);
    setListe(liste);

}

