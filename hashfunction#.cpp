#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hash Set using separate chaining
vector<vector<string>> myHashSet = {
    {""},
    {"Jones"},
    {""},
    {"Lisa"},
    {""},
    {"Bob"},
    {""},
    {"Siri"},
    {"Pete"},
    {""}
};

int hashFunction(string name){
    int a=0;
    for (char ch : name){
        a += ch;

    }
    return a %
}
//ADD a value to the hash Set
void add(string name){
    int index=hashFunction(name);
    vector<string>& bucket=myHashSet[index];
    //check if value already exist
    for(string item : bucket){
        if(item== name)
            return;
    }
    bucket.push_back(name);

}

//check if value exist
int Contains(string name){
    int index=hashFunction(name);
    vector<string>& bucket=myHashSet[index];

    for(string item : bucket){
        if(item== name){
            return true
        }
    }
    return false;
}

int main(){
    add("Stuart");

    //print hash set
    cout<<"HAsh Set:\n";
    for(int i=0;i<myHashSet.size();i++){
        cout<<i<<":";
        for (string item : myHashSet[i]){
            cout<<item<<" ";
        }
        cout<<end;

    }

    cout<<"Contains Stuart\n";
    if(contains("Stuart")){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;

}