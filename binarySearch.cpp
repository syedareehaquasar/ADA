#include <bits/stdc++.h>
using namespace std;
 
int binarySearch(int arr[], int l, int r, int x)    {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int binarySearchIter(int arr[], int l, int r, int x)    {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

void printArray(int arr[], int size)    {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()  {
    // int arr[] = { 2, 3, 4, 10, 40 };
    // int n = sizeof(arr) / sizeof(arr[0]);

    int n = rand() % 100;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    sort(arr, arr + n);
    cout << "Array: ";
    printArray(arr, n);

    int x;
    cout << "Enter element you want to search in  the array: ";
    cin >> x;
   
    cout << "\n Recursive Binary Search" << endl;
    int result = binarySearch(arr, 0, n, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    
    cout << "\n Iterative Binary Search" << endl;
    int resultIter = binarySearchIter(arr, 0, n, x);
    (resultIter == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << resultIter;

    return 0;
}