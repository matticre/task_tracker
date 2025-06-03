#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "TaskStructure.h"

class TaskManager {
    
    public:
        TaskManager();
        void Open(); //FATTO
        void Close();  

        void Add(const TaskStructure &task);
        void Add(const std::string &task);

        void Update(const std::string& task_id, 
                    const std::string& new_description);
        void Delete(const std::string &str_id);
        void List(const std::string& selection = "all"); // ALL, DONE, TODO, PROGRESS
        void Mark(const std::string& task_id,
                  const std::string& status);
        void Write();
    
    private:
        int m_id = 0;
        std::vector<TaskStructure> task_list = {};

};