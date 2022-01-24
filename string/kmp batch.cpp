#include <bits/stdc++.h>
using namespace std;

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char *pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

double KMPSearch(string pat, string txt)
{
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    int M = sizeof(pat);
    int N = sizeof(txt);

    if (M > N) {
        cout << "Pattern can't be longer than the String!" << endl;
        return -1;
    }

    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    bool match = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            cout << "Found pattern at index: " << (i - j) << endl;
            j = lps[j - 1];
            match = 1;
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters, they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9 * 1000;

    if (!match)
    {
        cout << "No Match Found!" << endl;
    }
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
        int n = rand() % 200;
        int m = rand() % 100;
        ns[x] = n;
        ms[x] = m;
        string s1 = randomStr(n);
        string s2 = randomStr(m);
        times[x] = KMPSearch(s1, s2);
    }
    cout << "value of n's: " << endl;
    printArray(ns, 10);
    cout << "value of m's: " << endl;
    printArray(ms, 10);
    cout << "time for LCS for n, m size strings: " << endl;
    printArray(times, 10);
    return 0;
}