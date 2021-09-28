#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int getMax(int arr[], int n)    {
    int maxEle = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxEle)
            maxEle = arr[i];
    return maxEle;
}
 
void countSort(int arr[], int n, int exp)   {
    int output[n]; // output array
    int count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)    {
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
  
void printArray(int arr[], int size)    {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
  
int main()  {
    // int arr[] = {64, 34, 25, 12, 22, 11, 90};
    // int n = sizeof(arr)/sizeof(arr[0]);
    int n = rand() % 100;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    cout << "Array: ";
    printArray(arr, n);
    cout << endl;
    
    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    
    radixsort(arr, n);  // sort arr
    
    auto end = chrono::high_resolution_clock::now();
    
    cout << "Sorted array: ";
    printArray(arr, n);
    cout << endl;
    
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    
    cout << "Time difference is: " << time_taken << setprecision(6);
    return 0;
}
