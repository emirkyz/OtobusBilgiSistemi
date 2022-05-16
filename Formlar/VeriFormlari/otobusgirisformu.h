#ifndef OTOBUSGIRISFORMU_H
#define OTOBUSGIRISFORMU_H

#include <QWidget>
#include "TemelVeriGirisi.h"
#include "qstyleoption.h"
#include <Veri/VeriSiniflari/otobusbilgileri.h>

namespace Ui {
class OtobusGirisFormu;
}

class OtobusGirisFormu : public QWidget, public TemelVeriGirisi<OtobusBilgileriPtr>
{
    Q_OBJECT

public:
    explicit OtobusGirisFormu(QWidget *parent = nullptr);
    ~OtobusGirisFormu();

    void paintEvent(QPaintEvent *) override;
private:
    Ui::OtobusGirisFormu *ui;


    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
signals:
    void veriKaydet();


};

#endif // OTOBUSGIRISFORMU_H
