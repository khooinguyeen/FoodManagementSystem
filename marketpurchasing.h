#ifndef MARKETPURCHASING_H
#define MARKETPURCHASING_H

#include "shoppinglist.h"

class MarketPurchasing : public ShoppingList
{
    Q_OBJECT
public:
    MarketPurchasing(QWidget *parent = nullptr);
    void loadAllElements() override;
    void showMarketInfo();
    void showInfo() override;
};

#endif // MARKETPURCHASING_H
