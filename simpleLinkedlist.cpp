#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;

};
Node* CreateNode(int data){
    Node* newNode=new Node();
    newNode->data=data;
    newNode->next=nullptr;
    return newNode;
}

int main(){
    Node* node1=CreateNode(3);
    Node* node2=CreateNode(5);
    Node* node3=CreateNode(7);
    Node* node4=CreateNode(9);

    //linking nodes
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;

    //printing linked list
    Node* currentNode=node1;
    while(currentNode->next!=nullptr){
        cout<<currentNode->data<<"->";
        currentNode=currentNode->next;
    }
    cout<<currentNode->data<<"->";
    cout<<"Null"<<endl;


}