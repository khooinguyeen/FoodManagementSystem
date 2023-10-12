#ifndef STORAGE_H
#define STORAGE_H

#include "list.h"
#include "addtostorage.h"
#include "removefromstorage.h"

class Storage : public List
{
public:
    Storage(QWidget *parent = nullptr);
    void addIngredient();
    void removeIngredient();
    void loadAllElements();
    void showInfo();
    ~Storage();
private:
    AddToStorage* ptrAddToStorage;
    RemoveFromStorage* ptrRemoveFromStorage;

};


#endif // STORAGE_H
