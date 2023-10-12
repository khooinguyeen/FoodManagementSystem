#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include "list.h"
#include "addtoshoppinglist.h"
#include "removefromshoppinglist.h"
#include "ui_list.h"

class ShoppingList : public List
{
    Q_OBJECT

public:
    ShoppingList(QWidget *parent = nullptr);
    void addIngredient();
    void removeIngredient();
    void loadAllElements();
    void showInfo();
    ~ShoppingList();

private:
    AddToShoppingList *ptrAddToShoppingList;
    RemoveFromShoppingList *ptrRemoveFromShoppingList;
};

#endif // SHOPPINGLIST_H
