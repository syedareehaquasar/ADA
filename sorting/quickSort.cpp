#include <bits/stdc++.h>
#include <chrono>

using namespace std;

// A utility function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// last element pivot and lower in 1 half and greater in 1 half divide
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // j == current element
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n\n" << endl;
}

int main()
{
    int n = rand() % 100;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    cout << "Given array: \n";
    printArray(arr, n);

    auto start = chrono::high_resolution_clock::now();

    quickSort(arr, 0, n - 1);

    auto end = chrono::high_resolution_clock::now();

    cout << "\nSorted array: \n";
    printArray(arr, n);

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Time difference is: " << time_taken << setprecision(6);

    return 0;
}