#include "json_lib/json_lib.h"

#include <map>
#include <string>

int main(){
    std::remove("prova.json");
    Json json;
    json.Create("prova.json");

    std::map<std::string,std::string> map = {
                                             {"task_id","1"},
                                             {"task","element"},
                                            };
    // json.Insert(map);
    // json.Insert(map);
    // json.Insert(map);
}