#ifndef REMOVEFROMSTORAGE_H
#define REMOVEFROMSTORAGE_H

#include <QWidget>
#include "databaseheader.h"

namespace Ui {
class RemoveFromStorage;
}

class RemoveFromStorage : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveFromStorage(QWidget *parent = nullptr);
    ~RemoveFromStorage();

private slots:
    void on_cbxRemoveIngredient_activated(int index);

    void on_btnOk_clicked();

    void on_btnCancel_clicked();

    void on_btnLoadStorage_clicked();

private:
    Ui::RemoveFromStorage *ui;
};

#endif // REMOVEFROMSTORAGE_H
