/* gestisce tutte le categorie nel loro insieme:
le stampa
le aggiunge e rimuove */


#include "categorymanager.h"

CategoryManager::CategoryManager() {}

// stampa descrizione di ogni categoria solo se ce ne sono
void CategoryManager::print(){
    qDebug()<<"Elenco categorie: ";
    if (categoryCollection.isEmpty()){
        qDebug()<<"lista categorie vuota";
    }
    else {
        for (auto category : categoryCollection){
            qDebug()<<category->getDescription()<<category->getTotalTask()<<category->getCompletedTask();
        }
    }
}

void CategoryManager::addCategory(Category* category){
    categoryCollection.push_back(category);
}

void CategoryManager::removeCategory(Category* category) {
    categoryCollection.removeOne(category);
    if (category) delete category;
}

CategoryManager::~CategoryManager(){}