#ifndef ONLINESHOPPING_H
#define ONLINESHOPPING_H

#include "shoppinglist.h"

class OnlineShopping : public ShoppingList
{
public:
    OnlineShopping(QWidget *parent = nullptr);
    // override the virtual function to load only ingredient with link on the list widget
    void loadAllElements() override;
    // function to show ingredient info on the text box
    void showLink();
    // override the virtual function for showing choosen ingredient info with links
    void showInfo() override;
};

#endif // ONLINESHOPPING_H
