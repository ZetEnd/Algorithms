#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main(){

    std::map<std::string, long long> account;
    std::string operation;

    while(std::cin >> operation){

        if(operation == "DEPOSIT"){
            std::string name;
            long long sum;

            std::cin >> name >> sum;

            account[name] += sum;
        }

        if(operation == "WITHDRAW"){
            std::string name;
            long long sum;

            std::cin >> name >> sum;

            account[name] -= sum;
        }

        if(operation == "BALANCE"){
            std::string name;
            
            std::cin >> name;

            if(account.find(name) != account.end()){
                std::cout << account[name] << std::endl;
            } else {
                std::cout << "ERROR" << std::endl;
            }
        }

        if(operation == "TRANSFER"){
            std::string name1, name2;
            long long sum;

            std::cin >> name1 >> name2 >> sum;

            account[name2] += sum;
            account[name1] -= sum;
        }

        if(operation == "INCOME"){
            long long p;

            std::cin >> p;

            for(auto& client : account){

                if(client.second > 0){
                    long long income = client.second * p/100;
                    client.second += income;
                }
            }
        }
    }

    return 0;
}