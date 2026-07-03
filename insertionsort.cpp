//
// Created by Nikita Singh on 06/06/26.
//

#include "insertionsort.h"
#include<iostream>
using namespace std;
void SORT3(int len, int arr[]) {

    for (int i=1;i<len;i++) {
        int curr=arr[i];
        for (int j=i;j>=0;j--) {
            if (arr[j]>curr) {
                arr[j]=arr[j-1];
                arr[j-1]=arr[j];

            }
            cout<<arr[j]<<"  ";

        }

    }
    for(int i=0;i<len;i++) {
        cout<<arr[i]<<" ";
    }
}
