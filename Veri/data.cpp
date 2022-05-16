#include "data.h"
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QDataStream>
#include <QDebug>

void Data::kaydet()
{
    QFile dosya(dosyaYolu());
    if(dosya.open(QIODevice::WriteOnly)){
        QDataStream out(&dosya);
        out << *this;
        dosya.close();
    }
}

void Data::yukle()
{
    QFile dosya(dosyaYolu());
    if(dosya.open(QIODevice::ReadOnly)){
        QDataStream in(&dosya);
        in >> *this;
        dosya.close();
    }
}

Data::~Data()
{
    qDebug() << "Data sonlandırılıyor";
    kaydet();
}

Data::Data(QObject *parent)
    : QObject{parent}
{
    qDebug() << "Data başlatılıyor";
    yukle();
}

QString Data::dosyaYolu()
{
    auto klasor = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir a(klasor);
    if (!a.exists()){
        a.mkpath(klasor);
    }
    qDebug() << klasor + "/veri.dat";
    return klasor + "/veri.dat";

}


QDataStream &operator<<(QDataStream &stream, const Data &veri){
    stream << veri._isletmeler;
    stream << veri._otobusler;
    stream << veri._seferler;
    stream << veri._kurallar;
    stream << veri._soforler;
    stream << veri._yolcular;
    stream << veri._seyehatler;
    stream << veri._biletler;
    return stream;
}
QDataStream &operator>>(QDataStream &stream, Data &veri){
    stream >> veri._isletmeler;
    stream >> veri._otobusler;
    stream >> veri._seferler;
    stream >> veri._kurallar;
    stream >> veri._soforler;
    stream >> veri._yolcular;
    stream >> veri._seyehatler;
    stream >> veri._biletler;
    return stream;
}

