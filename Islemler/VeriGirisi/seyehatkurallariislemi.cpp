#include "seyehatkurallariislemi.h"
#include "Veri/data.h"
#include "Formlar/VeriFormlari/seyehatkurallariverigirisformu.h"

SeyehatKurallariIslemi::SeyehatKurallariIslemi(QObject *parent)
    : QObject{parent}
{
    _islem = new QAction;
    _islem->setText(tr("Yeni Seyehat Kuralı Girişi"));
    _islem->setIcon(QIcon(":/Resimler/SeyehatKurallari.png"));
    _islem->setIconText("Yeni Seyehat Kuralı Girişi");
    connect(_islem, &QAction::triggered, this, &SeyehatKurallariIslemi::main);

}


void SeyehatKurallariIslemi::main()
{
    auto veri = Data::d1().kurallar().yeniNesne();
    SeyehatKurallariVeriGirisFormu *form = new SeyehatKurallariVeriGirisFormu();
    connect(form, &SeyehatKurallariVeriGirisFormu::veriKaydet, this, &SeyehatKurallariIslemi::depoEkle);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowModality(Qt::ApplicationModal);
    form->setVeri(veri);
    form->show();
}

QAction *SeyehatKurallariIslemi::islem()
{
    return _islem;
}

void SeyehatKurallariIslemi::depoEkle()
{
    SeyehatKurallariVeriGirisFormu *frmx = dynamic_cast<SeyehatKurallariVeriGirisFormu *>(sender());
    auto veri = frmx->veri();
    Data::d1().kurallar().nesneEkle(veri);
    frmx->close();
}
