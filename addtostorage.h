#ifndef ADDTOSTORAGE_H
#define ADDTOSTORAGE_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class AddToStorage;
}

class AddToStorage : public QDialog
{
    Q_OBJECT

public:
    explicit AddToStorage(QWidget *parent = nullptr);
    ~AddToStorage();

private slots:
    void on_btnReset_clicked();

    void on_btnSave_clicked();

private:
    Ui::AddToStorage *ui;
};

#endif // ADDTOSTORAGE_H
