#include "ObservableTaskList.hpp"

Observer::~Observer(){}

ObservableTaskList::ObservableTaskList(TaskList* list):
    TaskListDecorator(list), mObservers()
{}

ObservableTaskList::~ObservableTaskList(){
    while(mObservers.size() > 0){
        Observer* p = mObservers.front();
        mObservers.pop_front();
        delete p;
    }
}

void ObservableTaskList::doUpdate(){
    for(auto p = mObservers.begin(); p != mObservers.end(); ++p){
        Observer* i = *p;
        i->onUpdate(this);
    } 
}

void ObservableTaskList::doAction(int id){
    for(auto p = mObservers.begin(); p != mObservers.end(); ++p){
        Observer* i = *p;
        i->onAction(this, id);
    } 
}

ObservableTaskList* ObservableTaskList::attach(Observer* obs){
    mObservers.push_back(obs);
    return this;
}

ObservableTaskList* ObservableTaskList::detach(Observer* obs){
    mObservers.remove(obs);
    delete obs;
    return this;
}

int ObservableTaskList::newTask(const char* text){
    int id = TaskListDecorator::newTask(text);
    doAction(id);
    return id;
}

void ObservableTaskList::done(int id){
    TaskListDecorator::done(id);
    doAction(id);
}

void ObservableTaskList::draw(){
    TaskListDecorator::draw();
    doUpdate();
}

void ObservableTaskList::renew(int id){
    TaskListDecorator::renew(id);
    doAction(id);
}

void ObservableTaskList::delay(int id){
    TaskListDecorator::delay(id);
    doAction(id); 
}

void ObservableTaskList::load(const char* filename){
    TaskListDecorator::load(filename);
    doUpdate();
}

// @todo: #6 remove overriding for this functions
void ObservableTaskList::save(const char* filename){
    TaskListDecorator::save(filename);
}
