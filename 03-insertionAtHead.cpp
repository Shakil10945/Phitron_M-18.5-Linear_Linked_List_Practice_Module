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
void insertAtTail(Node* &head, int value);
void display(Node* head);
int countSize(Node* head);

void insertAtHead(Node* &head, int value)
{
    Node *newNode=new Node(value);
    newNode->Next=head;
    head=newNode;
}

void insertAtTail(Node* &head, int value)
{

    Node* newNode=new Node(value);
    if(head==NULL)
    {
        head=newNode;

    }
    else
    {
        Node* temp=head;

        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        temp->Next=newNode;
    }
}

void display(Node* head)
{
    if(head==NULL)
    {
        cout<< "Sorry the Linked list is empty right now";
    }
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->value;
        if(temp->Next!=NULL)
        {
            cout<< "->";
        }
        temp=temp->Next;
    }
    cout<<endl;
}

int countSize(Node* head)
{
    Node *temp=head;
    int size=0;
    while(temp!=NULL)
    {
        temp=temp->Next;
        size++;
    }
    return size;
}


int main()
{
    Node *head=NULL;
    int value;
    int choice;
    cout<< "Choice 1: for entering the value into head"<<endl
        << "Choice 2: for entering the value into tail"<<endl
        << "Choice 3: for watching the size of the linked list"<<endl

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
        case 2:
            cout<< "Enter the Value you want  to add into tail : ";
            cin>>value;
            insertAtTail(head,value);
            break;
        case 3:
            cout<< "Size of this Linked list is ";
            int size=countSize(head);
            cout<< size<<endl;
            break;


        }




        cout<< "Enter your Next Choice : ";
        cin>> choice;
    }
    display(head);

    return 0;
}
