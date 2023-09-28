#ifndef REMOVERECIPE_H
#define REMOVERECIPE_H

#include <QDialog>

namespace Ui {
class RemoveRecipe;
}

class RemoveRecipe : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveRecipe(QWidget *parent = nullptr);
    ~RemoveRecipe();

private:
    Ui::RemoveRecipe *ui;
};

#endif // REMOVERECIPE_H
