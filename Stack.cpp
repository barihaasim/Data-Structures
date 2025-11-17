// STACK AS ARRAY

#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
    int* arr;
    int capacity;
    int currentsize;

public:
    Stack(int cap) {
        if (cap <= 0) {
            throw invalid_argument("Invalid Capacity");
        }

        capacity = cap;
        currentsize = 0;

        arr = new int[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (currentsize == capacity) {
            throw overflow_error("Full");
        }

        arr[currentsize] = value;
        currentsize = currentsize + 1;
    }

    void pop() {
        if (currentsize == 0) {
            throw underflow_error("Empty");
        }

        currentsize = currentsize - 1;
    }

    int top() {
        if (currentsize == 0) {
            throw underflow_error("Empty");
        }

        int t;
        t = arr[currentsize - 1];
        return t;
    }

    bool isempty() {
        if (currentsize == 0) {
            return true;
        }
        return false;
    }
};

int main() {
    try {
        Stack s;

        s.push(10);
        s.push(20);
        s.push(30);

        int x;
        x = s.top();
        cout << x << endl;

        s.pop();

        x = s.top();
        cout << x << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

// STACK AS LINKEDLIST
#include <iostream>
#include <stdexcept>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void pushFront(int val) {
        Node* n;
        n = new Node(val);
        n->next = head;
        head = n;
    }

    void popFront() {
        if (head == nullptr) {
            throw underflow_error("Empty");
        }

        Node* temp;
        temp = head;

        head = head->next;

        delete temp;
    }

    int getFront() {
        if (head == nullptr) {
            throw underflow_error("Empty");
        }

        int x;
        x = head->data;
        return x;
    }

    bool empty() {
        if (head == nullptr) {
            return true;
        }
        return false;
    }
};

class Stack {
    LinkedList list;

public:
    Stack() {}

    void push(int value) {
        list.pushFront(value);
    }

    void pop() {
        if (list.empty()) {
            throw underflow_error("Empty");
        }

        list.popFront();
    }

    int top() {
        if (list.empty()) {
            throw underflow_error("Empty");
        }

        int t;
        t = list.getFront();
        return t;
    }

    bool isempty() {
        return list.empty();
    }
};

int main() {
    try {
        Stack s;

        s.push(5);
        s.push(15);
        s.push(25);

        int x;
        x = s.top();
        cout << x << endl;

        s.pop();

        x = s.top();
        cout << x << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
