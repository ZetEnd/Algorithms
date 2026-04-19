// quick_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

std::vector<int> quick_sort(std::vector<int> arr) {

    int len = arr.size();

    int mid = (arr[len] + arr[0]) / 2;

    std::vector<int> leftmass;
    int lenleft;

    std::vector<int> rightmass;
    int lenright;

    std::vector<int> midmass;

    for (int i = 0; i < len; i++) {
        if (arr[i] < mid)
            leftmass.push_back(arr[i]);
        else if (arr[i] > mid)
            rightmass.push_back(arr[i]);
        else
            midmass.push_back(arr[i]);
    }

    return quick_sort(leftmass) + midmass + quick_sort(rightmass);
}
int main()
{
    std::vector<int> numbers{ 1, 2, 3, 4, 5 };

    std::vector<int> nums{ 4,2,1,9,7,5,100,10,6 };

    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << std::endl;
    }

    quick_sort(nums);

    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << std::endl;
    }
    std::cout << "Hello World!\n";
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
