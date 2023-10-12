#ifndef STORAGE_H
#define STORAGE_H

#include "list.h"

class Storage : public List
{
public:
    Storage(QWidget *parent = nullptr);
    void addIngredient();
    void removeIngredient();
    void loadAllElements();
    void showInfo();
};

#endif // STORAGE_H
