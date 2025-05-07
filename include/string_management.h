#pragma once

#include <string>


std::string GetTask(const std::string &raw_task){
    std::string task;
    for (int i = 1; i < raw_task.length() - 2; ++i){
        task.push_back(raw_task[i]);
    }
    // std::cout << task << std::endl;
    return task;
}

std::string GetTaskId(const std::string &raw_task_id){
    std::string task_id;
    for (int i = 1; i < raw_task_id.length() - 1; ++i){
        task_id.push_back(raw_task_id[i]);
    }
    return task_id;
}