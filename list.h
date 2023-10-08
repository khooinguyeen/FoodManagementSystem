#ifndef LIST_H
#define LIST_H
#include "databaseheader.h"

class List
{

private:

private slots:
    virtual void on_listItemButton_clicked() = 0;

    virtual void on_addButton_clicked() = 0;

    virtual void on_removeButton_clicked() = 0;

public:
    List();
    virtual void loadAllIngredients();
    virtual ~List();

};

#endif // LIST_H
