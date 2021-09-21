
// Optimized implementation of Bubble sort
#include <iostream>
#include <ctime>
using namespace std;
  
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void bubbleSort(int arr[], int n)   {
   int i, j;
   bool swapped;
   for (i = 0; i < n - 1; i++)  {
     swapped = false;
     for (j = 0; j < n - i - 1; j++)    {
        if (arr[j] > arr[j+1])  {
           swap(&arr[j], &arr[j + 1]);
           swapped = true;
        }
     }
     
     if (swapped == false)  {// no swap means array sorted so break out
        break;
     }
   }
}
  
void printArray(int arr[], int size)    {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
  
int main()  {
    // int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Array: ";
    printArray(arr, n);
    cout << endl;
    time_t startTime = time(0);
    cout <<"Current Time: " <<  startTime << endl;
    bubbleSort(arr, n);
    time_t endTime = time(0);
    cout <<"Time after execution: " <<  startTime << endl;
    cout << endl;
    cout << "Sorted array: ";
    printArray(arr, n);
    cout << endl;
    cout << "Time difference is: " << endTime - startTime;
    return 0;
}