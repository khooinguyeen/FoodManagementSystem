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
    explicit List(QWidget *parent = nullptr);
    virtual void addIngredient() = 0;
    virtual void removeIngredient() = 0;
    virtual void loadAllElements() = 0;
    virtual void showInfo() = 0;
    ~List();

private slots:
    void on_btnAdd_clicked();

    void on_btnRemove_clicked();

    void on_btnLoad_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

protected:
    Ui::List *ui;
    QSqlDatabase database;
};

#endif // LIST_H
