#include "removefromstorage.h"
#include "ui_removefromstorage.h"

RemoveFromStorage::RemoveFromStorage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RemoveFromStorage)
{
    ui->setupUi(this);
}

RemoveFromStorage::~RemoveFromStorage()
{
    delete ui;
}
