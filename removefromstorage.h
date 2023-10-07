#ifndef REMOVEFROMSTORAGE_H
#define REMOVEFROMSTORAGE_H

#include <QDialog>

namespace Ui {
class RemoveFromStorage;
}

class RemoveFromStorage : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveFromStorage(QWidget *parent = nullptr);
    ~RemoveFromStorage();

private slots:
    void on_acceptButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::RemoveFromStorage *ui;
};

#endif // REMOVEFROMSTORAGE_H
