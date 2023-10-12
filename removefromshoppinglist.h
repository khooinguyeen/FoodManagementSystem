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
    explicit RemoveFromShoppingList(QWidget *parent = nullptr);
    void loadComboBox();
    ~RemoveFromShoppingList();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::RemoveFromShoppingList *ui;
    QSqlDatabase database;
};

#endif // REMOVEFROMSHOPPINGLIST_H
