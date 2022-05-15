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

private:
    Ui::IsletmeListesi *ui;
};

#endif // ISLETMELISTESI_H
