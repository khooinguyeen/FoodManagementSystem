#ifndef STORAGE_H
#define STORAGE_H

#include "list.h"
#include "addtostorage.h"
#include "removefromstorage.h"

class Storage : public List
{
public:
    // default constructor for ui that inherited from list class
    Storage(QWidget *parent = nullptr);
    // add ingredient into the storage database (virtual)
    void addIngredient();
    // remove ingredient from the storage database (virtual)
    void removeIngredient();
    // load all ingredients to the list widget
    void loadAllElements();
    // show the ingredient details on the text box
    void showInfo();
    // destructor to clear ui pointers
    ~Storage();
    friend class TestStorage;
private:
    // declare pointers to ui for AddToStorage and RemoveFromStorage class
    AddToStorage* ptrAddToStorage;
    RemoveFromStorage* ptrRemoveFromStorage;

};


#endif // STORAGE_H
