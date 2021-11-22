#include <bits/stdc++.h>
#include <chrono>

using namespace std;

void printMatrix(int arr[2][2], int r, int c)
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
    int a[2][2], b[2][2], mult[2][2];
    int m1, m2, m3, m4, m5, m6, m7, i, j;

    cout << "Matrix Multiplication Strassen's method: \n";
    cout << "Enter the elements of 2x2 Matrix 1:\n";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Enter the elements of 2x2 Matrix 2:\n";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cin >> b[i][j];
        }
    }

    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    m2 = (a[1][0] + a[1][1]) * b[0][0];
    m3 = a[0][0] * (b[0][1] - b[1][1]);
    m4 = a[1][1] * (b[1][0] - b[0][0]);
    m5 = (a[0][0] + a[0][1]) * b[1][1];
    m6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    mult[0][0] = m1 + m4 - m5 + m7;
    mult[0][1] = m3 + m5;
    mult[1][0] = m2 + m4;
    mult[1][1] = m1 - m2 + m3 + m6;

    auto end = chrono::high_resolution_clock::now();

    cout << "\nProduct of matrices is: \n";
    printMatrix(mult, 2, 2);

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Time difference is: " << time_taken << setprecision(6) << endl;

    return 0;
}