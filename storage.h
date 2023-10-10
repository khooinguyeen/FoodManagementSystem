#ifndef STORAGE_H
#define STORAGE_H

#include <QDialog>
#include "databaseheader.h"
#include "addtostorage.h"
#include "removefromstorage.h"
//#include "list.h"


namespace Ui {
class Storage;
}

class Storage : public QDialog
{
    Q_OBJECT

public:
    explicit Storage(QWidget *parent = nullptr);
    void loadAllElements();
    ~Storage();

private slots:
    void on_listItemButton_clicked();

    void on_addButton_clicked();

    void on_removeButton_clicked();

private:
    Ui::Storage *ui;
    AddToStorage *ptrAddToStorage;
    RemoveFromStorage *ptrRemoveFromStorage;
    QSqlQueryModel *model;
};

#endif // STORAGE_H
