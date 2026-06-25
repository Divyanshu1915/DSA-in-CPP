#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<char> stk;

    //push element in stack
    stk.push('A');
    stk.push('B');
    stk.push('C');
    
    cout<<"Stack Top:"<<stk.top()<<endl;

    
    //removing the top element from stack
    
    cout<<"Element Removed:"<<stk.top()<<endl;

    //peek
    cout<<"Stack top:"<<stk.top()<<endl;

    //isempty
    bool isempty= stk.empty();
    cout<<"ISempty:"<< boolalpha<<isempty<<endl;

    //Size of stack
    cout<<"Size of stack:"<<stk.size()<<endl;
    return 0;


}