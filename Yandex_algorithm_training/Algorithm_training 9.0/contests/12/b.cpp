#include <iostream>
#include <vector>
using namespace std;



int main() {
    vector<string> g(10);

    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    for (int i = 0; i < 10; i++)
        cin >> g[i];


    vector<vector<bool>> used(10, vector<bool>(10, false));
    vector<int> cnt(5);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (g[i][j] == '#' && !used[i][j]) {

                vector<pair<int,int>> cells;
                vector<pair<int,int>> stack = {{i,j}};
                used[i][j] = true;

                while (!stack.empty()) {
                    auto [x,y] = stack.back();
                    stack.pop_back();
                    cells.push_back({x,y});

                    int dx4[4] = {-1,1,0,0};
                    int dy4[4] = {0,0,-1,1};

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx4[d];
                        int ny = y + dy4[d];
                        if (nx>=0 && nx<10 && ny>=0 && ny<10 && !used[nx][ny] && g[nx][ny]=='#') {
                            used[nx][ny] = true;
                            stack.push_back({nx,ny});
                        }
                    }
                }

                int minx=10, maxx=-1, miny=10, maxy=-1;
                for (auto [x,y] : cells) {
                    minx = min(minx, x);
                    maxx = max(maxx, x);
                    miny = min(miny, y);
                    maxy = max(maxy, y);
                }

                int h = maxx - minx + 1;
                int w = maxy - miny + 1;

                if (!(h == 1 || w == 1)) {
                    cout << "NO";
                    return 0;
                }

                if ((int)cells.size() != h * w) {
                    cout << "NO";
                    return 0;
                }

                int size = cells.size();
                if (size < 1 || size > 4) {
                    cout << "NO";
                    return 0;
                }

                cnt[size]++;

                for (auto [x,y] : cells) {
                    for (int d = 0; d < 8; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx>=0 && nx<10 && ny>=0 && ny<10) {
                            if (g[nx][ny] == '#' && !used[nx][ny]) {
                                cout << "NO";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    if (cnt[1] == 4 && cnt[2] == 3 && cnt[3] == 2 && cnt[4] == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}