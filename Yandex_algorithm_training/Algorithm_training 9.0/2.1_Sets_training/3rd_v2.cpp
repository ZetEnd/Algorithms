#include <iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include <algorithm>

int main(){
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    if( !input.is_open()){

        //input.open("/dev/stdin"); - для линукса
        input.open("CON"); // - для виндовса
    }

    int num;
    std::string line1, line2;
    std::getline(input, line1);
    std::getline(input, line2);

    std::vector<int> v1;
    std::istringstream iss1(line1);
    while(iss1 >> num) v1.push_back(num);

    std::vector<int> v2;
    std::istringstream iss2(line2);
    while(iss2 >> num) v2.push_back(num);

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    // удаляем повторяющиеся элементы
    v1.erase(std::unique(v1.begin(), v1.end()), v1.end());
    v2.erase(std::unique(v2.begin(), v2.end()), v2.end());

    int i = 0, j = 0;

    while(i < v1.size() && j < v2.size()){

        if(v1[i] < v2[j]) i++;
        else 
        if (v1[i] > v2[j]) j++;
        else {
            output << v1[i] << " ";
            i++;
            j++;
        }
    }
    /*
        for (int x : set1) {
        if (set2.find(x) != set2.end()) {
            output << x << " ";
        }
    }
        */

    input.close();
    output.close();
    
    return 0;

}