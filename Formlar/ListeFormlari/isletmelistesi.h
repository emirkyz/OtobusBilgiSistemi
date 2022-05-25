#ifndef ISLETMELISTESI_H
#define ISLETMELISTESI_H

#include <QWidget>
#include <Veri/Tanimlar.h>

namespace Ui {
class IsletmeListesi;
}

class IsletmeListesi : public QWidget
{
    Q_OBJECT

public:
    explicit IsletmeListesi(QWidget *parent = nullptr);
    ~IsletmeListesi();

    const IsletmeBilgileriListesi &liste() const;
    void setListe(const IsletmeBilgileriListesi &newListe);

private:
    Ui::IsletmeListesi *ui;
    IsletmeBilgileriListesi _liste;
    void ekranGuncelle();
};

#endif // ISLETMELISTESI_H
