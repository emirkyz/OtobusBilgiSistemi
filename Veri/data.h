#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <Veri/VeriDepolari/isletmedeposu.h>
#include <Veri/VeriDepolari/otobusdeposu.h>
#include <Veri/VeriDepolari/seferdeposu.h>
#include <Veri/VeriDepolari/seyehatkurallarideposu.h>
#include <Veri/VeriDepolari/sofordeposu.h>
#include <Veri/VeriDepolari/yolcudeposu.h>
#include <Veri/VeriDepolari/seyehatdeposu.h>

class Data : public QObject
{
    Q_OBJECT
public:

    IsletmeDeposu &isletmeler(){return _isletmeler;}
    OtobusDeposu &otobusler(){return _otobusler;}
    SeferDeposu &seferler(){return _seferler;}
    SeyehatKurallariDeposu &kurallar(){return _kurallar;}
    SoforDeposu &soforler(){return _soforler;}
    YolcuDeposu &yolcular(){return _yolcular;}
    SeyehatDeposu &seyehatler(){return _seyehatler;}

    void kaydet();
    void yukle();

    ~Data();

    static Data& d1(){
        static Data veri;
        return veri;
    }

signals:

private:
    explicit Data(QObject *parent = nullptr);

    IsletmeDeposu _isletmeler;
    OtobusDeposu _otobusler;
    SeferDeposu _seferler;
    SeyehatKurallariDeposu _kurallar;
    SoforDeposu _soforler;
    YolcuDeposu _yolcular;
    SeyehatDeposu _seyehatler;

    QString dosyaYolu();
    friend QDataStream &operator<<(QDataStream &stream, const Data &veri);
    friend QDataStream &operator>>(QDataStream &stream, Data &veri);
};

QDataStream &operator<<(QDataStream &stream, const Data &veri);
QDataStream &operator>>(QDataStream &stream, Data &veri);

#endif // DATA_H
