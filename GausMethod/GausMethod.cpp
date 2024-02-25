#include <iostream>
using  namespace std;

int** getMatrix() {
    int n = 2;
    int m = 4;
    int** M = new int* [n];
    for (int i = 0; i < n; i++) {
        M[i] = new int[m + 1];
    }
    M[0][0] = 1; M[0][1] = 2; M[0][2] = 5; M[0][3] = -1; M[0][4] = 4;
    M[1][0] = 1; M[1][1] = -1; M[1][2] = -1; M[1][3] = 2; M[1][4] = 1;
    return M;
}

void printSystem(int** M, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m + 1; j++) {
            if (M[i][j] < 0) {
                cout << " - " << -1 * M[i][j];
            }
            else {
                if (j != 0 && j != m) {
                    cout << " + " << M[i][j];
                }
                else cout << M[i][j];

            }
            if (j < m - 1) {
                cout << "*x_" << j + 1;
            }
            if (j == m - 1) {
                cout << " = ";
            }
        }
        cout << endl;
    }
    return;
}

int main()
{
    int n = 2, m = 4;
    int** M = getMatrix();
    printSystem(M, n, m);
    return 0;
}

