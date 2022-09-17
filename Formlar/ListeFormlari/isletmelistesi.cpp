#include "isletmelistesi.h"
#include "ui_isletmelistesi.h"
#include <QStringList>
#include <QTableWidgetItem>

#include <Veri/VeriSiniflari/isletmebilgileri.h>
#include <Veri/VeriDepolari/isletmedeposu.h>
#include <Islemler/islemdeposu.h>
#include <Islemler/VeriSilme/isletmesilmeislemi.h>

IsletmeListesi::IsletmeListesi(IsletmeDeposu &depo,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IsletmeListesi),_depo(depo)
{
    ui->setupUi(this);
}

IsletmeListesi::~IsletmeListesi()
{
    delete ui;
}

const IsletmeBilgileriListesi &IsletmeListesi::liste() const
{
    return _liste;
}

void IsletmeListesi::setListe(const IsletmeBilgileriListesi &newListe)
{
    _liste = newListe;
    ekranGuncelle();
}

void IsletmeListesi::ekranGuncelle()
{
    ui->tblIsletmeler->clear();
    ui->tblIsletmeler->setColumnCount(6);
    QStringList Basliklar;
    Basliklar << tr("İşletme Adı") << tr("Kurucu Adı") << tr("Kurucu Soyad")
              << tr("Vergi Numarası") << tr("Adres") << tr("Sil");
    ui->tblIsletmeler->setHorizontalHeaderLabels(Basliklar);
    ui->tblIsletmeler->setRowCount(_liste.size());
    for(int i=0;i<_liste.size();i++){
        const auto &nesne_i = _liste[i];
        QTableWidgetItem *hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->IsletmeAdi());
        ui->tblIsletmeler->setItem(i,0,hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->KurucuAd());
        ui->tblIsletmeler->setItem(i,1,hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->KurucuSoyad());
        ui->tblIsletmeler->setItem(i,2,hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->VergiNo());
        ui->tblIsletmeler->setItem(i,3,hucre);

        hucre = new QTableWidgetItem;
        hucre->setText(nesne_i->Adres());
        ui->tblIsletmeler->setItem(i,4,hucre);

        auto silmeButonu = new QPushButton();
        auto gui = this->ui;
        silmeButonu->setText("Sil");
        connect(silmeButonu, &QPushButton::clicked,[nesne_i,gui](){
            auto islem1 = IslemDeposu::fb().getIslem(IslemDeposu::IslemIsletmeSilme);
            auto islem2 = std::dynamic_pointer_cast<IsletmeSilmeIslemi>(islem1);
            islem2->setVeri(nesne_i);
            islem2->main();
            gui->btnAra->click();
        });


        ui->tblIsletmeler->setCellWidget(i,5,silmeButonu);
    }
}


const QString &IsletmeFiltrelemeFonksiyonu::alanAdi() const
{
    return _alanAdi;
}

void IsletmeFiltrelemeFonksiyonu::setAlanAdi(const QString &newAlanAdi)
{
    _alanAdi = newAlanAdi;
}

IsletmeFiltrelemeFonksiyonu::FiltrelemeTuru IsletmeFiltrelemeFonksiyonu::filtre() const
{
    return _filtre;
}

void IsletmeFiltrelemeFonksiyonu::setFiltre(FiltrelemeTuru newFiltre)
{
    _filtre = newFiltre;
}

const QString &IsletmeFiltrelemeFonksiyonu::arananDeger() const
{
    return _arananDeger;
}

void IsletmeFiltrelemeFonksiyonu::setArananDeger(const QString &newArananDeger)
{
    _arananDeger = newArananDeger;
}

bool IsletmeFiltrelemeFonksiyonu::operator()(IsletmeBilgileriPtr data)
{
    if(_alanAdi == "tumu"){

    }

    QString deger;
    if(_alanAdi == "IsletmeAdi"){
        deger = data->IsletmeAdi();
    }
    if(_alanAdi == "KurucuAd"){
        deger = data->KurucuAd();
    }
    if(_alanAdi == "KurucuSoyad"){
        deger = data->KurucuSoyad();
    }
    if(_alanAdi == "VergiNo"){
        deger = data->VergiNo();
    }
    if(_alanAdi == "Adres"){
        deger = data->Adres();
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

void IsletmeListesi::on_btnAra_clicked()
{
    IsletmeFiltrelemeFonksiyonu f;

    if(ui->rbIsletmeAdi->isChecked()){
        f.setAlanAdi("IsletmeAdi");
    }
    if(ui->rbKurucuAd->isChecked()){
        f.setAlanAdi("KurucuAd");
    }
    if(ui->rbKurucuSoyad->isChecked()){
        f.setAlanAdi("KurucuSoyad");
    }
    if(ui->rbVergiNo->isChecked()){
        f.setAlanAdi("VergiNo");
    }
    if(ui->rbAdres->isChecked()){
        f.setAlanAdi("Adres");
    }

    if(ui->rbIceren->isChecked()){
        f.setFiltre(IsletmeFiltrelemeFonksiyonu::FiltreIceren);
    }
    if(ui->rbBaslayan->isChecked()){
        f.setFiltre(IsletmeFiltrelemeFonksiyonu::FiltreIleBaslayan);
    }
    if(ui->rbBiten->isChecked()){
        f.setFiltre(IsletmeFiltrelemeFonksiyonu::FiltreIleBiten);
    }

    f.setArananDeger(ui->leAranan->text().toLower());

    auto liste = _depo.tumunuBul(f);
    setListe(liste);
}

