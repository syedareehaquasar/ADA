#include <bits/stdc++.h>
using namespace std;

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size(), i = 0, ans = 0;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back({startTime[i], i});
    }
    sort(v.begin(), v.end());
    vector<int> dp(n, 0);

    for (i = n - 1; i >= 0; i--)
    {
        int f = v[i].first;
        int ii = v[i].second;
        int val = 0;

        val += profit[ii];

        int x = endTime[ii];

        auto it = lower_bound(v.begin(), v.end(), x, [](const pair<int, int> &p, const int &value)
                              { return p.first < value; }); // searching for next Starttime which is greater than the current endtime

        if (it != v.end())
        {
            int j = it - v.begin();

            val += dp[j];
        }

        if (i == n - 1)
            dp[i] = max(dp[i], val);

        else
        {
            dp[i] = max(dp[i], max(val, dp[i + 1])); // either take the ith job or skip it and take the next one
        }

        ans = max(ans, dp[i]);
    }

    return ans;
}

int main()
{
    vector<int> startTime{1, 2, 3, 3};
    vector<int> endTime{3, 4, 5, 6};
    vector<int> profit{50, 10, 40, 70};

    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    cout << "Total Profit earned by job Scheduling: " << jobScheduling(startTime, endTime, profit);

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9 * 1000;

    cout << "\nTime taken by program is : " << time_taken << setprecision(6);
    cout << "msec" << endl;

    return 0;
}