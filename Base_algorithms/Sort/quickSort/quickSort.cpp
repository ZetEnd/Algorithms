// quickSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<vector>
#define SIZE 20

void quickSort(int* numbers, int left, int right) {

    int pivot;
    int index;
    int l_hold = left;
    int r_hold = right;

    pivot = numbers[left];

    while (left < right) {

        while ((numbers[right] > pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }

        while ((numbers[left] < pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }



    numbers[left] = pivot;
    index = left;
    left = l_hold;
    right = r_hold;

    for (int i = 0; i < SIZE; i++)
        printf("%4d ", numbers[i]);
    printf(" \n");

    if (left < index)
        quickSort(numbers, left, index - 1);
    if (right > index)
        quickSort(numbers, index + 1, right);
}

auto qsort(std::vector<int> A)
{
    if (A.empty())
        return A;
    std::vector<int> p, mn, mx;
    p.push_back(A[A.size() - 1]);
    A.pop_back();

    for (int i = 0; i < A.size(); i++) {
        if (A[i] < p[0])
            mn.push_back(A[i]);
        else
            mx.push_back(A[i]);
    }

    std::vector<int> A1, A2;

    A1 = qsort(mn);
    A2 = qsort(mx);

    A1.insert(A1.end(), p.begin(), p.end());
    A1.insert(A1.end(), A2.begin(), A2.end());

    return A1;
}

void QSort(int* arr, int left, int right) {

    int i = left, j = right;
    int temp, pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            if (arr[i] > arr[j])
            {
                temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
            i++; j--;
        }
    }

    if (left < j) QSort(arr, left, j);
    if (right > i) QSort(arr, i, right);
}

void sort(int* nums, int begin, int end) {

    int l = begin, r = end;
    int v = nums[(l + r) / 2];

    while (l <= r) {

        while (nums[l] < v) l++;
        while (nums[r] > v) r++;
        if (l <= r) {
            int tmp = nums[l]; nums[l] = nums[r]; nums[r] = tmp; l++; r--;
        }

    }
    if (begin < r) sort(nums, begin, r);
    if (l < end) sort(nums, l, end);
}

void Sort(int* nums, int begin, int end) {

    int l = begin, r = end;
    int v = nums[(l + r) / 2];

    while (l <= r) {

        while ((nums[l] < v) && (l < end)) l++;
        while ((nums[r] > v) && (r > begin)) r--;

        if (l <= r)
        {
            int temp = nums[l]; nums[l] = nums[r]; nums[r] = temp;
            if (l < end) l++;
            if (r > begin) r--;
        }

    }

    if (r > begin) Sort(nums, begin, r);
    if (l < end) Sort(nums, l, end);
}

int partition2(std::vector<int>& vector, int lo, int hi) {

    int i = lo;
    int j = hi + 1;

    while (true) {

        while (vector[++i] < vector[lo])
            if (i == hi) break;

        while (vector[--j] > vector[lo])
            if (j == lo) break;

        if (i >= j) break;

        std::swap(vector[i], vector[j]);
    }

    std::swap(vector[lo], vector[j]);

    return j;
}

void quickSort2(std::vector<int>& vector, int lo, int hi) {

    if (hi <= lo) return;

    int j = partition2(vector, lo, hi);

    quickSort2(vector, lo, j-1);
    quickSort2(vector, j+1, hi);


}
int main()
{
    int a[SIZE]{ 1, 2, 3, 6, 4, 8,9 ,6, 4, 7, 2, 4, 6,2 ,10, 23,23,1,5,4};

    //for (int i = 0; i < SIZE; i++) 
        //a[i] = rand() % 20 - 10;
    

    for (int i = 0; i < SIZE; i++) 
        printf("%4d ", a[i]);
    
    printf(" \n");
    //quickSort(a, 0, SIZE - 1);
    //QSort(a, 0, SIZE - 1);
    Sort(a, 0, SIZE - 1);

    for (int i = 0; i < SIZE; i++)
        printf("%4d ", a[i]);

    printf(" \n");
    std::cout << "Hello World!\n";

    std::vector<int> Am;

    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        //Am[i] = rand() % 200 - 100;
        Am.push_back(rand() % 200);
        printf("%d ", Am[i]);
    }
    //Am = qsort(Am);
    quickSort2(Am, 0, m-1);
    printf(" \n");
    for (int i = 0; i < m; i++)
        std::cout << Am[i] << " ";

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
