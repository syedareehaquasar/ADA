#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2)  {
        for (int i = gap; i < n; i += 1)    {
            int temp = arr[i];
 
            // shift gap sorted elements to find position for ith element
            int j = i;
            for (j; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp; // place i th element in correct position
        }
    }
    return 0;
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
    
    shellSort(arr, n);  // sort arr
    
    auto end = chrono::high_resolution_clock::now();
    
    cout << "Sorted array: ";
    printArray(arr, n);
    cout << endl;
    
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    
    cout << "Time difference is: " << time_taken << setprecision(6);
    return 0;
}
