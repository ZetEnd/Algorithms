#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cell{
    int row, col , color;
};

int main(){

    int n;
    cin >> n;

    // матрица цветов
    vector<vector<int>> color(n, vector<int>(n));

    // массивы дин пррограммирования для макс длины пути и количества таких путей
    vector<vector<int>> dp_len(n, vector<int>(n));
    vector<vector<int>> dp_cnt(n, vector<int>(n));

    vector<Cell> cells;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> color[i][j];

            cells.push_back({i, j, color[i][j]});
        }
    }

    sort(cells.begin(), cells.end(), [](const Cell& a, const Cell& b){
        return a.color < b.color;
    });

    // для проверки соседних клеток
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    // заполняем 2 матрицы динамического программирования
    for(const Cell& cell: cells){

        int r = cell.row;
        int c = cell.col;

        int best_len = 1;
        int count_len = 1;

        for(int d = 0; d < 4; d++){

            int r_now = r + row[d];
            int c_now = c + col[d];

            if(r_now < n && r_now >= 0 && c_now < n && c_now >=0){

                if(color[r_now][c_now] < color[r][c]){

                    int new_len = dp_len[r_now][c_now] + 1;

                    if(new_len > best_len){
                        best_len = new_len;
                        count_len = dp_cnt[r_now][c_now];
                    } else if( new_len == best_len)
                        count_len += dp_cnt[r_now][c_now];;

                }
            }

        }

        // после проверких всех соседей обновляем матрицы динамического программирования

        dp_len[r][c] = best_len;
        dp_cnt[r][c] = count_len;

    }

    int best_len = 1;
    int count_best = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            if(i == 0 || i == n-1 || j == 0 || j == n-1){

                if(dp_len[i][j] > best_len){
                    best_len = dp_len[i][j];
                    count_best = dp_cnt[i][j];
                } else if(dp_len[i][j] == best_len)
                    count_best += dp_cnt[i][j];

            }
        }
    }

    cout << best_len << " " << count_best;

}