

#include "bubbleSORT.h"
#include<iostream>
#include<vector>
using namespace std;

int SORT(int len) {
    //for input in array
    std::vector<int> arr1(len);

    int i;
    for (i=0;i<len;i++) {
        std:: cout<<"Enter the vakue at index "<<i<<"array:";
        std::cin>>arr1[i];
    }
    //for the show of the array
    for(i=0;i<len;i++){
        cout<<arr1[i]<<"  ";
    }
    cout<<endl;


    int j;
    int t;
    for (i=0;i<len-1;i++) {
        for (j=0;j<len-i-1;j++) {
            if (arr1[j]>arr1[j+1]) {

                t=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=t;

            }
            cout<<arr1[j]<<" ";

        }
        cout<<endl;
    }
    //print sorted array
    cout<<"sorted array"<<endl;
    for (i=0;i<len;i++) {

        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    return 0;
}
