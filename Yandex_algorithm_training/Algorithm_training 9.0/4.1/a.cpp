#include<iostream>
#include<stdexcept>
#include <string>

using namespace std;

template <typename T> class Stack {

    private:
        T* data;
        size_t capacity;
        size_t upper_index;

        void resize(){

            capacity *= 2;
            T* new_data = new T[capacity];

            for(size_t i = 0; i < upper_index; i++){
                new_data[i] = data[i];
            }

            delete[] data;

            data = new_data;
        }

    public:
        Stack() {
            capacity = 10;
            upper_index = 0;
            data = new T[capacity];
        }

        ~Stack(){
            delete[] data;
        }

        void push(const T& val)
        {
            if(upper_index > capacity){
                resize();
            }

            data[upper_index] = val;
            upper_index++;
        }

        T& pop(){
            if(upper_index > 0){
                upper_index--;
            }

            return data[upper_index];
        }

        T& back(){
            return data[upper_index-1];
        }

        T& top(){
            if(upper_index == 0){
                throw std::out_of_range("error");
            }

            return data[upper_index - 1];
        }

        bool empty(){
            return capacity == 0;
        }

        size_t size(){

            return upper_index;
        }

        void clear(){

            for(size_t i = 0; i < upper_index; i++){
                data[i] = 0;
            }
            upper_index = 0;
        }
};

int main(){

    string s;
    int num;

    bool flag = true;

    Stack<int> St;

    while(flag){

        cin >> s;
        if(s == "push"){
            cin >> num;

            St.push(num);

            cout << "ok" << endl;
        }

        if(s == "pop"){

            if(St.size() != 0){
                int& n = St.pop();
                cout << n << endl;
            } else 
                cout << "error" << endl;
            
        }

        if(s == "back"){

            if(St.size() != 0){
                int& n = St.back();
                cout << n << endl;
            } else 
                cout << "error" << endl;
                

        }

        if(s == "size"){

            size_t size_st = St.size();
            cout << size_st << endl;
        }
        
        if(s == "clear"){

            St.clear();
            cout << "ok" << endl;

        }

        if(s == "exit"){
            cout << "bye";
            flag = false;
        }

    }
}