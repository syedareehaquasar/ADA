#include <bits/stdc++.h>
#include <chrono>

using namespace std;

void printMatrix(int arr[10][10], int r, int c)
{
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
        {
            cout << " " << arr[i][j];
            if (j == c - 1)
                cout << endl;
        }
}

int main()
{
    int a[10][10], b[10][10], multipliedMatrix[10][10], r1, c1, r2, c2, i, j, k;

    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    while (c1 != r2) // matrix multiplication validation check
    {
        cout << "Error! column of first matrix not equal to row of second." << endl;;

        cout << "Enter rows and columns for first matrix: ";
        cin >> r1 >> c1;

        cout << "Enter rows and columns for second matrix: ";
        cin >> r2 >> c2;
    }

    cout << endl
         << "\n Enter elements of matrix 1:" << endl;
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c1; ++j)
        {
            cin >> a[i][j];
        }

    cout << endl
         << "\n Enter elements of matrix 2:" << endl;
    for (i = 0; i < r2; ++i)
        for (j = 0; j < c2; ++j)
        {
            cin >> b[i][j];
        }

    // Initializing elements of matrix multipliedMatrix to 0.
    for (i = 0; i < r1; ++i)
        for (j = 0; j < c2; ++j)
        {
            multipliedMatrix[i][j] = 0;
        }

    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    for (i = 0; i < r1; ++i) // multiplication
        for (j = 0; j < c2; ++j)
            for (k = 0; k < c1; ++k)
            {
                multipliedMatrix[i][j] += a[i][k] * b[k][j];
            }

    auto end = chrono::high_resolution_clock::now();

    cout << "multiply of the matrix=\n";
    printMatrix(multipliedMatrix, r1, c2);

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time difference is: " << time_taken << setprecision(6) << endl;

    return 0;
}