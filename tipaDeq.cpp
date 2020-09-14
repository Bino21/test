// tipaDeq.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <forward_list>
#include <algorithm>
#include <vector>

template <typename T>
class list
{
private:
    struct Node
    {
        Node() { next = nullptr; }
        Node* next;
        T data;
        T& operator*() { return data; }
        operator T() { return data; }
    };
    Node* head;

public:
    list();
    ~list();
    void pushFront(const T& data);
    void popFront();
    Node* begin() { return head; }
    Node* end() {
        Node* node;
        node.next = nullptr;
        return node;
    }
};


template<typename T>
list<T>::list()
{
    head = nullptr;
}

template<typename T>
list<T>::~list()
{
    while (head != nullptr)
        popFront();
}

template<typename T>
void list<T>::popFront()
{
    Node* temp = head;
    head = head->next;
    delete temp;
}

template<typename T>
void list<T>::pushFront(const T& data)
{
    if (head == nullptr)
    {
        head = new Node;
        head->data = data;
        head->next = nullptr;
    }
    else
    {
        Node* temp = new Node;
        temp->next = head;
        temp->data = data;
        head = temp;
    }
}



int main()
{
    int arr[5] = { 1,2,3,4,5 };
    std::cout << *(std::end(arr)-1);
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

