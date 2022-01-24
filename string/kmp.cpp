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

int KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

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
    if (!match)
    {
        cout << "No Match Found!" << endl;
        return 0;
    }
    return 1;
}

int main()
{
    // char text[] = "AABAACAADAABAAABAA";
    // char pattern[] = "AABA";

    char text[100], pattern[100];

    cout << "Enter the string for pattern matching: ";
    cin >> text;
    cout << "Enter the pattern that you need to check: ";
    cin >> pattern;

    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    KMPSearch(pattern, text);

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9 * 1000;

    cout << "\nTime taken by KMP program is : " << time_taken << setprecision(6);
    cout << "msec" << endl;

    return 0;
}