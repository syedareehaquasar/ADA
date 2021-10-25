#include <bits/stdc++.h>
#include <chrono>

using namespace std;

// merging 2 arrays
void merge(int arr[], int const left, int const mid, int const right) {
	auto const subArr1 = mid - left + 1;
	auto const subArr2 = right - mid;

	auto *leftArr = new int[subArr1],
		*rightArr = new int[subArr2];

	for (auto i = 0; i < subArr1; i++)
		leftArr[i] = arr[left + i];
        
	for (auto j = 0; j < subArr2; j++)
		rightArr[j] = arr[mid + 1 + j];

	auto indexOfSubArr1 = 0,
		indexOfSubArr2 = 0;
	int indexOfMergedArr = left;

    // sorted merging of left and right arrays
	while (indexOfSubArr1 < subArr1 && indexOfSubArr2 < subArr2) {
		if (leftArr[indexOfSubArr1] <= rightArr[indexOfSubArr2]) {
			arr[indexOfMergedArr] = leftArr[indexOfSubArr1];
			indexOfSubArr1++;
		}
		else {
			arr[indexOfMergedArr] = rightArr[indexOfSubArr2];
			indexOfSubArr2++;
		}
		indexOfMergedArr++;
	}

	// check and add for remaining element in left arr
	while (indexOfSubArr1 < subArr1) {
		arr[indexOfMergedArr] = leftArr[indexOfSubArr1];
		indexOfSubArr1++;
		indexOfMergedArr++;
	}

	// check and add for remaining element in left arr
	while (indexOfSubArr2 < subArr2) {
		arr[indexOfMergedArr] = rightArr[indexOfSubArr2];
		indexOfSubArr2++;
		indexOfMergedArr++;
	}
}

void mergeSort(int array[], int const begin, int const end) {
	if (begin >= end) {
		return; // Returns recursively
    }
	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
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

void printArray(float arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;
}

double sortApp(int n)  {
    // int n = rand() % 100;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
// 	cout << "Given array: \n";
// 	printArr(arr, n);

    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

	mergeSort(arr, 0, n - 1);

    auto end = chrono::high_resolution_clock::now();

// 	cout << "\nSorted array: \n";
// 	printArr(arr, n);

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    
    // cout << "Time difference is: " << time_taken << setprecision(6);

	return time_taken;
}

int main() {
    double times[10];
    int ns[10];
    for (int x = 0; x < 10; x++)
    {
        int n = rand() % 100;
        ns[x] = n;
        times[x] = sortApp(n);
    }
    cout << "value of n's: " << endl;
    printArray(ns, 10);
    cout << "time for each n: " << endl;
    printArray(times, 10);
}
