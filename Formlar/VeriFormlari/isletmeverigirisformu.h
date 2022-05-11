#ifndef ISLETMEVERIGIRISFORMU_H
#define ISLETMEVERIGIRISFORMU_H
#include "TemelVeriGirisi.h"
#include <QWidget>
#include <Veri/VeriSiniflari/isletmebilgileri.h>

namespace Ui {
class IsletmeVeriGirisFormu;
}

class IsletmeVeriGirisFormu : public QWidget, public TemelVeriGirisi<IsletmeBilgileriPtr>

{
    Q_OBJECT

public:
    explicit IsletmeVeriGirisFormu(QWidget *parent = nullptr);
    ~IsletmeVeriGirisFormu();

private:
    Ui::IsletmeVeriGirisFormu *ui;

    // TemelVeriGirisi interface
public:
    void ekranGuncelle() override;
    void veriGuncelle() override;
signals:
    void veriKaydet();

};

#endif // ISLETMEVERIGIRISFORMU_H
