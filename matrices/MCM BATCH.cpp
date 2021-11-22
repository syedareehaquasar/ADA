#include <bits/stdc++.h>
#include <chrono>

using namespace std;

int dp[100][100];

int matrixChainMemo(int *p, int i, int j){
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = INT_MAX;

    for (int k = i; k < j; k++) {
        dp[i][j] = min(
            dp[i][j], matrixChainMemo(p, i, k) + matrixChainMemo(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}

int MatrixChainOrder(int *p, int n){
    int i = 1, j = n - 1;
    return matrixChainMemo(p, i, j);
}

void printArray(double arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;
}

void printArray(float arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;
}

int main(){
    double times[10];
    int ns[10];
    for (int x = 0; x < 10; x++)    {
        memset(dp, -1, sizeof dp);
        int n = rand() % 100;
        ns[x] = n;

        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }

        auto start = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        MatrixChainOrder(arr, n);

        auto end = chrono::high_resolution_clock::now();

        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        times[x] = time_taken;
    }

    cout << "value of n's: " << endl;
    printArray(ns, 10);

    cout << "time for each n: " << endl;
    printArray(times, 10);

    return 0;
}