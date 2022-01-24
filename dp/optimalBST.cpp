#include <bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j);

int optimalSearchTree(int keys[], int freq[], int n){

    int cost[n][n];

    // For a single key, cost is equal to frequency of the key
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Now we need to consider chains of length 2, 3, ... L is chain length.
    for (int L = 2; L <= n; L++) {

        // i is row number in cost[][]
        for (int i = 0; i <= n - L + 1; i++) {

            // Get column number j from row number i and chain length L
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try making all keys in interval keys[i..j] as root
            for (int r = i; r <= j; r++) {
                // c = cost when keys[r] becomes root of this subtree
                int c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + sum(freq, i, j);

                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n - 1];
}

int sum(int freq[], int i, int j){
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];

    return s;
}

int main(){

    srand((unsigned)time(0));

    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};

    int n = sizeof(keys) / sizeof(keys[0]);

    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, n);

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9 * 1000;

    cout << "\nTime taken by program is : " << time_taken << setprecision(6);
    cout << "msec" << endl;

    return 0;
}