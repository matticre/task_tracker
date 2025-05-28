#pragma once

#include <string>
#include <fstream>
#include <algorithm>

struct TaskStructure {
      std::string id;
      std::string description;
      std::string status;
      std::string createdAt;
      std::string updatedAt;

      void StoreStructure(std::ifstream &file){
            std::string line;

            std::getline(file, line, ':');
            std::getline(file, id, ',');
            
            std::getline(file, line, ':');
            std::getline(file, description, ',');

            std::getline(file, line, ':');
            std::getline(file, status, ',');

            std::getline(file, line, ':');
            std::getline(file, createdAt, ',');

            std::getline(file, line, ':');
            std::getline(file, updatedAt, ',');

            CleanFields();   
      }

      void CleanFields(){
            id.erase(std::remove(id.begin(), id.end(), '"'), id.end());
            CleanWhiteSpace(id);

            description.erase(std::remove(description.begin(), description.end(), '"'), description.end());
            CleanWhiteSpace(description);

            status.erase(std::remove(status.begin(), status.end(), '"'), status.end());
            CleanWhiteSpace(status);
            
            createdAt.erase(std::remove(createdAt.begin(), createdAt.end(), '"'), createdAt.end());
            CleanWhiteSpace(createdAt);
            
            updatedAt.erase(std::remove(updatedAt.begin(), updatedAt.end(), '"'), updatedAt.end());
            CleanWhiteSpace(updatedAt);
      }

      void CleanWhiteSpace(std::string &str){
            size_t first_char = str.find_first_not_of(" \t\n\r");

            if (first_char == std::string::npos){
                  str.clear();
                  return;
            }

            size_t last_char = str.find_last_not_of(" \t\n\r}]");

            str = str.substr(first_char, last_char - first_char + 1);

      }

      void PrintTask() const {
            std::cout << "id: " << id << "\n"   
                      << "description: " << description << "\n"   
                      << "status: " << status << "\n"   
                      << "createdAt: " << createdAt << "\n"   
                      << "updatedAt: " << updatedAt << "\n\n";   
      }
};
