#include "insertionsort.h"
#include <iostream>
using namespace std;

void SORT3(int len, int arr[])
{
    for (int i = 1; i < len; i++)
    {
        int curr = arr[i];
        int j = i - 1;

        // Shift elements greater than curr to the right
        while (j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert current element
        arr[j + 1] = curr;
    }

    // Print sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
