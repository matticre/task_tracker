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
    void Read();
    void Insert(std::map<std::string,std::string>);
    void Remove();
    
private:
    std::string m_file_name; 
    std::vector<std::map<std::string, std::string>> m_json_map;
};
