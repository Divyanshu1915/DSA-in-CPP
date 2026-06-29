//the code repesent the hash function implementation and its execution
#include<iostream>
#include<string>

using namespace std;

int hashFunction(string value);

int main(){
    string name;
    cout<<"Enter the name:";
    cin>>name;
    cout<<name<<" has hash code"<<hashFunction(name)<<endl;
}
int hashFunction(string value){
    int sumofchar=0;
    
    for(char ch : value){
        sumofchar += int(ch);

    }
    return sumofchar % 10;
}