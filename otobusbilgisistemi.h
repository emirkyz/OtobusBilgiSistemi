#ifndef OTOBUSBILGISISTEMI_H
#define OTOBUSBILGISISTEMI_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class OtobusBilgiSistemi; }
QT_END_NAMESPACE

class OtobusBilgiSistemi : public QMainWindow
{
    Q_OBJECT

public:
    OtobusBilgiSistemi(QWidget *parent = nullptr);
    ~OtobusBilgiSistemi();

private:
    Ui::OtobusBilgiSistemi *ui;

};
#endif // OTOBUSBILGISISTEMI_H
