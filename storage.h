#ifndef STORAGE_H
#define STORAGE_H

#include "list.h"

class Storage : public List
{
public:
    Storage();
    void addIngredient();
    void removeIngredient();
    void loadAllElements();
};

#endif // STORAGE_H
