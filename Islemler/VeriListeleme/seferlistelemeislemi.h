#ifndef SEFERLISTELEMEISLEMI_H
#define SEFERLISTELEMEISLEMI_H

#include <QObject>
#include <Islemler/TemelKullaniciIslemi.h>
class SeferListelemeIslemi : public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit SeferListelemeIslemi(QObject *parent = nullptr);

signals:
private:
    QAction* _islem;
public slots:
    void main() override;
public:
    QAction *islem() override;

};

#endif // SEFERLISTELEMEISLEMI_H
