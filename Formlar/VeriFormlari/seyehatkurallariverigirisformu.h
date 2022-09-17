#ifndef SEYEHATKURALLARIVERIGIRISFORMU_H
#define SEYEHATKURALLARIVERIGIRISFORMU_H

#include <QWidget>
#include "TemelVeriGirisi.h"
#include <Veri/VeriSiniflari/seyehatkurallari.h>
namespace Ui {
class SeyehatKurallariVeriGirisFormu;
}

class SeyehatKurallariVeriGirisFormu : public QWidget, public TemelVeriGirisi<SeyehatKurallariPtr>

{
    Q_OBJECT

public:
    explicit SeyehatKurallariVeriGirisFormu(QWidget *parent = nullptr);
    ~SeyehatKurallariVeriGirisFormu();

private:
    Ui::SeyehatKurallariVeriGirisFormu *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
signals:
    void veriKaydet();
};

#endif // SEYEHATKURALLARIVERIGIRISFORMU_H
