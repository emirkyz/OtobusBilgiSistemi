#include "ayarlar.h"
#include <QDir>
#include <QStandardPaths>
#include <QFile>
#include <QDataStream>

Ayarlar &Ayarlar::ayar()
{
    static Ayarlar ayr;
    return ayr;
}

Ayarlar::~Ayarlar()
{
    auto klasor = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
    QDir a(klasor);
    if(!a.exists()){
        a.mkpath(klasor);
    }
    QFile dosya(klasor+"/ayarlar.cfg");
    if(dosya.open(QIODevice::WriteOnly)){
        QDataStream stream(&dosya);
        stream << _isletmeId;
    }
}

Ayarlar::Ayarlar(QObject *parent)
    : QObject{parent}, _isletmeId{-1}
{
    auto klasor = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
    QDir a(klasor);
    if(!a.exists()){
        a.mkpath(klasor);
    }
    QFile dosya(klasor+"/ayarlar.cfg");
    if(dosya.open(QIODevice::ReadOnly)){
        QDataStream stream(&dosya);
        stream >> _isletmeId;
    }
}

Tamsayi Ayarlar::isletmeId() const
{
    return _isletmeId;
}

void Ayarlar::setIsletmeId(Tamsayi newIsletmeId)
{
    if (_isletmeId == newIsletmeId)
        return;
    _isletmeId = newIsletmeId;
    emit isletmeIdChanged(_isletmeId);
}


