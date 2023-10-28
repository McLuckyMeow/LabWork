#include <iostream>
using namespace std;

// Пример проги

// Введите целое число: 5
// 1 - Добавить еще, 2 - Завершить: 1
// Введите целое число: 3
// 5	3
// 1 - Добавить еще, 2 - Завершить: 1
// Введите целое число: 8
// 5	3	8
// 1 - Добавить еще, 2 - Завершить: 2
// В этом примере пользователь вводит три целых числа (5, 3 и 8) и может выбрать,
// хочет ли он добавить еще элементов (ввод "1") или завершить программу (ввод "2"). 
// Программа добавляет элементы в свой двусвязный список и сортирует его в порядке убывания.

class LinkedList {
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void addElement(int value);
    void display();
    ~LinkedList();

private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

    void sort();
};

void LinkedList::addElement(int value) {
    Node* newNode = new Node(value);

    if (!head) {
        head = tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    sort();
}

void LinkedList::display() {
    Node* current = head;
    while (current) {
        cout << current->data << '\t';
        current = current->next;
    }
    cout << endl;
}

void LinkedList::sort() {
    Node* left = head;
    Node* right = head->next;

    while (left) {
        while (right) {
            if (left->data < right->data) {
                swap(left->data, right->data);
            }
            right = right->next;
        }
        left = left->next;
        if (left) {
            right = left->next;
        }
    }
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int main() {

    setlocale(LC_ALL, "Russian");
    
    LinkedList list;

    while (true) {
        cout << "Введите целое число: ";
        int value;
        cin >> value;
        list.addElement(value);
        list.display();

        cout << "1 - Добавить еще, 2 - Завершить: ";
        int choice;
        cin >> choice;

        if (choice == 2) {
            break;
        }
    }

    return 0;
}
