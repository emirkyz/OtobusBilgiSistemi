#include "temelverisinifi.h"

temelverisinifi::temelverisinifi(QObject *parent)
    : QObject{parent}
{

}

Tamsayi temelverisinifi::id() const
{
    return _id;
}

void temelverisinifi::setId(Tamsayi newId)
{
    if (_id == newId)
        return;
    _id = newId;
    emit idChanged(_id);
}

bool temelverisinifi::silindiMi() const
{
    return _silindiMi;
}

void temelverisinifi::setSilindiMi(bool newSilindiMi)
{
    if (_silindiMi == newSilindiMi)
        return;
    _silindiMi = newSilindiMi;
    emit silindiMiChanged(_silindiMi);
}
