// linear_list_wOOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Node
{
    int field;
    class Node* ptr;

    friend class List;
};
//
class List
{
    Node* head;
    int count = 0;
    Node* Prev(Node*);

public:
    List() { head == NULL; }
    int getCount() { return count; }
    bool isEmpty() { return head == NULL; }
    int getValue(Node* p) { return p->field; }
    void setValue(Node* p, int val) { p->field = val; }
    Node* getFirst() { return head; }
    Node* getLast();
    void Clear();
    Node* Next(Node*);
    Node* Add(int, Node*);
    Node* Delete(Node*);
    void print();
    void Swap(Node*, Node*);

};

Node* List::Add(int num, Node* node = NULL) {
    Node* elem = new Node();

    elem->field = num;
    count++;

    if (node == NULL) {
        if (head == NULL) {
            elem->ptr = NULL;
            head = elem;
        }
        else {
            elem->ptr = head;
            head = elem;
        }

        return elem;
    }

    elem->ptr = node->ptr;
    node->ptr = elem;

    return elem;
}

Node* List::Delete(Node* node) {

    if (node == NULL) return NULL;
    count--;

    if (node == head)
    {
        head = node->ptr;
        delete node;
        return head;

    }

    Node* prev = Prev(node);
    prev->ptr = node->ptr;
    delete node;
    return prev;
}

Node* List::Next(Node* node) {

    if (isEmpty()) return NULL;
    return node->ptr;

}

Node* List::Prev(Node* node) {

    if (isEmpty()) return NULL;
    if (node == head) return NULL;

    Node* p = head;

    while (p->ptr != node)
        p = p->ptr;

    return p;
}
Node* List::getLast() {

    Node* p = head;

    while (Next(p) != NULL) {
        p = Next(p);
    }
    return p;
}

void List::Clear() {
    class Node* p = head;

    if (p == NULL) return;

    do {
        Node* d = p;
        p = Next(p);
        delete d;
    } while (p != NULL);
    count = 0;
    head = NULL;
}

void List::print() {
    if (isEmpty()) {
        std::cout << "List is empty" << std::endl; return;
    }

    Node* p = head;
    do {
        std::cout << getValue(p) << " ";
        // p = p->ptr;
        p = Next(p);
    } while (p != NULL);

    std::cout << std::endl;
}

void List::Swap(Node* node1, Node* node2) {

    if (node1 == NULL || node2 == NULL) return;
    if (node1 == node2) return;
    if (node2->ptr == node1) {
        Node* p = node1;
        node1 = node2;
        node2 = p;
    }

    Node* prev1 = Prev(node1);
    Node* prev2 = Prev(node2);
    Node* next1 = Next(node1);
    Node* next2 = Next(node2);

    if (next1 == node2) {
        if (prev1 != NULL)
            prev1->ptr = node2;
        else
            head = node2;
        node2->ptr = node1;
        node1->ptr = next2;

        return;
    }

    if (prev1 != NULL)
        prev1->ptr = node2;
    else
        head = node2;
    if (prev2 != NULL)
        prev2->ptr = node1;
    else
        head = node1;
    node1->ptr = next2;
    node2->ptr = next1;
}
int main()
{
    system("chcp 1251");
    system("cls");

    List list;
    list.print();

    for (int i = 0; i < 10; i++) {
        int z;
        std::cout << ">>";
        std::cin >> z;
        list.Add(z);
    }

    list.print();
    std::cout << "lastElem" << list.getValue(list.getLast()) << std::endl;

    Node* p = list.getFirst();

    do {
        if (list.getValue(p) == 0)
            p = list.Delete(p);
        else
            p = list.Next(p);
    } while (p != NULL);

    list.print();
    std::cout << "В списке " << list.getCount() << " элементов" << std::endl;

    list.Swap(list.getFirst(), list.getLast());
    list.print();
    list.Clear();
    list.print();

    std::cout << "В списке " << list.getCount() << " элементов" << std::endl;
    std::cin.get(); std::cin.get();
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
