#include <bits/stdc++.h>
#include <chrono>
using namespace std;

double lcs(string s1, string s2, int m, int n)
{
    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

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
    auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    return time_taken;
}

string randomStr(const int len) {
    static const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s;
    s.reserve(len);
    for (int i = 0; i < len; ++i) {
        s += letters[rand() % (sizeof(letters) - 1)];
    }
    return s;
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

int main()
{
    double times[10];
    int ns[10];
    int ms[10];
    for (int x = 0; x < 10; x++)
    {
        int n = rand() % 100;
        int m = rand() % 100;
        ns[x] = n;
        ms[x] = m;
        string s1 = randomStr(n);
        string s2 = randomStr(m);
        times[x] = lcs(s1, s2, n, m);
    }
    cout << "value of n's: " << endl;
    printArray(ns, 10);
    cout << "value of m's: " << endl;
    printArray(ms, 10);
    cout << "time for LCS for n, m size strings: " << endl;
    printArray(times, 10);
    return 0;
}