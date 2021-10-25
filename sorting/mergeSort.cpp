#include <bits/stdc++.h>
#include <chrono>

using namespace std;

// merging 2 arrays
void merge(int arr[], int const left, int const midIdx, int const right) {
    int temp[right - left + 1]; // sorted Arr

    int start = left, mid =  midIdx + 1, tempIdx = 0;

    // sorted merging of left and right arrays
	while (start <= midIdx && mid <= right) {
		if (arr[start] <= arr[mid]) {
			temp[tempIdx] = arr[start];
			tempIdx++;
            start++;
		}
		else {
			temp[tempIdx] = arr[mid];
            tempIdx++;
			mid++;
		}
	}

	// check and add for remaining element in left arr
	while (start <= midIdx) {
		temp[tempIdx] = arr[start];
		tempIdx++;
		start++;
	}

	// check and add for remaining element in right arr
	while (mid <= right) {
		temp[tempIdx] = arr[mid];
		tempIdx++;
		mid++;
	}

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i - left];
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

void printArr(int arr[], int size)  {
	for (auto i = 0; i < size; i++) {
		cout << arr[i] << " ";
    }
    cout << "\n\n" << endl;
}


int main()  {
    int n = rand() % 100;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
	cout << "Given array: \n";
	printArr(arr, n);

    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

	mergeSort(arr, 0, n - 1);

    auto end = chrono::high_resolution_clock::now();

	cout << "\nSorted array: \n";
	printArr(arr, n);

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    
    cout << "Time difference is: " << time_taken << setprecision(6);

	return 0;
}
