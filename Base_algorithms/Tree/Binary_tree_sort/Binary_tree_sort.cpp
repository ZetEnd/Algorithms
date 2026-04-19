// Binary_tree_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

struct tnode {
    int field;
    struct tnode* left;
    struct tnode* right;
};

void treeprint(struct tnode* tree) {

    if (tree != NULL) {
        treeprint(tree->left);
        printf("%d", tree->field);
        treeprint(tree->right);
    }
}

struct tnode* addnode(int x, struct tnode* tree) {

    if (tree == NULL) {
        tree = new tnode;
        tree->field = x;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if (x < tree->field)
        tree->left = addnode(x, tree->left);
    else
        tree->right = addnode(x, tree->right);

    return tree;
}

void freemem(struct tnode* p) {

    if (p != NULL) {
        freemem(p->left);
        freemem(p->right);
        delete p;
    }
}
int main()
{
    struct tnode* root = 0;
    system("chcp 1251");
    system("cls");

    int a;
    int size;

    std::cout << "wtf:";

    std::cin >> size;
    for (int i = 0; i < size; i++) {
        printf("Введите узел %d ", i + 1);
        scanf_s("%d", &a);
        root = addnode(a, root);

    }

    treeprint(root);
    printf("\n");
    freemem(root);
    system("pause");
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
