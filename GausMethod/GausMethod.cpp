#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
using  namespace std;

void printMatrix(double** M, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(10) << M[i][j] << " ";
            if (j == m - 2) {
                cout << "|";
            }
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

void printMatrixToTxt(double** M, int n, int m) {
    ofstream fout("output.txt");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fout << setw(10) << M[i][j] << " ";
            if (j == m - 2) {
                fout << "|";
            }
        }
        fout << endl;
    }
    fout.close();
    return;
}

void GausMethod(double** M, int n, int m, list<int> Indexes) {
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
}

int main()
{
    //чтение
    ifstream fin("input.txt");
    int n, m;
    fin >> n >> m;
    double** M;
    M = new double* [n];
    for (int i = 0; i < n; i++) {
        M[i] = new double[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> M[i][j];
        }
    }
    list<int> Indexes;
    int index;
    fin >> index;
    Indexes.push_front(index);
    fin >> index;
    Indexes.push_front(index);
    fin.close();
    Indexes.push_front(m);//индекс последнего столбика
    //Метод Гаусса
    GausMethod(M, n, m, Indexes);
    //запись
    printMatrixToTxt(M, n, m);
    return 0;
}
