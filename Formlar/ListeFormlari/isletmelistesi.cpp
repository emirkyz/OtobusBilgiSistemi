#include "isletmelistesi.h"
#include "ui_isletmelistesi.h"
#include <QStringList>
#include <QTableWidgetItem>
#include <Veri/VeriSiniflari/isletmebilgileri.h>
IsletmeListesi::IsletmeListesi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IsletmeListesi)
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
    ui->tblIsletmeler->setColumnCount(5);
    QStringList Basliklar;
    Basliklar << tr("İşletme Adı") << tr("Kurucu Adı") << tr("Kurucu Soyad")
              << tr("Vergi Numarası") << tr("Adres");
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

    }



}
