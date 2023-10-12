#ifndef ADDTOSTORAGE_H
#define ADDTOSTORAGE_H

#include <QWidget>

namespace Ui {
class AddToStorage;
}

class AddToStorage : public QWidget
{
    Q_OBJECT

public:
    explicit AddToStorage(QWidget *parent = nullptr);
    ~AddToStorage();

private:
    Ui::AddToStorage *ui;
};

#endif // ADDTOSTORAGE_H
