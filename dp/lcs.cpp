#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void lcs(string s1, string s2, int m, int n)
{
    int dpTable[m + 1][n + 1];

    for (int i = 0; i <= m; i++) // creating dp tale bottom up
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dpTable[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dpTable[i][j] = dpTable[i - 1][j - 1] + 1;
            else
                dpTable[i][j] = max(dpTable[i - 1][j], dpTable[i][j - 1]);
        }
    }

    int index = dpTable[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcsAlgo[index - 1] = s1[i - 1];
            i--;
            j--;
            index--;
        }

        else if (dpTable[i - 1][j] > dpTable[i][j - 1])
            i--;
        else
            j--;
    }
    cout << "s1 : " << s1 << "\nS2 : " << s2 << "\nlcs: " << lcsAlgo << "\n";
}

int main()
{
    // string s1 = "ACADB";
    // string s2 = "CBDA";
    string s1, s2;
    cout << "Please Enter the Strings for finding LCS" << endl;
    cin >> s1 >> s2;
    int m = s1.size();
    int n = s2.size();

    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    lcs(s1, s2, m, n);

    auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time difference is: " << time_taken << setprecision(6) << endl;
    return 0;
}