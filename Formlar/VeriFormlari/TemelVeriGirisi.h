#ifndef TEMELVERIGIRISI_H
#define TEMELVERIGIRISI_H
#include <Veri/Tanimlar.h>

template <class Ptr> class TemelVeriGirisi {
protected:
    Ptr _veri;

public:
    Ptr veri() {
        veriGuncelle();
        return _veri;
    }

    void setVeri(Ptr k) {
        _veri = k;
        ekranGuncelle();
    }

    virtual void ekranGuncelle() = 0;

    virtual void veriGuncelle() = 0;
};
#endif // TEMELVERIGIRISI_H
