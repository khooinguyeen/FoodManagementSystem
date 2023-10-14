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
    // Constructor to initialize the ui pointer
    explicit RemoveFromStorage(QWidget *parent = nullptr);
    // Destructor to delete the ui pointer
    ~RemoveFromStorage();

private slots:
    // signal function to implement functionality for combo box
    void on_cbxRemoveIngredient_activated(int index);
    // signal function for ok button
    void on_btnOk_clicked();
    // signal function for cancel button
    void on_btnCancel_clicked();
    // signal functionf or load button
    void on_btnLoadStorage_clicked();

private:
    // declare ui pointer
    Ui::RemoveFromStorage *ui;
};

#endif // REMOVEFROMSTORAGE_H
