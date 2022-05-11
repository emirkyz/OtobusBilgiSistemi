#ifndef ISLEMDEPOSU_H
#define ISLEMDEPOSU_H
#include <QList>
#include <QObject>
#include "TemelKullaniciIslemi.h"
#include <memory.h>

class IslemDeposu : public QObject
{
    Q_OBJECT
public:
    static IslemDeposu &fb();

    typedef enum {IslemIsletmeGiris=0, IslemOtobusGiris,
                   IslemSeferGiris, IslemKuralGiris, IslemSeyehatGiris} IslemSirasi;

    //0 dan başlayarak yazdığın kelimeler typedef gibi sayılar verir

    QAction* getAction(IslemSirasi x);
    void calistir(IslemSirasi y);

private:

    explicit IslemDeposu(QObject *parent = nullptr);
    QList<std::shared_ptr<TemelKullaniciIslemi>> _islemler;

signals:

};

#endif // ISLEMDEPOSU_H
