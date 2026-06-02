#include <array>
#include <deque>
#include <iostream>
#include <list>

using namespace std;


//std::list
template <typename T>
struct Node{
    T value;
    Node* prev;
    Node* next;
};



int main(){

    // array
    array<int, 3> point = {1, 2, 3};
    //////////////////////////////////////////////////////////

    // deque
    deque<int> d = {1, 2, 3, 4};

    d.push_back(5); // adding to the end
    d.push_back(6);

    d.pop_back(); // delete it from the end

    d.push_front(0); // adding to the beginning
    d.push_front(-1);
    d.pop_front(); // removing it from the beginning

    // elements of deque 0 1 2 3 4 5

    //for index
    for(size_t i= 0; i < d.size(); ++i){
        cout << d[i] << "\n";
    }

    for(int x: d)
        cout << x << endl;

    /////////////////////////////////////////////////////////////

    // list - список
    list<int> l = {10, 15, 20};

    l.push_front(5);
    l.push_front(0);

    l.push_back(25);
    l.push_back(30);

    l.pop_front();
    l.pop_back();

    for(int x : l){
        cout << x << "\n"; // 5 10 15 20 25
    }

    ////////////////////////////////////
    
    // iterators

    auto iter = l.begin();
    cout << *iter << "\n";  // printing first element

    ++iter; // moving to the next element
    --iter; // moving back;

    for(auto iter = l.begin(); iter != l.end(); ++iter)
        cout << *iter  << "\n"; // printing elements through iterator

    for(auto iter = l.rbegin(); iter != l.rend(); ++iter){
        cout << *iter << "\n"; // printing reverse elements
    }
}