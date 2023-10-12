#ifndef ADDTOSHOPPINGLIST_H
#define ADDTOSHOPPINGLIST_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class AddToShoppingList;
}

class AddToShoppingList : public QDialog
{
    Q_OBJECT

public:
    explicit AddToShoppingList(QWidget *parent = nullptr);
    ~AddToShoppingList();
    void loadComboBox();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddToShoppingList *ui;
    QSqlDatabase database;
};

#endif // ADDTOSHOPPINGLIST_H
