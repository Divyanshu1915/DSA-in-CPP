#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node* CreateNode(int value){
        data=value;
        next=nullptr;
        return this;

    }

};

int main(){
    //Creating nodes;
    Node* node1=new Node();
    Node* node2=new Node();
    Node* node3=new Node();
    Node* node4=new Node();

    node1->CreateNode(1);
    node2->CreateNode(2);
    node3->CreateNode(3);
    node4->CreateNode(4);

    //Linking nodes
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node1;

    //Printing circular linked list
    Node* currentNode=node1;
    Node* startnode=node1;
    cout<<"Circular linked list:";
    cout<<currentNode->data<<"->";
    currentNode=currentNode->next;
     while(currentNode!=startnode){
        cout<<currentNode->data<<"->";
        currentNode=currentNode->next;
        
        
     }

}