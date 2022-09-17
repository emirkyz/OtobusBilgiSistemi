#ifndef OTOBUSLISTELEMEISLEMI_H
#define OTOBUSLISTELEMEISLEMI_H

#include <QObject>
#include <Islemler/TemelKullaniciIslemi.h>
class OtobusListelemeIslemi : public QObject, public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit OtobusListelemeIslemi(QObject *parent = nullptr);

signals:
private:
    QAction* _islem;
public slots:
    void main() override;
public:
    QAction *islem() override;
};

#endif // OTOBUSLISTELEMEISLEMI_H
