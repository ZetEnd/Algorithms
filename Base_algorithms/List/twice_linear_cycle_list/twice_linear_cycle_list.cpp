// twice_linear_cycle_list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct list
{
    int field;
    struct list* next;
    struct list* prev;

};

struct list* init(int a) {
    struct list* lst;

    lst = (struct list*)malloc(sizeof(struct list));

    lst->field = a;
    lst->next = lst;
    lst->prev = lst;

    return(lst);
}

struct list* addelem(list* lst, int number) {

    struct list* temp, * p;
    temp = (struct list*)malloc(sizeof(struct list));

    p = lst->next;
    lst->next = temp;
    temp->field = number;
    temp->next = p;
    temp->prev = lst;
    p->prev = temp;

    return(temp);
}

struct list* deleteelem(list* lst) {

    struct list* prev, * next;

    prev = lst->prev;
    next = lst->next;

    prev->next = next;
    next->prev = prev;

    free(lst);
    return(prev);
}

void listprintA(list* lst) {

    struct list* p;

    p = lst;

    do {
        printf("%d \n", p->field);
        p = p->next;
    } while (p != lst);
}

void listprintB(list* lst) {

    struct list* p;

    p = lst;

    do {
        p = p->prev;
        printf("%d \n", p->field);
    } while (p != lst);
}

struct list* swap(list* lst1, list* lst2, list* head) {

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
        next2->prev = lst1;
        prev1->next = lst2;
    }
    else if (lst1 == next2) {
        lst1->next = lst2;
        lst1->prev = prev2;
        lst2->next = next1;
        lst2->prev = lst1;
        next1->prev = lst2;
        prev2->next = lst1;
    }
    else {
        lst1->next = next2;
        lst1->prev = prev2;
        lst2->next = next1;
        lst2->prev = prev1;
        prev1->next = lst2;
        next1->prev = lst2;
        prev2->next = lst1;
        next2->prev = lst1;
    }

    if (lst1 == head)
        return(lst2);
    if (lst2 == head)
        return(lst1);
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
