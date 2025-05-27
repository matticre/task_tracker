#include <iostream>
#include <fstream>
#include <vector>

#include "TaskStructure.h"

class TaskManager {
    
    public:
        TaskManager();
        void Open();
        void Close();
        void Add();
        void Update();
        void Delete();
        void List(); // ALL, DONE, NOT DONE, PROGRESS
        void Mark();
    
    private:
        std::vector<TaskStructure> task_list = {};

};