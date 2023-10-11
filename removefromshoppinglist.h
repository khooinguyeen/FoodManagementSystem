#ifndef REMOVEFROMSHOPPINGLIST_H
#define REMOVEFROMSHOPPINGLIST_H

#include <QDialog>

namespace Ui {
class RemoveFromShoppingList;
}

class RemoveFromShoppingList : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveFromShoppingList(QWidget *parent = nullptr);
    ~RemoveFromShoppingList();

private:
    Ui::RemoveFromShoppingList *ui;
};

#endif // REMOVEFROMSHOPPINGLIST_H
