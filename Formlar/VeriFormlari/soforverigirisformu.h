#ifndef SOFORVERIGIRISFORMU_H
#define SOFORVERIGIRISFORMU_H

#include <QWidget>
#include "TemelVeriGirisi.h"
#include <Veri/VeriSiniflari/soforbilgileri.h>
namespace Ui {
class SoforVeriGirisFormu;
}

class SoforVeriGirisFormu : public QWidget, public TemelVeriGirisi<SoforbilgileriPtr>
{
    Q_OBJECT

public:
    explicit SoforVeriGirisFormu(QWidget *parent = nullptr);
    ~SoforVeriGirisFormu();

private:
    Ui::SoforVeriGirisFormu *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
signals:
    void veriKaydet();
};

#endif // SOFORVERIGIRISFORMU_H
