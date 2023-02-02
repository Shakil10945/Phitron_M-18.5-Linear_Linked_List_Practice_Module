#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int value)
    {
        this->value=value;
        Next=NULL;
    }
};
void insertAtHead(Node* &head, int value);

void insertAtHead(Node* &head, int value)
{
    Node *newNode=new Node(value);
    newNode->Next=head;
    head=newNode;
}


int main()
{
    Node *head=NULL;
    int value;
    int choice;
    cout<< "Choice 1: for entering the value into head"<<endl

        << "Choice 0: for exit"<<endl
        <<endl;

    cout<< "Enter your choice : ";
    cin>>choice;
    while(choice!=0)
    {
        switch(choice)
        {
        case 1:
            cout<< "Enter the value you want to add into the head : ";
            cin>> value;
            insertAtHead(head,value);
            break;
        }
        cout<< "Enter your Next Choice : ";
        cin>> choice;
    }

    return 0;
}
