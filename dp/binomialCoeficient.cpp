#include <bits/stdc++.h>
using namespace std;

int min(int a, int b);

int binomialCoeff(int n, int k){

    int C[n + 1][k + 1];
    int i, j;

    // Calculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++) {

        for (j = 0; j <= min(i, k); j++) {

            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previously stored values
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

// A utility function to return minimum of two integers
int min(int a, int b) { 
    return (a < b) ? a : b;
}

int main(){

    srand((unsigned)time(0));

    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    int n = 5, k = 2;

    cout << "Value of C[" << n << "][" << k << "] is " << binomialCoeff(n, k);

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9 * 1000;
    cout << "\nTime taken by program is : " << time_taken << setprecision(6);
    cout << "msec" << endl;
}