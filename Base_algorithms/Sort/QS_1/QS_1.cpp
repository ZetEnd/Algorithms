// QS_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

void QuickSort(std::vector<int>& arr, int l, int r) {

    int left = l;
    int right = r;
    int mid = arr[(left + right) / 2];


    while (left < right) {

       //std::cout << left<< " "<< right;

        while (arr[left] < mid)
            left++;

        while (arr[right] > mid)
            right--;

        //std::cout << left << " " << right;

        if (left < right) 
            std::swap(arr[left], arr[right]);
    }

    //left++;
    //right--;

    if (l < right)
        QuickSort(arr, l, --right);

    if (r > left)
        QuickSort(arr, ++left, r);


}

void QuickSort_v2(std::vector<int>& arr, int l, int r) {

    int left = l;
    int right = r;
    int mid = arr[(left + right) / 2];


    while (left <= right) {

        //std::cout << left<< " "<< right;

        while (arr[left] < mid)
            left++;

        while (arr[right] > mid)
            right--;

        //std::cout << left << " " << right;

        if (left <= right)
            std::swap(arr[left++], arr[right--]);
    }

    //left++;
    //right--;

    if (l < right)
        QuickSort(arr, l, right);

    if (r > left)
        QuickSort(arr, left, r);


}
/*
void my_qsort(std::vector<int>& arr, int l, int r)
{
    int left = l;
    int right = r;
    int mid = arr[(left + right) / 2];

    while (left <= right) {
        while (arr[left] < mid) {
            left++;
        }
        while (arr[right] > mid) {
            right--;
        }
        if (left <= right) {
            std::swap(arr[left++], arr[right--]);
        }
    }
    if (l < right) {
        my_qsort(arr, l, right);
    }
    if (r > left) {
        my_qsort(arr, left, r);
    }
}
*/
int main()
{
    std::cout << "Hello World!\n";

    std::vector<int> vec = { 10, 7, 8, 9, 1, 5 };
    int n = vec.size();

    // Calling quicksort for the vector vec
    QuickSort(vec, 0, n - 1);
    //my_qsort(vec, 0, n - 1);

    for (auto i : vec) {
        std::cout << i << " ";
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
