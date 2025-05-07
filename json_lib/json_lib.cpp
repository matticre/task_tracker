#include "json_lib.h"
#include "string_management.h"

#include <ctime>

void Json::Create(std::string file_name){
    m_file_name = file_name;
    std::ofstream file(m_file_name);
    file << "[\n" << "]\n";
    file.close();
}

void Json::Read(std::string file_name){
    m_file_name = file_name;
    std::ifstream file(m_file_name);
    std::string line, task, task_id, delimiter;
    std::map<std::string, std::string> temp_map;
    
    while (file >> line){
        if (line.find("{") != std::string::npos){
            std::string task_label, task, task_id_label, task_id, delimiter;
            file >> task_label >> delimiter >> task >> task_id_label >> delimiter >> task_id;
            temp_map["task"]    = GetTask(task);
            temp_map["task_id"] = GetTaskId(task_id);
            m_json_map.push_back(temp_map);
        }
    }
    
    file.close();
}

void Json::Write(std::string file_name){
    std::ofstream file(file_name);
    file << "[\n";
    
    for (auto map = m_json_map.begin(); map != m_json_map.end(); map++){
        file << "  {\n";
        for (auto it = (*map).begin(); it != (*map).end(); it++){
            file << "    \"" << (*it).first << "\" : \"" << (*it).second << "\"";
            if (std::next(it) != (*map).end())
                file << ",";
            file << "\n";
        }
        
        file << "  }";
        if (std::next(map) != m_json_map.end())
            file << ",";
        file << "\n";
    }

    file << "]\n";
    file.close();
}

void Json::Add(std::string task){
    std::map<std::string, std::string> temp_map;
    temp_map["task"]    = task;
    temp_map["task_id"] = std::to_string(this->GenerateID());
    temp_map["status"] = "None";
    temp_map["created_at"] = "NaN";
    temp_map["updated_at"] = "NaN";

    m_json_map.push_back(temp_map);

}

void Json::Remove(){}

void Json::Print(){
    for(const auto &map : m_json_map){
        for (const auto &item : map){
            std::cout << item.first << " : " << item.second <<  "\n";
        }
        std::cout << "\n";
    }
}

int Json::GenerateID(){
    return ++m_task_id;
}



