#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
};

int main(){

    int n;

    cin >> n;

    vector<Point> v;

    while(n > 0){
        int x,y;

        cin >> x >> y;

        v.push_back({x,y});
        n--;
    }
    /*for(auto& p : v){
        cout << p.x << " " << p.y << endl;
    }*/

    sort(v.begin(), v.end(), [](const Point& p1, const Point& p2){
        return p1.x*p1.x + p1.y*p1.y < p2.x*p2.x + p2.y*p2.y;
    });

    for(auto& p : v){
        cout << p.x << " " << p.y << endl;
    }
}