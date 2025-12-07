#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class LinkedList; 

template <class T>
class Node {
private:
    T data;
    Node<T>* next;

    Node(T val) {
        data = val;
        next = nullptr;
    }

    friend class LinkedList<T>; 
};

template <class T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void pushFront(T val) {
        Node<T>* n = new Node<T>(val);
        n->next = head;
        head = n;
    }

    void popFront() {
        if (head == nullptr) {
            throw underflow_error("LinkedList is empty. Cannot pop.");
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    T getFront() {
        if (head == nullptr) {
            throw underflow_error("LinkedList is empty. Cannot get front.");
        }
        return head->data;
    }

    bool empty() {
        return head == nullptr;
    }
};

template <class T>
class Stack {
private:
    LinkedList<T> list;

public:
    Stack() {}

    void push(T value) {
        list.pushFront(value);
    }

    void pop() {
        if (list.empty()) {
            throw underflow_error("Stack is empty. Cannot pop.");
        }
        list.popFront();
    }

    T top() {
        if (list.empty()) {
            throw underflow_error("Stack is empty. Cannot get top.");
        }
        return list.getFront();
    }

    bool isempty() {
        return list.empty();
    }
};

int main() {
    Stack<int> s;

    try {
        s.push(10);
        s.push(20);
        s.push(30);

        cout << "Top: " << s.top() << endl;

        s.pop();

        cout << "Top after pop: " << s.top() << endl;

        s.pop();
        s.pop();

        cout << "Trying to pop empty stack..." << endl;
        s.pop(); 
    }
    catch (const underflow_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
