#include <iostream>
using namespace std;

template <typename T> class SinglyLinkedList;

template <typename T>
class Node {
private:
    T value;
    Node<T>* next;

public:
    Node(T v) {
        value = v;
        next = nullptr;
    }

    friend class SinglyLinkedList<T>;
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head = nullptr;

public:
    bool empty() {
        return (head == nullptr);
    }

    void pushFront(T v) {
        Node<T>* nn = new Node<T>(v);
        nn->next = head;
        head = nn;
    }

    void pushBack(T v) {
        Node<T>* nn = new Node<T>(v);

        if (empty()) {
            head = nn;
        }
        else {
            Node<T>* curr = head;
            while (curr->next != nullptr)
                curr = curr->next;

            curr->next = nn;
        }
    }

    void popFront() {
        if (empty()) return;

        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    T front() {
        if (empty())
            throw runtime_error("List is empty");

        return head->value;
    }

    void insertAt(int pos, T v) {
        if (pos == 0) {
            pushFront(v);
            return;
        }

        Node<T>* curr = head;
        for (int i = 0; i < pos - 1 && curr != nullptr; i++)
            curr = curr->next;

        if (curr != nullptr) {
            Node<T>* nn = new Node<T>(v);
            nn->next = curr->next;
            curr->next = nn;
        }
    }

    void deleteAt(int pos) {
        if (empty()) return;

        if (pos == 0) {
            popFront();
            return;
        }

        Node<T>* curr = head;
        for (int i = 0; i < pos - 1 && curr != nullptr; i++)
            curr = curr->next;

        if (curr != nullptr && curr->next != nullptr) {
            Node<T>* del = curr->next;
            curr->next = curr->next->next;
            delete del;
        }
    }

    int count() {
        int c = 0;
        for (Node<T>* curr = head; curr != nullptr; curr = curr->next)
            c++;
        return c;
    }

    void print() {
        for (Node<T>* curr = head; curr != nullptr; curr = curr->next)
            cout << curr->value << " ";
        cout << endl;
    }
};

int main() {
    SinglyLinkedList<int> list;

    list.pushFront(10);
    list.pushBack(20);
    list.pushFront(5);
    list.insertAt(1, 15);

    list.print();
    cout << "Count = " << list.count() << endl;

    list.popFront();
    list.deleteAt(1);

    list.print();

    return 0;
}
