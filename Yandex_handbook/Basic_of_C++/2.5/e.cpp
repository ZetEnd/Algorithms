#include <iostream>
#include <vector>
#include <string>


std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix){

    size_t n = matrix.size();
    size_t m = matrix[0].size();

    std::vector<std::vector<int>> res (m, std::vector<int>(n));

    for(size_t i = 0; i < m; i++){

        for(size_t j = 0; j < n; j++){

            res[i][j] = matrix[j][i];
        }
    }

    return res;
}