//singly linked list implentation with operation

#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node*next;
}*head;
void createsll()
{
    cout<<"Create a sinly linked list."<<endl;
    struct node *newnode,*temp;
    int choice=1;
    head=0;
    while(choice){
        newnode = new node;
        cout<<"Enter a data: ";
        cin>>newnode->data;
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        cout<<"Do I want to continuew?[1/0] ";
        cin>>choice;
    }
}
int getlength()
{
    cout<<"\nLength of the singly linked list: ";
    int Count=0;
    struct node *temp;
    temp=head;
    while(temp!=0)
    {
        Count++;
    }
    cout<<Count<<endl;
    //return Count;
}
void insertBeg()
{
    cout<<"\nInsertion at Begining position."<<endl;
    struct node *newnode;
    newnode = new node;
    cout<<"Enter a data to insert: ";
    cin>>newnode->data;
    newnode->next=0;
    if(head==0)
    {
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}
void insertEnd()
{
    cout<<"\nInsertion at End position."<<endl;
    struct node *newnode,*temp;
    temp=head;
    newnode = new node;
    cout<<"Enter a data to insert: ";
    cin>>newnode->data;
    newnode->next=0;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void insertPos()
{
    cout<<"insertion at any position."<<endl;
    struct node *newnode,*temp;
    int pos,i=1,l;
   // l=getlength();
    temp=head;
    newnode = new node;
    cout<<"Enter a position: ";
    cin>>pos;
    if(pos<1||pos>l)
    {
        cout<<"Position is inavalid!!!!"<<endl;
    }
    else if(pos==1)
    {
        insertBeg();
    }
    else
    {
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        cout<<"Enter a data to insert: ";
        cin>>newnode->data;
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void deleteBeg()
{
    cout<<"\nDeletion from Begining."<<endl;
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);
}
void deleteEnd()
{
    cout<<"\nDeletion from End position."<<endl;
    struct node *temp, *prevnode;
    temp=head;
    while(temp->next!=0)
    {
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=0;
    free(temp);
}

void deletePos()
{
    cout<<"\nDeletion from any position."<<endl;
    struct node *prevnode,*temp,*nextnode;
    int pos,i=1,l;
    temp=head;
    //l=getlength();
    cout<<"Enter a positoin: ";
    cin>>pos;
    if(pos<1||pos>l)
    {
        cout<<"Invalid position."<<endl;
    }
    else if(pos==1)
    {
        deleteBeg();
    }
    else{

        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next=nextnode->next;
        free(temp);
    }
    //Or I can write
    /*else{
        while(i<pos)
        {
            prevnode=temp;
            temp=temp->next;
            i++;
        }
        prevnode->next=temp->next;
        free(temp);
    }*/
}

void Reverse()
{
   cout<<"\nReverse the list is."<<endl;
   struct node *prevnode,*currentnode,*nextnode;
   prevnode =0;
   currentnode=nextnode=head;
   while(nextnode!=0)
   {
       nextnode=nextnode->next;
       currentnode->next=prevnode;
       prevnode=currentnode;
       currentnode=nextnode;
   }
   head=prevnode;
}
void display()
{
    struct node *temp;
    temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=0);
}
int main()
{
    createsll();
    display();
    getlength();
//    insertBeg();
//    display();
//    insertEnd();
//    display();
//    insertPos();
//    display();
//    deleteBeg();
//    display();
//    deleteEnd();
//    display();
//    deletePos();
//    display();
//    Reverse();
//    display();
}

