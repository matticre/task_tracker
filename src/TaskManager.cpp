#include <filesystem>

#include "TaskManager.h"

TaskManager::TaskManager(){

}

void TaskManager::Open(){
    
    std::filesystem::path execPath = std::filesystem::current_path();
    std::string filePath = execPath.string() + "/tasks.json";

    
    std::ifstream file("tasks.json");
    std::string temp_string;

    while (file >> temp_string){
        if (temp_string == "{"){
            TaskStructure temp_structure;
            temp_structure.StoreStructure(file);
            task_list.push_back(temp_structure);
        }
    }

    file.close();
}

void TaskManager::List(){

    for (const auto task : task_list){
        task.PrintTask();
    }
}