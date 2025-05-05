#include "json_lib.h"

void Json::Create(std::string file_name){
    m_file_name = file_name;
    std::ofstream file(m_file_name);
    file << "[\n" << "]\n";
    file.close();
}

void Json::Read(){
    
}

void Json::Insert(std::map<std::string,std::string> new_element){
    m_json_map.push_back(new_element);
    
    std::ofstream file(m_file_name);
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

void Json::Remove(){}
