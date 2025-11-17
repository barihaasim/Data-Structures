#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = nullptr;
    }

    void pushFront(int val) {
        Node* n;
        n = new Node(val);

        if (head != nullptr) {
            n->next = head;
            head->prev = n;
        }

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
            n->prev = temp;
        }
    }

    void popFront() {
        if (head != nullptr) {
            Node* temp;
            temp = head;

            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            }

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

        Node* prevNode;
        prevNode = nullptr;

        int i;
        for (i = 0; temp->next != nullptr; i++) {
            prevNode = temp;
            temp = temp->next;
        }

        prevNode->next = nullptr;
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

                if (temp->next != nullptr) {
                    temp->next->prev = n;
                }

                temp->next = n;
                n->prev = temp;
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
            for (i = 0; i < pos && temp != nullptr; i++) {
                temp = temp->next;
            }

            if (temp != nullptr) {
                if (temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                }

                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                }

                delete temp;
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
    DoublyLinkedList d;

    d.pushFront(10);
    d.pushBack(20);
    d.pushFront(5);
    d.insertAt(1, 15);

    d.display();

    cout << "Count: " << d.count() << endl;

    d.popFront();
    d.popBack();
    d.deleteAt(1);

    d.display();

    return 0;
}
