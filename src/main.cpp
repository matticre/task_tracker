#include <iostream>

#include "TaskManager.h"

int main (int argc, char *argv[]){
    TaskManager taskmanager;
    taskmanager.Open();    

    // std::cout << argc << std::endl;
    if (argc < 3){
        std::cerr << "Error! Missing arguments. \n"; 
        return 1;
    }

    std::string command(argv[1]);
    
    if (command == "add"){
        if (argc > 3){
            std::cerr << "Too many arguments!" << std::endl;
            return 2;
        }   
        std::string task_description = argv[2];
        taskmanager.Add(task_description);
    }
    else if (command == "update"){
        if (argc != 4){
            std::cerr << "Too many arguments!" << std::endl;
            return 2;
        }   

        std::string task_to_update  = argv[2];
        std::string new_description = argv[3];
        taskmanager.Update(task_to_update, new_description);
    }
    else if (command == "delete"){
        if (argc != 3){
            std::cerr << "Too many arguments!" << std::endl;
            return 2;
        }   

        std::string task_to_del = argv[2];
        taskmanager.Delete(task_to_del);
    }
    else if (command == "mark-in-progress"){
        if (argc != 3){
            std::cerr << "Too many arguments!" << std::endl;
            return 2;
        }   
        std::string task_to_mark = argv[2];
        taskmanager.Mark(task_to_mark, "in-progress");
    }
    else if (command == "mark-done"){
        if (argc != 3){
            std::cerr << "Too many arguments!" << std::endl;
            return 2;
        }   
        std::string task_to_mark = argv[2];
        taskmanager.Mark(task_to_mark, "done");
    }
    else if (command == "list"){
        if (argc == 2){
            taskmanager.List();
        } 
        else{
            std::string specifier(argv[3]);            
            taskmanager.List(specifier);
        }
    }

    // taskmanager.List();    
    // taskmanager.Update("task-001", "urcu liu");
    // taskmanager.Mark("task-001", "done");
    // taskmanager.List("in-progress");    

    return 0;
}