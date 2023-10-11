#include "shoppinglist.h"

ShoppingList::ShoppingList() : List(){}

void ShoppingList::addIngredient(){qDebug() << "add to ShoppingList";}
void ShoppingList::removeIngredient(){qDebug() << "remove from ShoppingList";}
void ShoppingList::loadAllElements(){qDebug() << "load in ShoppingList";}
void ShoppingList::showInfo(){qDebug() << "show ingredient info in ShoppingList";}

