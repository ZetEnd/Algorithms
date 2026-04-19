// Linear_list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct list {
    int field;
    struct list* ptr;
};

struct list *init(int a) {
    struct list* lst;
    lst = (struct list*)malloc(sizeof(struct list));
    lst->field = a;
    lst->ptr = NULL;

    return(lst);
}

struct list* addelem(list* lst, int number) {

    struct list *temp, *p;

    temp = (struct list*)malloc(sizeof(struct list));

    p = lst->ptr;
    lst->ptr = temp;
    temp->field = number;
    temp->ptr = p;

    return temp;
}

struct list* deleteelem(list* lst, list* root) {

    struct list* temp;

    temp = root;
    while (temp->ptr != lst)
        temp = temp->ptr;

    temp->ptr = lst->ptr;
    free(lst);

    return(temp);
}

struct list* deletehead(list* root) {

    struct list* temp;
    temp = root->ptr;
    free(root);

    return(temp);
}

void listprint(list* lst) {

    struct list* p;
    p = lst;

    do {
        printf("%d \n", p->field);
        p = p->ptr;
    } while (p != NULL);
}

struct list* swap(list* lst1, list* lst2, list* head) {

    struct list* prev1, * prev2, * next1, * next2;

    prev1 = head;
    prev2 = head;

    if (prev1 == lst1)
        prev1 = NULL;
    else {
        while (prev1->ptr != lst1)
            prev1 = prev1->ptr;
    }

    if (prev2 == lst2)
        prev2 = NULL;
    else {
        while (prev2->ptr != lst2)
            prev2 = prev2->ptr;
    }

    next1 = lst1->ptr;
    next2 = lst2->ptr;

    if (lst2 == next1) {
        lst2->ptr = lst1;
        lst1->ptr = next2;

        if (lst1 != head)
            prev1->ptr = lst2;
    }
    else
        if (lst1 == next2) {
            lst1->ptr = lst2;
            lst2->ptr = next1;

            if (lst2 != head)
                prev2->ptr = lst1;
        }
        else {
            if (lst1 != head)
                prev1->ptr = lst2;
            lst2->ptr = next1;
            if (lst2 != head)
                prev2->ptr = lst1;
            lst1->ptr = next2;
        }

    if (lst1 == head)
        return lst2;
    if (lst2 == head)
        return lst1;
    return(head);
}
int main()
{

    list* one = init(1);



    list* two = addelem(one, 2);
    list* tree = addelem(two, 3);

    list* another = swap(one, tree, one);

    std::cout << "Hello World!\n";
    listprint(another);

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
