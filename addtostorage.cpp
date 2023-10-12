#include "addtostorage.h"
#include "ui_addtostorage.h"

AddToStorage::AddToStorage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddToStorage)
{
    ui->setupUi(this);
}

AddToStorage::~AddToStorage()
{
    delete ui;
}
