#ifndef TANIMLAR_H
#define TANIMLAR_H

#include <memory>
#include <QDateTime>
#include <QString>
#include <QList>

typedef QString Metin;
typedef int Tamsayi;
typedef enum { Kadin = 1, Erkek = 2 } Cinsiyet;
typedef QDate Tarih;
typedef QTime Saat;
typedef QDateTime TarihSaat;

class IsletmeBilgileri;
class OtobusBilgileri;
class Seferbilgileri;
class Yolcubilgileri;
class Seyehatkurallari;
class Soforbilgileri;
class Biletbilgileri;
class Seyehatbilgileri;

typedef std::shared_ptr<IsletmeBilgileri> IsletmeBilgileriPtr ;
typedef std::shared_ptr<OtobusBilgileri> OtobusBilgileriPtr ;
typedef std::shared_ptr<Seferbilgileri> SeferbilgileriPtr ;
typedef std::shared_ptr<Yolcubilgileri> YolcubilgileriPtr ;
typedef std::shared_ptr<Seyehatkurallari> SeyehatKurallariPtr ;
typedef std::shared_ptr<Soforbilgileri> SoforbilgileriPtr;
typedef std::shared_ptr<Biletbilgileri> BiletbilgileriPtr;
typedef std::shared_ptr<Seyehatbilgileri> SeyehatbilgileriPtr;



typedef QList<IsletmeBilgileriPtr> IsletmeBilgileriListesi;
typedef QList<OtobusBilgileriPtr> OtobusBilgileriListesi ;
typedef QList<SeferbilgileriPtr> SeferbilgileriListesi ;
typedef QList<YolcubilgileriPtr> YolcubilgileriListesi;
typedef QList<SeyehatKurallariPtr> SeyehatKurallariListesi;
typedef QList<SoforbilgileriPtr> SoforbilgileriListesi;
typedef QList<BiletbilgileriPtr> BiletbilgileriListesi;
typedef QList<SeyehatbilgileriPtr> SeyehatListesi;

class IsletmeDeposu;
class OtobusDeposu;
class SeferDeposu;
class YolcuDeposu;
class SeyehatKurallariDeposu;
class SoforDeposu;
class BiletDeposu;
class SeyehatDeposu;









#endif // TANIMLAR_H
