#include "otobusbilgisistemi.h"
#include "ui_otobusbilgisistemi.h"
#include <Islemler/islemdeposu.h>
#include <Islemler/VeriGirisi/isletmegirisislemi.h>

OtobusBilgiSistemi::OtobusBilgiSistemi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OtobusBilgiSistemi)
{


    ui->setupUi(this);
    ui->menu_letme->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemIsletmeGiris));
    ui->toolBarVeriGiris->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemIsletmeGiris));
    // button a action eklenemez, bu yüzden toolbutton da dafault action değiştirilir!!!!
    ui->tbIsletme->setDefaultAction(IslemDeposu::fb().getAction(IslemDeposu::IslemIsletmeGiris));
    ui->menu_letme->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemIsletmeListe));
    ui->tblIsletmeListesi->setDefaultAction(IslemDeposu::fb().getAction(IslemDeposu::IslemIsletmeListe));


    ui->menuOtobusler->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemOtobusGiris));
    ui->toolBarVeriGiris->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemOtobusGiris));
    ui->tbOtobus->setDefaultAction(IslemDeposu::fb().getAction(IslemDeposu::IslemOtobusGiris));

    ui->menuSeferler->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemSeferGiris));
    ui->toolBarVeriGiris->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemSeferGiris));
    ui->tbSefer->setDefaultAction(IslemDeposu::fb().getAction(IslemDeposu::IslemSeferGiris));

    ui->menuSeyehat_Kurallar->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemKuralGiris));
    ui->toolBarVeriGiris->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemKuralGiris));
    ui->tbSeyehatKurallari->setDefaultAction(IslemDeposu::fb().getAction(IslemDeposu::IslemKuralGiris));

    ui->menuSeyehatler->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemSeyehatGiris));
    ui->toolBarVeriGiris->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemSeyehatGiris));
    ui->tbSeyehat->setDefaultAction(IslemDeposu::fb().getAction(IslemDeposu::IslemSeyehatGiris));

    ui->menuSoforler->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemSoforGiris));
    ui->tbSofor->setDefaultAction(IslemDeposu::fb().getAction(IslemDeposu::IslemSoforGiris));
    ui->toolBarVeriGiris->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemSoforGiris));

    ui->menuYolcular->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemYolcuGiris));
    ui->tbYolcular->setDefaultAction(IslemDeposu::fb().getAction(IslemDeposu::IslemYolcuGiris));
    ui->toolBarVeriGiris->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemYolcuGiris));

    ui->menuBiletler->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemBiletGiris));
    ui->tbBilet->setDefaultAction(IslemDeposu::fb().getAction(IslemDeposu::IslemBiletGiris));
    ui->toolBarVeriGiris->addAction(IslemDeposu::fb().getAction(IslemDeposu::IslemBiletGiris));
}

OtobusBilgiSistemi::~OtobusBilgiSistemi()
{
    delete ui;
}

