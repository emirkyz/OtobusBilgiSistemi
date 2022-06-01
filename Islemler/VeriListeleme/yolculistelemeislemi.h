#ifndef YOLCULISTELEMEISLEMI_H
#define YOLCULISTELEMEISLEMI_H

#include <QObject>
#include <Islemler/TemelKullaniciIslemi.h>
class YolcuListelemeIslemi : public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit YolcuListelemeIslemi(QObject *parent = nullptr);

signals:
private:
    QAction* _islem;
public slots:
    void main() override;
public:
    QAction *islem() override;
};

#endif // YOLCULISTELEMEISLEMI_H
