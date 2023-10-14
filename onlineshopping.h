#ifndef ONLINESHOPPING_H
#define ONLINESHOPPING_H

#include "shoppinglist.h"

class OnlineShopping : public ShoppingList
{
public:
    OnlineShopping(QWidget *parent = nullptr);
    void loadAllElements() override;
    void showLink();
    void showInfo() override;
};

#endif // ONLINESHOPPING_H
