#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

class Json {
    
public:
    Json(){};
    
    void Create(std::string file_name);
    void Read(std::string file_name);
    void Add(std::string task);
    void Write(std::string file_name);
    void Print();
    void Remove();
    
private:
    int m_task_id = 0;
    std::string m_file_name; 
    std::vector<std::map<std::string, std::string>> m_json_map;
    int GenerateID();
    
};
