#ifndef TEMELVERISINIFI_H
#define TEMELVERISINIFI_H

#include <QObject>
#include <Veri/Tanimlar.h>
class temelverisinifi : public QObject
{
    Q_OBJECT
public:    
    Q_PROPERTY(Tamsayi id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(bool silindiMi READ silindiMi WRITE setSilindiMi NOTIFY silindiMiChanged)
    explicit temelverisinifi(QObject *parent = nullptr);


    Tamsayi id() const;
    bool silindiMi() const;


public slots:
    void setId(Tamsayi newId);
    void setSilindiMi(bool newSilindiMi);
signals:

    void idChanged(Tamsayi newId);

    void silindiMiChanged(bool newSilindiMi);

protected:
    Tamsayi _id;
    bool _silindiMi;
};

#endif // TEMELVERISINIFI_H
