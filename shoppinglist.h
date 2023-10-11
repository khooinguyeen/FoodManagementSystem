#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include "list.h"

class ShoppingList : public List
{
public:
    ShoppingList();
    void addIngredient();
    void removeIngredient();
    void loadAllElements();
};

#endif // SHOPPINGLIST_H
