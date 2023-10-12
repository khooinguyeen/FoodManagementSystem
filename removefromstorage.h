#ifndef REMOVEFROMSTORAGE_H
#define REMOVEFROMSTORAGE_H

#include <QWidget>

namespace Ui {
class RemoveFromStorage;
}

class RemoveFromStorage : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveFromStorage(QWidget *parent = nullptr);
    ~RemoveFromStorage();

private:
    Ui::RemoveFromStorage *ui;
};

#endif // REMOVEFROMSTORAGE_H
