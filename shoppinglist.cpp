#include "shoppinglist.h"

ShoppingList::ShoppingList() : List(){
    ptrAddToShoppingList = new AddToShoppingList();
    ptrRemoveFromShoppingList = new RemoveFromShoppingList();
}

void ShoppingList::addIngredient(){
    qDebug() << "add to ShoppingList";
    ptrAddToShoppingList->show();

}
void ShoppingList::removeIngredient(){
    qDebug() << "remove from ShoppingList";
    ptrRemoveFromShoppingList->show();
}
void ShoppingList::loadAllElements(){qDebug() << "load in ShoppingList";}

ShoppingList::~ShoppingList(){
    delete ptrAddToShoppingList;
    delete ptrRemoveFromShoppingList;
}
