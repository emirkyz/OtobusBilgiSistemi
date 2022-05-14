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

}

OtobusBilgiSistemi::~OtobusBilgiSistemi()
{
    delete ui;
}

