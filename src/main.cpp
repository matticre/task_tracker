#include <iostream>

#include "TaskManager.h"

int main (){
    TaskManager taskmanager;
    taskmanager.Open();    
    // taskmanager.List();    
    taskmanager.Update("task-001", "urcu liu");
    taskmanager.Mark("task-001", "done");
    taskmanager.List("in-progress");    

    return 0;
}