// Binary_tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

struct tnode {

    char* word;
    int count;
    struct tnode* left;
    struct tnode* right;
};

struct tnode* addtree(struct tnode* p, char* w)
{
    int cond;

    if (p == NULL) {
        p = (struct tnode*)malloc(sizeof(struct tnode));
        p->word = _strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond > 0)
        p->right = addtree(p->right, w);
    else
        p->left = addtree(p->left, w);

    return p;
}

void freemem(tnode* tree) {

    if (tree != NULL) {
        freemem(tree->left);
        freemem(tree->right);
        free(tree->word);
        free(tree);
    }
}

//void printtree( tnode* tree)
void printtree(struct tnode* tree)
{
    if (tree != NULL) {
        printtree(tree->left);
        printf("%d %s \n", tree->count, tree->word);
        printtree(tree->right);
    }
}
int main()
{
    struct tnode* root;
    char word[MAXWORD];
    root = NULL;

    do {
        scanf_s("%s", word, MAXWORD);
        if (isalpha(word[0]))
            root = addtree(root, word);
    } while (word[0] != '0');

    printtree(root);
    freemem(root);
    getchar();
    getchar();


    std::cout << "Hello World!\n";

    //return 0;
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
