
// Optimized implementation of Bubble sort
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void printArray(int arr[], int size)    {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
  
int main()  {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    auto start = chrono::steady_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    
    cout << "Array: ";
    printArray(arr, n);
    cout << endl;
    
    
    
    cout << "Sorted array: ";
    printArray(arr, n);
    cout << endl;
    auto end = chrono::steady_clock::now();
    
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    
    cout << "Time difference is: " << time_taken << setprecision(6);
    return 0;
}
