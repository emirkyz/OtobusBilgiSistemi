#ifndef ISLETMELISTESIISLEMI_H
#define ISLETMELISTESIISLEMI_H
#include <QObject>
#include <Islemler/TemelKullaniciIslemi.h>

class IsletmeListesiIslemi : public QObject,public TemelKullaniciIslemi
{
    Q_OBJECT
public:
    explicit IsletmeListesiIslemi(QObject *parent = nullptr);

signals:
private:
    QAction* _islem;
public slots:
    void main() override;
public:
    QAction *islem() override;
};

#endif // ISLETMELISTESIISLEMI_H
