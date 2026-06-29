#include <iostream>
#include <string>
using namespace std;

// Hash set (empty slots are represented by empty strings "")
string myHashSet[10] = {
    "",      // Index 0 (None)
    "Jones", // Index 1
    "",      // Index 2
    "Lisa",  // Index 3
    "",      // Index 4
    "Bob",   // Index 5
    "",      // Index 6
    "Siri",  // Index 7
    "Pete",  // Index 8
    ""       // Index 9
};

int hashFunction(string value){
    int sumofchar=0;
    for(char ch : value){
        sumofchar += ch;

    }
    return sumofchar %10 ;

}
//Search Function
bool Contains(string name){
    int index=hashFunction(name);
    return myHashSet[index]==name;

}
int main(){
    string name;
    cout<<"Enter the name";
    cin>>name;

    cout<<name<<" is in the hast set";
    if(Contains(name)){
        cout<<"true";
    }
    else{
        cout<<"False";
    }
    return 0;
}