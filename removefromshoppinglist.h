#ifndef REMOVEFROMSHOPPINGLIST_H
#define REMOVEFROMSHOPPINGLIST_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class RemoveFromShoppingList;
}

class RemoveFromShoppingList : public QDialog
{
    Q_OBJECT

public:
    // constructor to open window for RemoveFromShoppingList class
    explicit RemoveFromShoppingList(QWidget *parent = nullptr);
    // function to implement the combo box
    void loadComboBox();
    // destructor to delete ui pointer
    ~RemoveFromShoppingList();

private slots:
    // signal function to delete ingredient from the database
    void on_buttonBox_accepted();

private:
    // declare ui pointer
    Ui::RemoveFromShoppingList *ui;
    // declare database
    QSqlDatabase database;
};

#endif // REMOVEFROMSHOPPINGLIST_H
