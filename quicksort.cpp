
#include "quicksort.h"
#include<iostream>

using namespace std;
int partition(int arr[],int str,int end);
void quicksort(int arr[],int str,int end) {
    if (str<=end) {
        int pividx=partition(arr,str,end);
        quicksort(arr,str,pividx-1);
        quicksort(arr,pividx+1,end);

    }
}

int partition(int arr[],int str,int end) {
    int idx=str-1;
    int pivot = arr[end];
    for (int i=str;i<end;i++) {
        if (arr[i]<=pivot) {
            idx++;
            swap(arr[i],arr[idx]);

        }

    }
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
}
int main(){
    int arr[] = {1,2,3,5,4,6,8,9,76,54,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}