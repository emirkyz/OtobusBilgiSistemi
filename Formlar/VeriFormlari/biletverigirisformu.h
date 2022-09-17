#ifndef BILETVERIGIRISFORMU_H
#define BILETVERIGIRISFORMU_H
#include "TemelVeriGirisi.h"
#include <QWidget>
#include <Veri/VeriSiniflari/biletbilgileri.h>
namespace Ui {
class BiletVeriGirisFormu;
}

class BiletVeriGirisFormu : public QWidget, public TemelVeriGirisi<BiletbilgileriPtr>
{
    Q_OBJECT

public:
    explicit BiletVeriGirisFormu(QWidget *parent = nullptr);
    ~BiletVeriGirisFormu();

private:
    Ui::BiletVeriGirisFormu *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
signals:
    void veriKaydet();

};

#endif // BILETVERIGIRISFORMU_H
