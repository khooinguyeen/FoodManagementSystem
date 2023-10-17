#ifndef LIST_H
#define LIST_H

#include <QWidget>
#include <QListWidget>
#include "databaseheader.h"

namespace Ui {
class List;
}

class List : public QWidget
{
    Q_OBJECT

public:
    // constructor to initialize ui pointer for List class
    explicit List(QWidget *parent = nullptr);
    // declare virtual function to implement funtionality for add button
    virtual void addIngredient() = 0;
    // declare virtual funciton to implement functionality for remove button
    virtual void removeIngredient() = 0;
    // declare virtual function to implement functionality for load button
    virtual void loadAllElements() = 0;
    // declare virtual function to implement functionality for list widget
    virtual void showInfo() = 0;
    // destructor to delete ui pointer
    ~List();

private slots:
    // declare signal function for add button
    void on_btnAdd_clicked();
    // declare signal function for remove button
    void on_btnRemove_clicked();
    // declare signal function for load button
    void on_btnLoad_clicked();
    // declare signal function for the list widget when each item is clicked
    void on_listWidget_itemClicked(QListWidgetItem *item);

protected:
    // declare pointer to the ui
    friend class TestStorage;
    Ui::List *ui;
    // declare database
    QSqlDatabase database;
};

#endif // LIST_H
