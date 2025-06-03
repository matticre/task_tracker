#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <ctime> 

struct TaskStructure {
      std::string id;
      std::string description;
      std::string status;
      std::string createdAt;
      std::string updatedAt;

      TaskStructure(){};
      TaskStructure(const int &task_id, const std::string task_description) : 
            id(std::string(std::to_string(task_id))), 
            description(task_description),
            status("todo")
            {     
                  auto now   = std::chrono::system_clock::now();
                  auto now_t = std::chrono::system_clock::to_time_t(now);
                  auto *time = std::localtime(&now_t);
                  auto date = std::put_time(time, "%Y-%m-%d %H:%M:%S");
                  std::ostringstream oss;
                  oss << date;

                  createdAt = oss.str();
                  updatedAt = createdAt;
            };
            
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
