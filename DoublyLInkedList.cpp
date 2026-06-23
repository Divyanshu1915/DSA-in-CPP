#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node*prev;
};



Node* CreateNode(int data){
    Node* NewNode=new Node();
    NewNode->data=data;
    NewNode->next=nullptr;
    NewNode->prev=nullptr;
    return NewNode;

}
int main(){
    //creating nOdes
    Node* node1=CreateNode(3);
    Node* node2=CreateNode(5);
    Node* node3=CreateNode(7);
    Node* node4=CreateNode(8);

    //linking nodes
    //forward linking
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    //backward linking
    node2->prev=node1;
    node3->prev=node2;
    node4->prev=node3;

    //printing linked list
    cout<<"Forward Traversal:"<<endl;
    Node* CurrentNode=node1;
    while(CurrentNode->next!=nullptr){
        cout<<CurrentNode->data<<"->";
        CurrentNode=CurrentNode->next;
    }
    cout<<CurrentNode->data<<"->";
    cout<<"Null"<<endl;

    cout<<"Backward Traversal"<<endl;
    CurrentNode=node4;
    while(CurrentNode->prev!=nullptr){
        cout<<CurrentNode->data<<"->";
        CurrentNode=CurrentNode->prev;
    }
    cout<<CurrentNode->data<<"->";
    cout<<"Null"<<endl;
    
}
