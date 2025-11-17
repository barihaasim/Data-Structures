#include <iostream>
using namespace std;

class MyList {
    int arr[100]; 
    int size;       

public:
    MyList() {
        size = 0;
        for (int i = 0; i < 100; i++)
            arr[i] = 0;
    }

    void InsertHead(int val) {
        for (int i = size; i > 0; i--)  
            arr[i] = arr[i - 1];
        arr[0] = val;
        size++;
    }

    void InsertTail(int val) {
        arr[size] = val;  
        size++;
    }

    void InsertMiddle(int val, int pos) {
        if (pos > size) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        for (int i = size; i > pos; i--)
            arr[i] = arr[i - 1];
        arr[pos] = val;
        size++;
    }

    void DeleteItem(int pos) {
        if (pos >= size) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        for (int i = pos; i < size - 1; i++)
            arr[i] = arr[i + 1];
        arr[size - 1] = 0;
        size--;
    }

    void Search(int val) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == val) {
                cout << "Found " << val << " at position " << i << endl;
                return;
            }
        }
        cout << val << " not found!" << endl;
    }

    void Display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MyList list;

    list.InsertHead(10);
    list.InsertHead(20);
    list.InsertTail(30);
    list.Display();

    cout << "Insert 40 at tail" << endl;
    list.InsertTail(40);
    list.Display();

    cout << "Insert 50 at head" << endl;
    list.InsertHead(50);
    list.Display();

    int pos = 2;
    cout << "Insert 25 at position 2" << endl;
    list.InsertMiddle(25, pos);
    list.Display();

    list.Search(25);

    list.DeleteItem(2);
    list.Display();

    return 0;
}
