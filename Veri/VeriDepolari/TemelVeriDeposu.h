#ifndef TEMELVERIDEPOSU_H
#define TEMELVERIDEPOSU_H
#include <Veri/Tanimlar.h>
#include <functional>

template <class Data> class TemelVeriDeposu {
public:
    typedef std::shared_ptr<Data> DataPtr;
    typedef QList<DataPtr> DataList;

    TemelVeriDeposu() : _veriler{100}, _sonId(0){}

    inline DataPtr yeniNesne(){ return std::make_shared<Data>();  }

    typedef std::function<bool(DataPtr)> FiltreFonksiyonu;

    bool nesneEkle(DataPtr veri) {
        for (const auto &kayitliVeri : _veriler) {
          if (veri->id() == kayitliVeri->id()) {
            return false;
          }
        }
        _sonId++;
        veri->setId(_sonId);
        veri->setSilindiMi(false);
        _veriler.append(veri);
        return true;
      }

    bool nesneSil(DataPtr silinecekVeri) {
       for (const auto &kayitliVeri : _veriler) {
         if (silinecekVeri->id() == kayitliVeri->id()) {
           kayitliVeri->setSilindiMi(true);
           return true;
         }
       }
       return false;
     }

    DataPtr ilkiniBul(FiltreFonksiyonu f) {
      for (auto i = _veriler.begin(); i != _veriler.end(); i++) {
        auto veri = *i;
        if (veri->silindiMi() == false && f(veri) == true) {
          return veri;
        }
      }
      return DataPtr(nullptr);
    }

    DataPtr sonuncuyuBul(FiltreFonksiyonu f) {
      for (auto i = _veriler.rbegin(); i != _veriler.rend(); i++) {
        auto veri = *i;
        if (veri->silindiMi() == false && f(veri) == true) {
          return veri;
        }
      }
      return DataPtr(nullptr);
    }

    DataList tumunuBul(FiltreFonksiyonu f) {
      DataList sonuc;
      for (auto i = _veriler.begin(); i != _veriler.end(); i++) {
        auto veri = *i;
        if (veri->silindiMi() == false && f(veri) == true) {
          sonuc.append(veri);
        }
      }
      return sonuc;
    }

    Tamsayi kacTaneVar(FiltreFonksiyonu f) {
        Tamsayi sonuc = 0;
        for (const auto &veri : _veriler) {
            if (veri->silindiMi() == false && f(veri) == true) {
                sonuc++;
            }
        }
        return sonuc;
    }

protected:
    DataList _veriler;
    Tamsayi _sonId;    
};

template <class Data>
QDataStream &operator<<(QDataStream &stream, const std::shared_ptr<Data> &veri){
    stream << *veri;
    return stream;
}
template <class Data>
QDataStream &operator>>(QDataStream &stream, std::shared_ptr<Data> &veri){
    veri = std::make_shared<Data>();
    stream >> *veri;
    return stream;
}


#endif // TEMELVERIDEPOSU_H
