#ifndef AYARLAR_H
#define AYARLAR_H

#include <QObject>
#include "../Tanimlar.h"



class Ayarlar : public QObject
{
    Q_OBJECT
public:
    static Ayarlar& ayar();
    Q_PROPERTY(Tamsayi isletmeId READ isletmeId WRITE setIsletmeId NOTIFY isletmeIdChanged)

    ~Ayarlar();

    Tamsayi isletmeId() const;


public slots:
    void setIsletmeId(Tamsayi newIsletmeId);

signals:
    void isletmeIdChanged(Tamsayi isletmeId);



private:
    explicit Ayarlar(QObject *parent = nullptr);
    Tamsayi _isletmeId;


};

#endif // AYARLAR_H
