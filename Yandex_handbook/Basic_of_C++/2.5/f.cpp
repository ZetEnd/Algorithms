#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int>> merge(const vector<pair<int,int>>& arr1, const vector<pair<int,int>>& arr2){

    size_t i = 0, j = 0;

    vector<pair<int, int>> res;

    while(i < arr1.size() && j < arr2.size()){

        long long sum1 = arr1[i].first*arr1[i].first + arr1[i].second*arr1[i].second;
        long long sum2 = arr2[j].first*arr2[j].first + arr2[j].second*arr2[j].second;

        if(sum1 >= sum2){
            res.push_back(arr2[j]);
            j++;
        } else {
            res.push_back(arr1[i]);
            i++;
        }
    }
    while( i != arr1.size()){
        res.push_back(arr1[i]);
        i++;
    }

    while( j != arr2.size()){
        res.push_back(arr2[j]);
        j++;
    }

    return res;
}

vector<pair<int,int>> merge_sort(const vector<pair<int,int>>& coord){

    if(coord.size() <= 1){
        return coord;
    }


    size_t mean = coord.size() / 2;

    vector<pair<int,int>> arr1;
    vector<pair<int,int>> arr2;

    for(size_t i = 0; i < coord.size(); i++){

        if(i < mean)
            arr1.push_back(coord[i]);
        else 
            arr2.push_back(coord[i]);
    }

    arr1 = merge_sort(arr1);
    arr2 = merge_sort(arr2);

    return merge(arr1,arr2);
}

int main(){

    int n;

    cin >> n;

    vector<pair<int,int>> coord;
    
    while(n>0){

        int x, y;

        cin >> x >> y;
        
        coord.push_back({x,y});

        n--;
    }

    coord = merge_sort(coord);

    for(size_t i = 0; i < coord.size(); i++){
        cout << coord[i].first << " " << coord[i].second << endl;
    }
}