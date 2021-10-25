#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void heapify(int arr[], int n, int root)
{
    int largest = root;
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;
 
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;
 
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n)
{
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) { // ectract elements from heap
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0); // call max heapify on the reduced heap
    }
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
    
    heapSort(arr, n);  // sort arr
    
    auto end = chrono::high_resolution_clock::now();
    
    cout << "Sorted array: ";
    printArray(arr, n);
    cout << endl;
    
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    
    cout << "Time difference is: " << time_taken << setprecision(6);
    return 0;
}
