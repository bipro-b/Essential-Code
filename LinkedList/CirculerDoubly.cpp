//Implementation Doubly circular linked list wiht operatoin
#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node *next;
struct node *prev;
}*head,*tail;
void createDCLL()
{
    cout<<"Creation doubly circular linked list."<<endl;
    struct node * newnode;
    int choice=1;
    head=0;
    while(choice)
    {
        newnode=new node;
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->next=0;
        newnode->prev=0;
        if(head==0)
        {
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }
        cout<<"Do I want to continue?[1/0] ";
        cin>>choice;
    }
}
void getlength()
{
    cout<<"\nLength of the list is: ";
    struct node *temp;
    int Count =1;
    temp=head;
    while(temp!=tail)
    {
        temp=temp->next;
        Count++;
    }
    cout<<Count<<endl;
}
//Insertion operation
void insertBeg()
{
    cout<<"\n\nInsertion at Begining."<<endl;
    struct node *newnode;
    newnode = new node;
    cout<<"Enter data: ";
    cin>>newnode->data;
    newnode->next=0;
    newnode->prev=0;
    if(head==0)
    {
       head=tail=newnode;
       newnode->next=tail;
       newnode->prev=head;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=tail;
        tail->next=newnode;
        head=newnode;
    }
}
void insertEnd()
{
   cout<<"\n\nInsertion at Begining."<<endl;
    struct node *newnode;
    newnode = new node;
    cout<<"Enter data: ";
    cin>>newnode->data;
    newnode->next=0;
    newnode->prev=0;
    if(head==0)
    {
       head=tail=newnode;
       newnode->next=tail;
       newnode->prev=head;
    }
    else
    {
        newnode->prev=tail;
        tail->next=newnode;
        newnode->next=head;
        head->prev=newnode;
        tail=newnode;
    }
}
void insertPos()
{
    cout<<"\n\nInsertion any position."<<endl;
    struct node *temp, *newnode;
    temp=head;
    int pos,i=1,l;
    cout<<"Enter a position: ";
    cin>>pos;
    if(pos<1||pos>l)
    {
        cout<<"Invalid position!"<<endl;
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
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
    }
}
//Deletion insertion
void deleteBeg()
{
    cout<<"\n\nDeletion from Begining."<<endl;
    struct node*temp;
    temp=head;
    if(head==0)
    {
        cout<<"List is empty!"<<endl;
    }
    else if(head->next==head)
    {
        head=tail=0;
        free(temp);
    }
    else
    {
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
}
void deleteEnd()
{
      cout<<"\n\nDeletion from End."<<endl;
    struct node*temp;
    temp=tail;
    if(head==0)
    {
        cout<<"List is empty!"<<endl;
    }
    else if(head->next==head)
    {
        head=tail=0;
        free(temp);
    }
    else
    {
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);
    }
}
void deletePos()
{
    cout<<"\n\nDeletion from any position."<<endl;
    struct node *temp;
    int pos,i=1,l;
    temp=head;
    cout<<"Enter Data: ";
    cin>>pos;
    if(pos<1||pos>l)
    {
        cout<<"Invalid position!"<<endl;
    }
    else if(pos==1)
    {
        insertBeg();
    }
    else
    {
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    if(temp->next==head)
    {
        tail=temp->prev;
        free(temp);
    }
    else
    {
        free(temp);
    }
}
//Reverse operation
void Reverse()
{
    cout<<"\n\nReverse of the list."<<endl;
    struct node *current, *nextnode;
    current = head;
    while(current!=tail)
    {
        nextnode=current->next;
        current->next=current->prev;
        current->prev=nextnode;
        current=nextnode;
    }
    current =head;
    head=tail;
    tail=current;
   /* cout<<"List is: "<<endl;
    struct node *temp;
    temp=head;
    do{
        cout<<temp->data<<" ";
        //temp=temp->next;
    } while ((temp = temp->next) != head->next);*/
}

void display()
{
    cout<<"List is: "<<endl;
    struct node *temp;
    temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail->next);
}
int main()
{
    createDCLL();
    display();
    getlength();
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
   // Reverse();
    //display();
}
