#pragma once

#include "TaskListDecorator.hpp"
#include "Task.hpp"
#include "Observer.hpp"

#include <list>
#include <memory>

class ObservableTaskList: public TaskListDecorator{
private:
    std::list<Observer*> mObservers;
    void doUpdate();
    void doAction(int id);
public:
    ObservableTaskList(TaskList* list);
    ~ObservableTaskList();
    ObservableTaskList* attach(Observer* obs);
    ObservableTaskList* detach(Observer* obs);

    int newTask(const char* text) override;
    void done(int id) override;
    void draw() override;
    void renew(int id) override;
    void delay(int id) override;
    // @todo: #5 adding fileexistance checking 
    void load(const char* filename) override;
    void save(const char* filename) override;

};