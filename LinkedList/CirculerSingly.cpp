//Singly circular linked list implented with operation
#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node *next;
}*tail;
void createscll()
{
    cout<<"Creation of singly circular linked list."<<endl;
    struct node * newnode;
    int choice=1;
    tail=0;
    while(choice){
        newnode = new node;;
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->next=0;
        if(tail==0)
        {
            tail=newnode;
            tail->next=newnode;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        cout<<"Do you want to continue??[1/0]: ";
        cin>>choice;
         }
}
//Inserton operation
void insertBeg()
{
    cout<<"\n\nInsertion at Begining."<<endl;
    struct node *newnode;
    newnode= new node;
    cout<<"Enter data: ";
    cin>>newnode->data;
    newnode->next=0;
    if(tail==0)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
    }
}
void insertEnd()
{
    cout<<"\n\nInsertion at End."<<endl;
    struct node *newnode;
    newnode= new node;
    cout<<"Enter data: ";
    cin>>newnode->data;
    newnode->next=0;
    if(tail==0)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}
void insertPos()
{
    cout<<"\n\nInsertion any position."<<endl;
    struct node *newnode, *temp;
    int pos,i=1,l;
    cout<<"Enter a position: ";
    cin>>pos;
    if(pos<1||pos>l)
    {
        cout<<"Position is invalid!"<<endl;
    }
    else if(pos==1)
    {
        insertBeg();
    }
    else
    {
        newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->next=0;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
//Deletion opwration
void deleteBeg()
{
    cout<<"\n\nDelete from begining....."<<endl;
 struct node *temp;
 temp=tail->next;
 if(tail==0)
  cout<<"Link is empty!!"<<endl;
 else if(temp->next==temp)
 {
     tail=0;
     free(temp);
 }
 else{

    tail->next=temp->next;
    free(temp);
 }
}
void deleteEnd()
{
    cout<<"\n\nDelete from End positon.."<<endl;
    struct node *current, *previous;
    current = tail->next;
    if(tail==0)
    {
        cout<<"List is empty!!1"<<endl;
    }
    else if(current->next==current)
    {
        tail=0;
        free(current);
    }
    else
    {
        while(current->next!=tail->next)
        {
            previous=current;
            current = current->next;
        }
        previous->next=tail->next;
        tail=previous;}
        free(current);
}
void deletePos()
{
    cout<<"\n\nDeletion fro any position."<<endl;
    struct node *current,*nextnode;
    int pos,i=1,l;
    current=tail->next;
    cout<<"Enter a position: ";
    cin>>pos;
    if(pos<1||pos>l)
    {
        cout<<"Invalid position!"<<endl;
    }
    else if(pos==1)
    {
        deleteBeg();
    }
    else
    {
        while(i<pos-1)
        {
            current=current->next;
            i++;
        }
        nextnode=current->next;
        current->next=nextnode->next;
        free(nextnode);
    }
}
//reverse
void Reverse()
{
    cout<<"\n\nReverse of the list"<<endl;
    struct node *current,*prev,*nextnode;
    current = tail->next;
    nextnode=current->next;
    if(tail==0)
    {
        cout<<"List is empty!"<<endl;
    }
    else{
        while(current!=tail)
        {
            prev=current;
            current=nextnode;
            nextnode=current->next;
            current->next=prev;
        }
        nextnode->next=tail;
        tail=nextnode;
    }
}
void display()
{
    cout<<"List is:"<<endl;
    struct node *temp;
    temp=tail->next;
    do{

        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail->next);
}
int main()
{
    createscll();
    display();
    insertBeg();
    display();
    insertEnd();
    display();
    insertPos();
    display();
    deleteBeg();
    display();
    deleteEnd();
    display();
    deletePos();
    display();
    Reverse();
    display();
}

