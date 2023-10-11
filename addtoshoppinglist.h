#ifndef ADDTOSHOPPINGLIST_H
#define ADDTOSHOPPINGLIST_H

#include <QDialog>

namespace Ui {
class AddToShoppingList;
}

class AddToShoppingList : public QDialog
{
    Q_OBJECT

public:
    explicit AddToShoppingList(QWidget *parent = nullptr);
    ~AddToShoppingList();

private:
    Ui::AddToShoppingList *ui;
};

#endif // ADDTOSHOPPINGLIST_H
