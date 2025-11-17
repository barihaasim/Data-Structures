// Row Major 
#include <iostream>
using namespace std;
int main() {
    int r = 2, c = 3;
    int arr[2][3] = { {1,2,3}, {4,5,6} };
    int row = 1;                   
    int col = 2;                  
    int index = row * c + col;
    cout << "Row-major index = " << index;
}
//Column Major
#include <iostream>
using namespace std;

int main() {
    int r = 2, c = 3;
    int arr[2][3] = { {1,2,3}, {4,5,6} };
    int row = 1;  // 2nd row
    int col = 2;  // 3rd column
    int index = col * r + row;
    cout << "Column-major index = " << index;
}
//Special Matrices
//(a) Identity Matrix
#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int I[3][3];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) I[i][j] = 1;
            else I[i][j] = 0;
        }
    }
}
//(b)Diagonal Matrix
#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int D[3][3];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) D[i][j] = i + 1;
            else D[i][j] = 0;
        }
    }
}
(//c)Upper Triangular
#include <iostream>
using namespace std;

int main() {
    int n = 3, U[3][3];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) U[i][j] = j + 1;
            else U[i][j] = 0;
        }
    }
}
//(d)Lower Triangular
#include <iostream>
using namespace std;

int main() {
    int n = 3, L[3][3];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) L[i][j] = i + 1;
            else L[i][j] = 0;
        }
    }
}
