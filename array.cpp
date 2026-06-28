#include<iostream>
#include<vector>
using namespace std;
int a(int arrlength) {

    vector<int> arr(arrlength);
    int i;
    for (i=0;i<arrlength;i++) {
        cout<<"enter the element"<<i <<"in array";
        cin>>arr[i];
    }
    int j;
    for (j=0;j<arrlength;j++) {
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    return 0;


}