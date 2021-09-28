#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void bucketSort(float arr[], int n) {
    vector<float> bucket[n];
 
 // put elemets in respective buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        bucket[bi].push_back(arr[i]);
    }
 
    for (int i = 0; i < n; i++) // sorting each buckets
        sort(bucket[i].begin(), bucket[i].end());
 
    int index = 0;
    for (int i = 0; i < n; i++) // Concatenate all buckets into arr[]
        for (int j = 0; j < bucket[i].size(); j++)
            arr[index++] = bucket[i][j];
}
  
void printArray(double arr[], int size)    {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printArray(int arr[], int size)    {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printArray(float arr[], int size)    {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
  
int main()  {
    double times[10];
    int ns[10];
    for (int x = 0; x < 10; x++)    {  
    int n = rand() % 100;
    ns[x] = n;
    float arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = (float(rand())/float((RAND_MAX)));
    }
    cout << "Array: ";
    printArray(arr, n);
    cout << endl;
    
    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    
    bucketSort(arr, n);  // sort arr
    
    auto end = chrono::high_resolution_clock::now();
    
    cout << "Sorted array: ";
    // printArray(arr, n);
    cout << endl;
    
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    
    times[x] = time_taken;
    cout << "Time difference is: " << time_taken << setprecision(6) << endl;
    }
    printArray(times, 10);
    printArray(ns, 10);
    return 0;
}
