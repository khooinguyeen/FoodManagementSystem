#ifndef ADDRECIPE_H
#define ADDRECIPE_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class AddRecipe;
}

class AddRecipe : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecipe(QWidget *parent = nullptr);
    ~AddRecipe();

private slots:
    void on_btnSave_clicked();

    void on_btnReset_clicked();

private:
    Ui::AddRecipe *ui;
    QSqlDatabase database;
};

#endif // ADDRECIPE_H
