#ifndef MARKETPURCHASING_H
#define MARKETPURCHASING_H

#include "shoppinglist.h"

class MarketPurchasing : public ShoppingList
{
    Q_OBJECT
public:
    MarketPurchasing(QWidget *parent = nullptr);
    // override the virtual function to load only ingredient with market info on the list widget
    void loadAllElements() override;
    // function to show ingredient info on the text box
    void showMarketInfo();
    // override the virtual function for showing choosen ingredient info with market details
    void showInfo() override;
};

#endif // MARKETPURCHASING_H
