#include <iostream>
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

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = nullptr;
    }

    void pushFront(int val) {
        Node* n;
        n = new Node(val);
        n->next = head;
        head = n;
    }

    void pushBack(int val) {
        Node* n;
        n = new Node(val);

        if (head == nullptr) {
            head = n;
        }
        else {
            Node* temp;
            temp = head;

            for (; temp->next != nullptr; temp = temp->next) {}

            temp->next = n;
        }
    }

    void popFront() {
        if (head != nullptr) {
            Node* temp;
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void popBack() {
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp;
        temp = head;

        Node* prev;
        prev = nullptr;

        int i;
        for (i = 0; temp->next != nullptr; i++) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = nullptr;
        delete temp;
    }

    void insertAt(int pos, int val) {
        if (pos == 0) {
            pushFront(val);
        }
        else {
            Node* temp;
            temp = head;

            int i;
            for (i = 0; i < pos - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }

            if (temp != nullptr) {
                Node* n;
                n = new Node(val);
                n->next = temp->next;
                temp->next = n;
            }
        }
    }

    void deleteAt(int pos) {
        if (head == nullptr) {
            return;
        }

        if (pos == 0) {
            popFront();
        }
        else {
            Node* temp;
            temp = head;

            int i;
            for (i = 0; i < pos - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }

            if (temp != nullptr && temp->next != nullptr) {
                Node* d;
                d = temp->next;
                temp->next = temp->next->next;
                delete d;
            }
        }
    }

    int count() {
        int c;
        c = 0;

        Node* temp;
        temp = head;

        for (; temp != nullptr; temp = temp->next) {
            c = c + 1;
        }

        return c;
    }

    void display() {
        Node* temp;
        temp = head;

        for (; temp != nullptr; temp = temp->next) {
            cout << temp->data << " ";
        }

        cout << endl;
    }
};

int main() {
    SinglyLinkedList s;

    s.pushFront(10);
    s.pushBack(20);
    s.pushFront(5);
    s.insertAt(1, 15);

    s.display();

    cout << "Count: " << s.count() << endl;

    s.popFront();
    s.popBack();
    s.deleteAt(1);

    s.display();

    return 0;
}
