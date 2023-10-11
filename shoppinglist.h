#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include "list.h"
#include "addtoshoppinglist.h"
#include "removefromshoppinglist.h"

class ShoppingList : public List
{
public:
    ShoppingList();
    void addIngredient();
    void removeIngredient();
    void loadAllElements();
    ~ShoppingList();

private:
    AddToShoppingList *ptrAddToShoppingList;
    RemoveFromShoppingList *ptrRemoveFromShoppingList;
};

#endif // SHOPPINGLIST_H
