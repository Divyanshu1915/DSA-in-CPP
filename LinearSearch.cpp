#include<iostream>
using namespace std;
int linearsearch(int arr[],int len,int target){
    for (int i=0;i<len;i++){
        if(arr[i]==target){
            return i;
        }

    }
    return -1;
}
int main(){
   
    int len,target;
    cout<<"Enter the size of the array:";
    cin>>len;
    cout<<"Enter the target value to found:";
    cin>>target;
    int arr[len];
    for(int i=0;i<len;i++){
        cout<<"enter the"<<i<<"th element of the array:";
        cin>>arr[i];

    }
    int result=linearsearch(arr,len,target);
    if(result!=-1){
        cout<<"Element found at index"<< result;

    }
    else{
    cout<<"Element not found in the array";
    }
}