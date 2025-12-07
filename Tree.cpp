#include <iostream>
using namespace std;

template <typename T> class List;
template <typename T> class Queue;

template <typename T>
class ListNode {
public:
    T val;
    ListNode<T>* next;

    ListNode(T v) {
        val = v;
        next = nullptr;
    }
};

template <typename T>
class List {
public:
    ListNode<T>* head;

    List() {
        head = nullptr;
    }

    bool empty() {
        return head == nullptr;
    }

    void pushFront(T v) {
        ListNode<T>* n = new ListNode<T>(v);
        n->next = head;
        head = n;
    }

    int count() {
        int c = 0;
        ListNode<T>* t = head;
        while (t != nullptr) {
            c++;
            t = t->next;
        }
        return c;
    }

    T getAt(int pos) {
        int i = 0;
        ListNode<T>* t = head;
        while (t != nullptr && i < pos) {
            t = t->next;
            i++;
        }
        return t->val;
    }

    void removeVal(T v) {
        if (head == nullptr) return;

        if (head->val == v) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode<T>* t = head;
        while (t->next != nullptr) {
            if (t->next->val == v) {
                ListNode<T>* del = t->next;
                t->next = t->next->next;
                delete del;
                return;
            }
            t = t->next;
        }
    }
};

template <typename T>
class QNode {
public:
    T val;
    QNode<T>* next;

    QNode(T v) {
        val = v;
        next = nullptr;
    }
};

template <typename T>
class Queue {
public:
    QNode<T>* head;
    QNode<T>* tail;

    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    bool empty() {
        return head == nullptr;
    }

    void push(T v) {
        QNode<T>* n = new QNode<T>(v);
        if (head == nullptr) {
            head = n;
            tail = n;
        }
        else {
            tail->next = n;
            tail = n;
        }
    }

    void pop() {
        if (head == nullptr) return;
        QNode<T>* t = head;
        head = head->next;
        delete t;
        if (head == nullptr) tail = nullptr;
    }

    T front() {
        return head->val;
    }
};

template <typename T>
class Tree {
public:
    T data;
    Tree<T>* par;
    List<Tree<T>*> childs;

    Tree(T d) {
        data = d;
        par = nullptr;
    }

    T retrieve() {
        return data;
    }

    Tree<T>* parent() {
        return par;
    }

    bool isRoot() {
        return par == nullptr;
    }

    int degree() {
        return childs.count();
    }

    bool isLeaf() {
        return degree() == 0;
    }

    Tree<T>* child(int n) {
        return childs.getAt(n);
    }

    Tree<T>* insert(T d) {
        Tree<T>* n = new Tree<T>(d);
        n->par = this;
        childs.pushFront(n);
        return n;
    }

    int size() {
        int s = 1;
        ListNode<Tree<T>*>* t = childs.head;
        while (t != nullptr) {
            s += t->val->size();
            t = t->next;
        }
        return s;
    }

    int height() {
        if (isLeaf()) return 0;
        int h = 0;
        ListNode<Tree<T>*>* t = childs.head;
        while (t != nullptr) {
            int c = t->val->height();
            if (c > h) h = c;
            t = t->next;
        }
        return h + 1;
    }

    void attach(Tree<T>* sub) {
        if (sub->par != nullptr) sub->detach();
        sub->par = this;
        childs.pushFront(sub);
    }

    void detach() {
        if (par == nullptr) return;
        par->childs.removeVal(this);
        par = nullptr;
    }

    void DFS() {
        cout << data << " ";
        ListNode<Tree<T>*>* t = childs.head;
        while (t != nullptr) {
            t->val->DFS();
            t = t->next;
        }
    }

    void BFS() {
        Queue<Tree<T>*> q;
        q.push(this);

        while (!q.empty()) {
            Tree<T>* n = q.front();
            q.pop();
            cout << n->data << " ";

            ListNode<Tree<T>*>* t = n->childs.head;
            while (t != nullptr) {
                q.push(t->val);
                t = t->next;
            }
        }
    }
};

int main() {
    Tree<string> root("A");
    Tree<string>* b = root.insert("B");
    Tree<string>* c = root.insert("C");
    b->insert("D");
    b->insert("E");
    c->insert("F");

    cout << "DFS: ";
    root.DFS();
    cout << endl;

    cout << "BFS: ";
    root.BFS();
    cout << endl;

    cout << "Size: " << root.size() << endl;
    cout << "Height: " << root.height() << endl;

    return 0;
}
