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
        dp[i][j] = min(dp[i][j], matrixChainMemo(p, i, k) + matrixChainMemo(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}

int MatrixChainOrder(int *p, int n){
    return matrixChainMemo(p, 1, n - 1);
}

int main(){
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);

    auto start = chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false);

    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, n) << endl;

    auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Time difference is: " << time_taken << setprecision(6) << endl;

    return 0;
}