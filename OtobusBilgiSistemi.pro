QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Formlar/VeriFormlari/isletmeverigirisformu.cpp \
    Formlar/VeriFormlari/otobusgirisformu.cpp \
    Formlar/VeriFormlari/seferverigirisformu.cpp \
    Formlar/VeriFormlari/seyehatkurallariverigirisformu.cpp \
    Formlar/VeriFormlari/seyehatverigirisformu.cpp \
    Formlar/VeriFormlari/soforverigirisformu.cpp \
    Formlar/VeriFormlari/yolcugirisformu.cpp \
    Islemler/VeriGirisi/isletmegirisislemi.cpp \
    Islemler/VeriGirisi/otobusgirisislemi.cpp \
    Islemler/VeriGirisi/sefergirisislemi.cpp \
    Islemler/VeriGirisi/seyehatgirisislemi.cpp \
    Islemler/VeriGirisi/seyehatkurallariislemi.cpp \
    Islemler/islemdeposu.cpp \
    Islemler/tumkullaniciislemleri.cpp \
    Veri/VeriDepolari/biletdeposu.cpp \
    Veri/VeriDepolari/isletmedeposu.cpp \
    Veri/VeriDepolari/otobusdeposu.cpp \
    Veri/VeriDepolari/seferdeposu.cpp \
    Veri/VeriDepolari/seyehatdeposu.cpp \
    Veri/VeriDepolari/seyehatkurallarideposu.cpp \
    Veri/VeriDepolari/sofordeposu.cpp \
    Veri/VeriDepolari/yolcudeposu.cpp \
    Veri/VeriSiniflari/biletbilgileri.cpp \
    Veri/VeriSiniflari/insan.cpp \
    Veri/VeriSiniflari/isletmebilgileri.cpp \
    Veri/VeriSiniflari/otobusbilgileri.cpp \
    Veri/VeriSiniflari/seferbilgileri.cpp \
    Veri/VeriSiniflari/seyehatbilgileri.cpp \
    Veri/VeriSiniflari/seyehatkurallari.cpp \
    Veri/VeriSiniflari/soforbilgileri.cpp \
    Veri/VeriSiniflari/temelverisinifi.cpp \
    Veri/VeriSiniflari/yolcubilgileri.cpp \
    Veri/data.cpp \
    main.cpp \
    otobusbilgisistemi.cpp

HEADERS += \
    Formlar/VeriFormlari/TemelVeriGirisi.h \
    Formlar/VeriFormlari/isletmeverigirisformu.h \
    Formlar/VeriFormlari/otobusgirisformu.h \
    Formlar/VeriFormlari/seferverigirisformu.h \
    Formlar/VeriFormlari/seyehatkurallariverigirisformu.h \
    Formlar/VeriFormlari/seyehatverigirisformu.h \
    Formlar/VeriFormlari/soforverigirisformu.h \
    Formlar/VeriFormlari/yolcugirisformu.h \
    Islemler/TemelKullaniciIslemi.h \
    Islemler/VeriGirisi/isletmegirisislemi.h \
    Islemler/VeriGirisi/otobusgirisislemi.h \
    Islemler/VeriGirisi/sefergirisislemi.h \
    Islemler/VeriGirisi/seyehatgirisislemi.h \
    Islemler/VeriGirisi/seyehatkurallariislemi.h \
    Islemler/islemdeposu.h \
    Islemler/tumkullaniciislemleri.h \
    Veri/Tanimlar.h \
    Veri/VeriDepolari/TemelVeriDeposu.h \
    Veri/VeriDepolari/biletdeposu.h \
    Veri/VeriDepolari/isletmedeposu.h \
    Veri/VeriDepolari/otobusdeposu.h \
    Veri/VeriDepolari/seferdeposu.h \
    Veri/VeriDepolari/seyehatdeposu.h \
    Veri/VeriDepolari/seyehatkurallarideposu.h \
    Veri/VeriDepolari/sofordeposu.h \
    Veri/VeriDepolari/yolcudeposu.h \
    Veri/VeriSiniflari/biletbilgileri.h \
    Veri/VeriSiniflari/insan.h \
    Veri/VeriSiniflari/isletmebilgileri.h \
    Veri/VeriSiniflari/otobusbilgileri.h \
    Veri/VeriSiniflari/seferbilgileri.h \
    Veri/VeriSiniflari/seyehatbilgileri.h \
    Veri/VeriSiniflari/seyehatkurallari.h \
    Veri/VeriSiniflari/soforbilgileri.h \
    Veri/VeriSiniflari/temelverisinifi.h \
    Veri/VeriSiniflari/yolcubilgileri.h \
    Veri/data.h \
    otobusbilgisistemi.h

FORMS += \
    Formlar/VeriFormlari/isletmeverigirisformu.ui \
    Formlar/VeriFormlari/otobusgirisformu.ui \
    Formlar/VeriFormlari/seferverigirisformu.ui \
    Formlar/VeriFormlari/seyehatkurallariverigirisformu.ui \
    Formlar/VeriFormlari/seyehatverigirisformu.ui \
    Formlar/VeriFormlari/soforverigirisformu.ui \
    Formlar/VeriFormlari/yolcugirisformu.ui \
    otobusbilgisistemi.ui

TRANSLATIONS += \
    OtobusBilgiSistemi_tr_TR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Kaynaklar.qrc

DISTFILES += \
    Resimler/64_bit.png \
    Resimler/accept.png \
    Resimler/book-addresses-error.png \
    Resimler/building-add.png \
    Resimler/bus.png \
    Resimler/cancel.png \
    Resimler/file_save_as.png \
    Resimler/user.png \
    Resimler/user_silhouette.png
