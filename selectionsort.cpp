
//
// Created by Nikita Singh on 05/06/26.
//

#include "selectionsort.h"
#include<iostream>
using namespace std;

void SORT2(int len,int arr[]) {
    for (int i=0;i<len-1;i++) {
        int smallestvalueidx=i;
        for (int j=i+1;j<len-1;j++) {
            if (arr[j]<arr[smallestvalueidx]) {
                smallestvalueidx=j;
            }
        }
        swap(arr[smallestvalueidx],arr[i]);
    }
    // sorted array display
    cout<<" Sorted array"<<endl;
    for (int i=0;i<len;i++) {
        cout<<arr[i]<<"  ";
    }
}
