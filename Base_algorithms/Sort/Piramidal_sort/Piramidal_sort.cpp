// Piramidal_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

void heapify(int* arr, int i, int len);

void heap_sort(int* array, int size) {

    for (int i = size; i >= 0; i--) {
        heapify(array,i,size);
    }

    for (int i = size - 1; i >= 1;i--) {
        int buf = array[0];
        array[0] = array[i];
        array[i] = buf;

        heapify(array, 0, i);

    }
}

void heapify(int* arr, int i, int len) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < len && arr[i] < arr[left])
        largest = left;

    if (right < len && arr[largest] < arr[right])
        largest = right;

    if (largest != i){
        int buf = arr[i];
        arr[i] = arr[largest];
        arr[largest] = buf;

        heapify(arr, largest, len);
    }
}

#include <iostream>

int main()
{

    int numbers[]{ 11, 12, 13, 14 };
    int count = std::size(numbers);
    std::cout << "Length: " << count << std::endl;   // Length: 4

    const int n = 10;
    int num[n]{1,4,6,2,5,10,9,14,12,7};

    count = std::size(num);
    std::cout << "Length: " << count << std::endl;   // Length: 4

    for (int i = 0; i < n; i++) {
        std::cout << num[i] << std::endl;
    }

    heap_sort(num, n);
    std::cout << "Hello World!\n";

    for (int i = 0; i < n; i++) {
        std::cout << num[i] << std::endl;
    }
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
