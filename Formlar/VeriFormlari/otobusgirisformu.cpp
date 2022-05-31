#include "otobusgirisformu.h"
#include "ui_otobusgirisformu.h"
#include <QPainter>
OtobusGirisFormu::OtobusGirisFormu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OtobusGirisFormu){
    ui->setupUi(this);
    connect(ui->btnKaydet,SIGNAL(clicked()),this, SIGNAL(veriKaydet()));

}
OtobusGirisFormu::~OtobusGirisFormu(){
    delete ui;
}

/*!
    \class OtobusGirisFormu::paintEvent
    \brief QWidget ve diğer ui larda arkaplanı ayarlamaya yarar.

    Bu sınıf override edilmesi gereken bir sınıf bu yüzden override et,
        gerekirse fonksiyon değer kümesini (QPaintEvent *) olarak yaz
    " void OtobusGirisFormu::paintEvent(QPaintEvent *) "
    \note https://stackoverflow.com/questions/62935451/qpixmap-resizing-with-realsense-image?utm_source=pocket_mylist
            Ana kaynak link.
                       */
void OtobusGirisFormu::paintEvent(QPaintEvent *)
{
    QImage image;
    image.load(":/Resimler/busBackground.png");
    QPainter painter(this);
    auto scaled = image.scaled(width(), height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter.setOpacity(0.8);
    painter.drawImage(0,51,scaled);

}


void OtobusGirisFormu::ekranGuncelle(){
    ui->leOturmaDuzeni->setText(_veri->OturmaDuzeni());
    ui->leBoyut->setText(_veri->Boyut());
    ui->leModel->setText(_veri->Model());
    ui->lePlaka->setText(_veri->Plaka());
    ui->leRenk->setText(_veri->Renk());
    ui->spnKapasite->setValue(_veri->Kapasite());
}

void OtobusGirisFormu::veriGuncelle(){
    _veri->setOturmaDuzeni(ui->leOturmaDuzeni->text());
    _veri->setBoyut(ui->leBoyut->text());
    _veri->setModel(ui->leModel->text());
    _veri->setPlaka(ui->lePlaka->text());
    _veri->setRenk(ui->leRenk->text());
    _veri->setKapasite(ui->spnKapasite->value());
}
