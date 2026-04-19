// Index_search.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf() в Visual Studio
#include <stdio.h>
#include <stdlib.h> // для использования функций system()

int main()
{
    int k[] = { 8,  14,  26,  38,  72, 115, 206, 221,
         229, 307, 318, 389, 411, 413, 473, 504, 518 };

    const int size = sizeof(k) / sizeof(int);

    const int step = 5;

    int r[size];
    const int ind_size = size / step + 1;
    int key, j;
    int kindex[ind_size];
    int pindex[ind_size];

    system("chcp 1251");
    system("cls");

    for (int i = 0; i < size; i++) {
        printf(" k[%2d] = %3d: r[%2d] = ", i, k[i], i);
        //scanf("%d", &r[i]);
        std::cin >> r[i];
    }


    for (int i = 0, j = 0; i < size; i = i + step, j++) {

        kindex[j] = k[i];
        pindex[j] = i;
    }
    printf("Индексная таблица:\n");

    for (int i = 0; i < ind_size; i++) {
        printf("p[%2d] = %3d: индекс %3d\n", i, kindex[i], pindex[i]);
    }
    printf("Введите k: "); // вводим ключевое поле
    //scanf("%d", &key);
    std::cin >> key;

    int beg, end;

    for (j = 0; j < ind_size; j++) {

        if (key < kindex[j]) {
            break;
        }
    }

    int flag = 0;
    if (j > 0)
        beg = pindex[j - 1];
    else
        beg = 0;

    if (j == ind_size)
        end = size;
    else
        end = pindex[j];

    for (int i = beg; i < end; i++) {

        if (k[i] == key) {

            printf("Найдена запись %2d: k = %3d, r = %3d\n", i, k[i], r[i]);               
            flag = 1;
        }
    }

    if (flag == 0)
        printf("Запись не найдена !\n");
    std::cout << "Hello World!\n";

    system("pause");
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
