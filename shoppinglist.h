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
    // Constructor to inherit the ui from List class and open two windows: market purshasing and online shopping
    ShoppingList(QWidget *parent = nullptr);
    // implement the add button
    void addIngredient();
    // implement the remove button
    void removeIngredient();
    // implement the load button
    void loadAllElements();
    // implement the list widget to show all ingredients from ShoppingList database
    void showInfo();
    // destructor to delete the ui pointers
    ~ShoppingList();

private:
    // declare ui pointers for AddToshoppingList class and RemoveFromShoppingList class
    AddToShoppingList *ptrAddToShoppingList;
    RemoveFromShoppingList *ptrRemoveFromShoppingList;
};

#endif // SHOPPINGLIST_H
