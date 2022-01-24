#include <bits/stdc++.h>
using namespace std;

int n;
int st[1000], en[1000];
int dp[1000][1000];

int solve(int index, int currentFinishTime)
{
    if (index == n)
        return 0;
    int v1 = 0, v2 = 0;
    if (dp[index][currentFinishTime] != -1)
        return dp[index][currentFinishTime];

    // do not choose the current activity
    v1 = solve(index + 1, currentFinishTime);

    // try to choose the current activity
    if (st[index] >= currentFinishTime)
    {
        v2 = solve(index + 1, en[index]) + 1;
    }
    return dp[index][currentFinishTime] = max(v1, v2);
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> st[i] >> en[i];

    memset(dp, -1, sizeof dp);

    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    cout << solve(0, 0) << endl;

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9*1000;
  
    cout << "\nTime taken by program is : " << time_taken << setprecision(6);
    cout << "msec" << endl;
    
    return 0;
}