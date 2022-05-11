#ifndef SEYEHATVERIGIRISFORMU_H
#define SEYEHATVERIGIRISFORMU_H

#include <QWidget>
#include "TemelVeriGirisi.h"
#include <Veri/VeriSiniflari/seyehatbilgileri.h>
namespace Ui {
class SeyehatVeriGirisFormu;
}

class SeyehatVeriGirisFormu : public QWidget, public TemelVeriGirisi<SeyehatbilgileriPtr>
{
    Q_OBJECT

public:
    explicit SeyehatVeriGirisFormu(QWidget *parent = nullptr);
    ~SeyehatVeriGirisFormu();

private:
    Ui::SeyehatVeriGirisFormu *ui;


    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
signals:
    void veriKaydet();
};

#endif // SEYEHATVERIGIRISFORMU_H
