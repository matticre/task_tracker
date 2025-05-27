#include <iostream>

#include "TaskManager.h"

using namespace std;

int main (){
    TaskManager taskmanager;
    taskmanager.Open();    
    taskmanager.List();    

    return 0;
}