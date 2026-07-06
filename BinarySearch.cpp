#include<iostream>
using namespace std;
int binarysearch(int arr[],int len,int target){
    int str=0;
    int end=len-1;
    while(str<=end){
        int mid=str+(end-str)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(target >arr[mid]){
            str=mid+1;

        }
        else{
            end=mid-1;
        }
    }
    return -1;
}
int main(){
    int len,target;
    cout<<"Enetr the length of the array:";
    cin>>len;
    cout<<"Enter the target value to be found:";
    cin>>target;
    int arr[len];
    for(int i=0;i<len;i++){
        cout<<"Enter the "<<i<<"th element of the array:";
        cin>>arr[i];
    }
    int result=binarysearch(arr,len,target);
    if(result==-1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at index"<<result;
    }
}


