// Twice_linear_list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct list {
    int field;
    struct list* next;
    struct list* prev;
};

struct list* init(int a) {

    struct list* lst;

    lst = (struct list*)malloc(sizeof(struct list));

    lst->field = a;
    lst->next = NULL;
    lst->prev = NULL;

    return(lst);
}

struct list* addelem(list* lst, int a) {

    struct list* temp, * p;

    temp = (struct list*)malloc(sizeof(struct list));

    p = lst->next;
    temp->field = a;


    temp->prev = lst;
    lst->next = temp;

    if(p != NULL)
        p->prev = temp;
    temp->next = p;

    return(temp);

}

struct list* deleteelem(list* lst) {

    struct list* prev, *next;

    prev = lst->prev;
    next = lst->next;

    if (prev != NULL)
        prev->next = next;

    if (next != NULL)
        next->prev = prev;

    free(lst);
    return(next);
}

struct list* deletehead(list* root) {
    
    struct list* temp;
    temp = root->next;

    if (root->next != NULL) {
        temp->prev = NULL;
    }

    free(root);

    return(temp);
}

void listprintA(list* head) {

    struct list* lst;

    lst = head;

    do {
        printf("%d \n", lst->field);
        lst = lst->next;
    } while (lst != NULL);
}

void listprintB(list* head) {

    struct list* lst;

    lst = head;
    while (lst->next != NULL) {
        lst = lst->next;
    }
    do {
        printf("%d \n", lst->field);
        lst = lst->prev;
    } while (lst != NULL);
}

struct list* swap(struct list* lst1, struct list* lst2, struct list* head) {

    struct list* prev1, * prev2, * next1, * next2;

    prev1 = lst1->prev;
    prev2 = lst2->prev;

    next1 = lst1->next;
    next2 = lst2->next;

    if (lst2 == next1) {

        lst2->next = lst1;
        lst2->prev = prev1;
        lst1->next = next2;
        lst1->prev = lst2;

        if (next2 != NULL)
            next2->prev = lst1;

        if (prev1 != NULL)
            prev1->next = lst2;
    }
    else if (lst1 == next2) {
        lst1->next = lst2;
        lst1->prev = prev2;
        lst2->next = next1;
        lst2->prev = lst1;

        if (prev2 != NULL)
            prev2->next = lst1;
        if (next1 != NULL)
            next1->prev = lst2;
    }
    else {
        if (lst1 != head)
            prev1->next = lst2;
        lst2->next = next1;

        if (lst2 != head)
            prev2->next = lst1;
        lst1->next = next2;
        lst2->prev = prev1;

        if (next2 != NULL)
            next2->prev = lst1;
        lst1->prev = prev2;

        if (next1 != NULL)
            next1->prev = lst2;

    }

    if (lst1 == head)
        return lst2;
    if (lst2 == head)
        return lst1;
    return(head);
}

int main()
{
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
