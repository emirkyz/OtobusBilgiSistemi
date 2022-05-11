#ifndef SEFERVERIGIRISFORMU_H
#define SEFERVERIGIRISFORMU_H

#include <QWidget>
#include "TemelVeriGirisi.h"
#include <Veri/VeriSiniflari/seferbilgileri.h>

namespace Ui {
class SeferVeriGirisFormu;
}

class SeferVeriGirisFormu : public QWidget, public TemelVeriGirisi<SeferbilgileriPtr>
{
    Q_OBJECT

public:
    explicit SeferVeriGirisFormu(QWidget *parent = nullptr);
    ~SeferVeriGirisFormu();

private:
    Ui::SeferVeriGirisFormu *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
signals:
    void veriKaydet();
};

#endif // SEFERVERIGIRISFORMU_H
