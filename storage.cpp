#include "storage.h"

Storage::Storage(QWidget *parent) : List(parent){}

void Storage::addIngredient(){qDebug() << "add to Storage";}
void Storage::removeIngredient(){qDebug() << "remove from Storage";}
void Storage::loadAllElements(){qDebug() << "load all in Storage ";}
void Storage::showInfo(){qDebug() << "show Info in storage";}
