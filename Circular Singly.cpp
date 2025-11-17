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

class CircularSingly {
public:
    Node* tail;

    CircularSingly() {
        tail = nullptr;
    }

    void pushFront(int val) {
        Node* n;
        n = new Node(val);

        if (tail == nullptr) {
            tail = n;
            n->next = n;
        }
        else {
            n->next = tail->next;
            tail->next = n;
        }
    }

    void pushBack(int val) {
        pushFront(val);
        tail = tail->next;
    }

    void popFront() {
        if (tail == nullptr) {
            return;
        }

        Node* temp;
        temp = tail->next;

        if (temp == tail) {
            delete temp;
            tail = nullptr;
        }
        else {
            tail->next = temp->next;
            delete temp;
        }
    }

    void popBack() {
        if (tail == nullptr) {
            return;
        }

        if (tail->next == tail) {
            delete tail;
            tail = nullptr;
            return;
        }

        Node* temp;
        temp = tail->next;

        Node* prev;
        prev = nullptr;

        int i;
        for (i = 0; temp->next != tail; i++) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = tail->next;
        delete tail;
        tail = prev;
    }

    void insertAt(int pos, int val) {
        if (pos == 0) {
            pushFront(val);
        }
        else {
            Node* temp;
            temp = tail->next;

            int i;
            for (i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }

            Node* n;
            n = new Node(val);

            n->next = temp->next;
            temp->next = n;

            if (temp == tail) {
                tail = n;
            }
        }
    }

    void deleteAt(int pos) {
        if (tail == nullptr) {
            return;
        }

        if (pos == 0) {
            popFront();
        }
        else {
            Node* temp;
            temp = tail->next;

            int i;
            for (i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }

            Node* del;
            del = temp->next;

            temp->next = del->next;

            if (del == tail) {
                tail = temp;
            }

            delete del;
        }
    }

    int count() {
        if (tail == nullptr) {
            return 0;
        }

        int c;
        c = 0;

        Node* temp;
        temp = tail->next;

        for (;; temp = temp->next) {
            c = c + 1;
            if (temp == tail) {
                break;
            }
        }

        return c;
    }

    void display() {
        if (tail == nullptr) {
            return;
        }

        Node* temp;
        temp = tail->next;

        for (;; temp = temp->next) {
            cout << temp->data << " ";
            if (temp == tail) {
                break;
            }
        }

        cout << endl;
    }
};

int main() {
    CircularSingly cs;

    cs.pushFront(10);
    cs.pushBack(20);
    cs.pushFront(5);
    cs.insertAt(1, 15);

    cs.display();

    cout << "Count: " << cs.count() << endl;

    cs.popFront();
    cs.popBack();
    cs.deleteAt(1);

    cs.display();

    return 0;
}
