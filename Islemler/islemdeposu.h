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
                   IslemSeferGiris, IslemKuralGiris, IslemSeyehatGiris,
                   IslemSoforGiris, IslemYolcuGiris, IslemBiletGiris,
                   IslemIsletmeListe, IslemOtobusListe,IslemYolcuListe,IslemSeferListe,IslemIsletmeSilme,} IslemSirasi;
    /*!
    \class IslemDeposu::fb
    \brief Islem sirasi ÖNEMLİ, islem listesine append ederken islem sirasi enum
            sirasi ile aynı olmak zorunda!!'^!!'!'!!!'

                       */
    //0 dan başlayarak yazdığın kelimeler typedef gibi sayılar verir

    QAction* getAction(IslemSirasi x);
    void calistir(IslemSirasi y);
    std::shared_ptr<TemelKullaniciIslemi> getIslem(IslemSirasi z);

private:

    explicit IslemDeposu(QObject *parent = nullptr);
    QList<std::shared_ptr<TemelKullaniciIslemi>> _islemler;

signals:

};

#endif // ISLEMDEPOSU_H
