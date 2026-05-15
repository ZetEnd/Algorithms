#include <iostream>
#include <vector>

//using namespace std;

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix){

    std::pair<size_t, size_t> maxarg {0,0};

    for(size_t i = 0; i != matrix.size(); i++){
        for(size_t j = 0; j != matrix[0].size(); j++){
            if(matrix[maxarg.first][maxarg.second] < matrix[i][j]){
                maxarg.first = i;
                maxarg.second = j;

            }
        }
    }

    return maxarg;
}

int main(){

    int n,k;

    std::cin >> n >> k;



    std::vector<std::vector<int>> v (n, std::vector<int>(k)); 

    for(size_t i = 0; i < v.size(); i++){

        for(size_t j = 0; j < v[0].size(); j++){

            std::cin >> v[i][j];

        }
    }

    std::pair<int,int> par = MatrixArgMax(v);

    std::cout << par.first << " " << par.second;

}