#include <filesystem>

#include "TaskManager.h"

TaskManager::TaskManager(){

}

void TaskManager::Open(){
    
    std::filesystem::path execPath = std::filesystem::current_path();
    std::string filePath = execPath.string() + "/tasks.json";

    
    std::ifstream file("tasks-belin.json");
    std::string temp_string;

    while (file >> temp_string){
        // std::cout << temp_string << "\n";
        if (temp_string == "{"){
            TaskStructure temp_structure;
            temp_structure.StoreStructure(file);
            task_list.push_back(temp_structure);
        }
    }

    file.close();
    m_id = task_list.size();
    Write();
}

void TaskManager::List(const std::string& selection){

    if (selection == "all"){
        for (const auto task : task_list){
            task.PrintTask();
        }
    }

    else if (selection == "todo" || selection == "in-progress" || selection == "done") {
        for (const auto task : task_list){
            if (task.status == selection)
                task.PrintTask();
        }
    }

    else {
        std::cerr << "Status not allowed! \n";
        return;
    }

}

void TaskManager::Add(const TaskStructure &task){
    task_list.push_back(task);
    Write();
}

void TaskManager::Add(const std::string &task_description){
    int task_id = m_id + 1;
    TaskStructure new_task(task_id, task_description);
    task_list.push_back(new_task);
    Write();
}

void TaskManager::Update(const std::string& task_id, 
                         const std::string& new_description){
    int  idx_to_up;
    bool to_up = false;

    for (int i = 0; i < task_list.size(); ++i){
        if (task_list[i].id == task_id){
            to_up    = true;
            idx_to_up = i;
            break;
        }
    }       

    if (to_up)
        task_list[idx_to_up].description = new_description;
    else
        std::cerr << "Task not found!\n";

    Write();
}

void TaskManager::Delete(const std::string &task_id){
    int  idx_to_del;
    bool to_del = false;

    for (int i = 0; i < task_list.size(); ++i){
        if (task_list[i].id == task_id){
            to_del     = true;
            idx_to_del = i;
            break;
        }
    }

    if (to_del)
        task_list.erase(task_list.begin() + idx_to_del);
    else
        std::cerr << "Task not found!\n";

    Write();
}

void TaskManager::Mark(const std::string& task_id,
                       const std::string& status){
    

    bool check = status == "done";
    check = check || (status == "in-progress");
    if (!check){
        std::cerr << "Status not allowed! \n";
        return;
    }

    int  idx_to_up;
    bool to_up;

    for (int i = 0; i < task_list.size(); ++i){
        if (task_list[i].id == task_id){
            to_up     = true;
            idx_to_up = i;
            break;
        }
    }

    if (to_up)
        task_list[idx_to_up].status = status;
    
    Write();

}

void TaskManager::Write(){
    std::ofstream file("tasks.json");
    file << "[ \n";
    
    for (const auto & item : task_list){
        file << "    {\n"
             << "        \"id\": " << "\"" << item.id << "\",\n"
             << "        \"description\": " << "\"" << item.description << "\",\n"
             << "        \"status\": " << "\"" << item.status << "\",\n"
             << "        \"createdAt\": " << "\"" << item.createdAt << "\",\n"
             << "        \"updatedAt\": " << "\"" << item.updatedAt << "\"\n"     
             << "    },\n";
    }
    
    file << "] \n";

}