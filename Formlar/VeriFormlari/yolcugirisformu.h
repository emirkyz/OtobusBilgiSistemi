#ifndef YOLCUGIRISFORMU_H
#define YOLCUGIRISFORMU_H

#include <QWidget>
#include "TemelVeriGirisi.h"
#include <Veri/VeriSiniflari/yolcubilgileri.h>

namespace Ui {
class YolcuGirisFormu;
}

class YolcuGirisFormu : public QWidget, public TemelVeriGirisi<YolcubilgileriPtr>

{
    Q_OBJECT

public:
    explicit YolcuGirisFormu(QWidget *parent = nullptr);
    ~YolcuGirisFormu();

private:
    Ui::YolcuGirisFormu *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
};

#endif // YOLCUGIRISFORMU_H
