#ifndef LIST_H
#define LIST_H

#include <QWidget>

namespace Ui {
class List;
}

class List : public QWidget
{
    Q_OBJECT

public:
    explicit List(QWidget *parent = nullptr);
    ~List();

private:
    Ui::List *ui;
};

#endif // LIST_H
