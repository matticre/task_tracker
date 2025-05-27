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
            std::string id_label;
            std::string description_label;
            std::string status_label;
            std::string createdAt_label;
            std::string updatedAt_label;

            file >> id_label >> id
                 >> description_label >> description 
                 >> status_label >> status
                 >> createdAt_label >> createdAt
                 >> updatedAt_label >> updatedAt;       
            
            CleanFields();   
      }

      void CleanFields(){

            id.erase(std::remove(id.begin(), id.end(), '"'), id.end());
            id.erase(std::remove(id.begin(), id.end(), ','), id.end());

            description.erase(std::remove(description.begin(), description.end(), '"'), description.end());
            description.erase(std::remove(description.begin(), description.end(), ','), description.end());

            status.erase(std::remove(status.begin(), status.end(), '"'), status.end());
            status.erase(std::remove(status.begin(), status.end(), ','), status.end());
            
            createdAt.erase(std::remove(createdAt.begin(), createdAt.end(), '"'), createdAt.end());
            createdAt.erase(std::remove(createdAt.begin(), createdAt.end(), ','), createdAt.end());
            
            updatedAt.erase(std::remove(updatedAt.begin(), updatedAt.end(), '"'), updatedAt.end());
            updatedAt.erase(std::remove(updatedAt.begin(), updatedAt.end(), ','), updatedAt.end());
      }

      void PrintTask() const {
            std::cout << "id: " << id << "\n"   
                      << "description: " << description << "\n"   
                      << "status: " << status << "\n"   
                      << "createdAt: " << createdAt << "\n"   
                      << "updatedAt: " << updatedAt << "\n\n";   
      }
};
