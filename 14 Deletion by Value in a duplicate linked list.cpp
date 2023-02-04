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
struct Test
{
    int positon[1000];
};

void insertAtHead(Node* &head, int value);
void insertAtTail(Node* &head, int value);
void display(Node* head);
int countSize(Node* &head);
void insertAtSpecific(Node* &head,int position, int value);
int searchValueUnique(Node* &head, int value);
void searchValueDuplicate(Node* &head, int value);
Test searchValueDuplicateReturn(Node* &head,int value);
void insertAfterSpecificValue(Node* &head,int value, int new_val);
void insertAfterSpecificValueDuplicate(Node* &head,int value,int new_val);
void deleteHead(Node* &head);
void deleteTail(Node* &head);
void deleteSpecificPositon(Node* &head,int position);
void deleteSpecificValue(Node* &head,int value);
void deleteSpecificValueDuplicate(Node* & head,int value);


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

int countSize(Node* &head)
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

void insertAtSpecific(Node* &head,int position, int value)
{
    Node *newNode=new Node(value);
    int size=countSize(head);

    if(position>size+1)
    {
        cout<< "Sorry your position is wrong here"<<endl;
        cout<< "Enter your position Again: ";
        int pos;
        cin>> pos;
        insertAtSpecific(head,pos, value);
    }

    else
    {
        Node *temp=head;
        if (position==1)
        {
            insertAtHead(head,value);
        }
        else if(position>1 && position<=size)
        {
            for(int i=0;i<position-2;i++)
            {
                temp=temp->Next;
            }
            newNode->Next=temp->Next;
            temp->Next=newNode;
        }
        else if(position==size+1)
        {
            insertAtTail(head,value);
        }
    }
}

int searchValueUnique(Node* &head, int value)
{
    Node *temp=head;
    int pos=1;
    while(temp!=NULL)
    {
        if(temp->value==value)
        {
            return pos;
        }
        temp=temp->Next;
        pos++;
    }
    cout<< "Your desired value is not found. Please Enter a new value : ";
    int val;
    cin>>val;
    searchValueUnique(head,val);
}
void searchValueDuplicate(Node* &head, int value)
{
    Node *temp =head;
    int count=1;
    int size=countSize(head);
    int position[size+1];
    int k=1,flag=0;
    while(temp!=NULL)
    {
        if(temp->value==value)
        {
            position[k]=count;
            k++;
            flag=1;
        }
        temp=temp->Next;
        count++;
    }
    if(flag==0)
    {
        cout<< "Please Enter again, your searched value did not found : ";
        int val;
        cin>>val;
        searchValueDuplicate(head,val);
    }
    else
    {
        position[0]=k;
        for(int i=1;i<k;i++)
        {
            cout<< position[i];
            if(i<position[0]-1)
            {
                cout<< ",";
            }
        }
        cout<<endl;
    }
}

Test searchValueDuplicateReturn(Node* &head,int value)
{
    Node *temp=head;
    Test T;
    int count=1;
    int k=1;
    while(temp!=NULL)
    {
        if(temp->value==value)
        {
            T.positon[k]=count;
            k++;
        }
        temp=temp->Next;
        count++;
    }
    T.positon[0]=k;
    return T;
}

void insertAfterSpecificValue(Node* &head, int value,int new_val)
{
    int pos=searchValueUnique(head,value);

    insertAtSpecific(head,pos+1,new_val);
}
void insertAfterSpecificValueDuplicate(Node* &head,int value,int new_val)
{
    Test T;
    T=searchValueDuplicateReturn(head,value);
    int size=T.positon[0];
    for(int i=1;i<size;i++)
    {
        int n=T.positon[i];
        insertAtSpecific(head,n+i,new_val);
    }
}

void deleteHead(Node* &head)
{
    Node *temp=head;
    if(temp!=NULL)
    {
        head=temp->Next;
        delete temp;
    }
    else
    {
        cout<< "Sorry, your linked list is empty yet"<<endl;
    }
}

void deleteTail(Node* &head)
{
    Node *temp=head;
    if(temp!=NULL && temp->Next!=NULL)
    {
        while(temp->Next->Next!=NULL)
        {
            temp=temp->Next;
        }
        Node* delNode=temp->Next;
        temp->Next=NULL;
        delete delNode;
    }
}

void deleteSpecificPositon(Node* &head,int position)
{
    Node *temp=head;
    if(position==1)
    {
        deleteHead(head);
    }
    else if(position==countSize(head))
    {
        deleteTail(head);
    }
    else
    {
         int i=0;
         while(i<position-2)
         {
             temp=temp->Next;
             i++;
         }
         Node *delNode=temp->Next;
         temp->Next=temp->Next->Next;
         delete delNode;
    }
}
void deleteSpecificValue(Node* &head,int value)
{
    int position=searchValueUnique(head,value);
    deleteSpecificPositon(head,position);
}

void deleteSpecificValueDuplicate(Node* & head,int value)
{
    Test T;
    T=searchValueDuplicateReturn(head,value);
    int size=T.positon[0];
    int j=0;
    for(int i=1;i<size;i++)
    {
        int n=T.positon[i];
        deleteSpecificPositon(head,n-j);
        j++;
    }
}

int main()
{
    Node *head=NULL;
    int value;
    int position;
    int choice;
    cout<< "Choice 1: for entering the value into head"<<endl
        << "Choice 2: for entering the value into tail"<<endl
        << "Choice 3: for watching the size of the linked list"<<endl
        << "Choice 4: for entering a value in a specific place"<<endl
        << "Choice 5: for searching a value from a unique valued linked list"<<endl
        << "Choice 6: for searching a value from a duplicate valued linked list"<<endl
        << "Choice 7: for entering a value after a specific value in the unique LLL"<<endl
        << "Choice 8: for entering a value after a specific value in the duplicated LLL"<<endl
        << "Choice 9: for deleting the head"<<endl
        << "Choice 10: for deleting the tail"<<endl
        << "Choice 11: for deleting at a specific position"<<endl
        << "Choice 12: for deleting the specific value in a Unique LLL"<<endl
        << "Choice 13: for deleting the specific value in a Duplicate LLL"<<endl

        << "Choice 50: for showing the display"<<endl
        << "Choice 0: for exit"<<endl
        <<endl;

    cout<< "Enter your choice : ";
    cin>>choice;
    while(choice)
    {
        switch(choice)
        {
        case 1:
            {
            cout<< "Enter the value you want to add into the head : ";
            cin>> value;
            insertAtHead(head,value);
            break;
            }
        case 2:
            {
            cout<< "Enter the Value you want  to add into tail : ";
            cin>>value;
            insertAtTail(head,value);
            break;
            }
        case 3:
            {
            cout<< "Size of this Linked list is ";
            int size=countSize(head);
            cout<< size<<endl;
            break;
            }
        case 4:
            {
            cout<< "Enter the position you want to place your new value : ";
            cin>>position;
            cout<< "Enter the value you want to put : ";
            cin>>value;
            insertAtSpecific(head,position,value);
            break;
            }
        case 5:
            {
                cout<< "Enter the value you want to search in a unique linked list : ";
                cin>> value;
                int pos=searchValueUnique(head,value);
                cout<< "Your value is at position : "<<pos<<endl;
                break;
            }
        case 6:
            {
                cout<< "Enter the value you want to search in a duplicate linked list : ";
                cin>> value;
                //searchValueDuplicate(head,value);
                Test T;
                T=searchValueDuplicateReturn(head,value);
                if(T.positon[0]==1)
                {
                    cout<< "The Searched Value is not yet in the List"<<endl;
                }
                else
                {
                    int size=T.positon[0];
                    cout<< "The value is found at the position : ";
                    for(int i=1;i<size;i++)
                    {
                        cout<< T.positon[i];
                        if(i<size-1)
                        {
                            cout<< ",";
                        }
                    }
                    cout<<endl;
                }
            break;
            }
        case 7:
            {
                cout<< "Enter the value after which you want to put a new one (unique LLL) : ";
                cin>>value;
                int new_val;
                cout<< "Enter the value you want to insert : ";
                cin>>new_val;
                insertAfterSpecificValue(head,value,new_val);
                break;
            }
        case 8:
            {
                cout<< "Enter the value after which you want to put a new one (duplicate LLL) : ";
                cin>>value;
                int new_val;
                cout<< "Enter the value you want to insert : ";
                cin>>new_val;
                insertAfterSpecificValueDuplicate(head,value,new_val);
                break;
            }
        case 9:
            {
                deleteHead(head);
                break;
            }
        case 10:
            {
                deleteTail(head);
                break;
            }
        case 11:
            {
                cout<< "Enter the position you want to delete : ";
                cin>>position;
                deleteSpecificPositon(head,position);
                break;
            }
        case 12:
            {
                cout<< "Enter the value you want to delete (unique LLL) : ";
                cin>> value;
                deleteSpecificValue(head,value);
                break;
            }
        case 13:
            {
                cout<< "Enter the value you want to delete (Duplicate LLL) : ";
                cin>>value;
                deleteSpecificValueDuplicate(head,value);
                break;
            }
        case 50:
            {
                display(head);
                break;
            }

        }
        cout<< "Enter your Next Choice : ";
        cin>> choice;
    }
    display(head);

    return 0;
}
