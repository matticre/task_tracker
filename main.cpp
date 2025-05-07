#include "json_lib/json_lib.h"

#include <map>
#include <string>

int main(int argc, char *argv[]){
    Json json;
    // json.Read("prova_3.json");
    // std::string command = std::string(argv[1]);

    // if (command == "add"){
    //     std::string task = std::string(argv[2]);
    //     json.Insert(task);
    // }


    // std::remove("prova.json");
    
// 
    std::string task = "element";
    // 
    json.Add(task);
    json.Add(task);
    json.Add(task);
    json.Write("prova_3.json");

    // json.Read("prova_3.json");
    // json.Print();

}
