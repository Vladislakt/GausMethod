#include <iostream>
#include <list>
using  namespace std;

void printMatrix(double** M, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

void printSystem(double** M, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j] < 0) {
                cout << " - " << -1 * M[i][j];
            }
            else {
                if (j != 0 && j != m - 1) {
                    cout << " + " << M[i][j];
                }
                else cout << M[i][j];

            }
            if (j < m - 1) {
                cout << "*x_" << j + 1;
            }
            if (j == m - 2) {
                cout << " = ";
            }
        }
        cout << endl;
    }
    return;
}

bool contains(list<int> Indexes, int index) {
    for (int i : Indexes) {
        if (index == i - 1) {
            return true;
        }
    }
    return false;
}

int main()
{
    int n = 2, m = 5;
    double** M;
    M = new double*[n];
    for (int i = 0; i < n; i++) {
        M[i] = new double[m];
    }
    M[0][0] = 1; M[0][1] = 2; M[0][2] = 5; M[0][3] = -1; M[0][4] = 1;
    M[1][0] = 1; M[1][1] = -1; M[1][2] = -1; M[1][3] = 2; M[1][4] = 1;
    list<int> Indexes;
    Indexes.push_front(1);
    Indexes.push_front(2);

    printMatrix(M, n, m);
    cout << "-----------------------------" << endl;

    double mn;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (contains(Indexes, j)) {
                continue;
            }
            else {


                if (M[i][j] != 0) {
                    mn = M[i][j];
                    for (int k = 0; k < m; k++) {
                        M[i][k] = M[i][k] / mn;
                    }
                    for (int k = 0; k < n; k++) {
                        if (k != i) {
                            mn = M[k][j];
                            for (int l = 0; l < m; l++) {
                                M[k][l] = M[k][l] - mn * M[i][l];
                            }
                        }
                    }
                    break;
                }
            }            
        }
    }
    printMatrix(M, n, m);
    return 0;
}

