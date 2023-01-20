//Doubly linked list implementaion with operation
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct  node * prev;
}*head,*tail;
void createdll()
{
    cout<<"Creation doubly link list."<<endl;
    struct node *newnode;
    int choice=1;
    head=0;
    while(choice){
        newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->prev=0;
        newnode->next=0;
        if(head==0)
        {
            head=tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        cout<<"Do I want to continue?[1/0] ";
        cin>>choice;
    }
}
int getlength()
{
//    cout<<"\nLength of the list is: ";
    struct node *temp;
    int Count =0;
    temp=head;
    while(temp!=0)
    {
        temp=temp->next;
        Count++;
    }
//    cout<<Count<<endl;
    return Count;
}
//Insertion operation
void insertBeg()
{
    cout<<"\nInsertion at begining position."<<endl;
    struct node *newnode;
    newnode =new node;
    cout<<"Enter a data: ";
    cin>>newnode->data;
    newnode->prev=0;
    newnode->next=0;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}
void insertEnd()
{
    cout<<"\n\nInsertion at End position."<<endl;
    struct node *newnode;
    newnode =new node;
    cout<<"Enter a data: ";
    cin>>newnode->data;
    newnode->prev=0;
    newnode->next=0;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
}
void insertPos()
{
    cout<<"\n\nInsert any position."<<endl;
    struct node *newnode,*temp;
    int pos,i=1,l;
    temp=head;
    //l=getlength();
    cout<<"Enter a position: ";
    cin>>pos;
    if(pos<1||pos>l)
    {
        cout<<"Position is invalisd!!!!"<<endl;
    }
    else if(pos==1)
    {
        insertBeg();
    }
    else
    {
        newnode =new node;
        cout<<"Enter a data: ";
        cin>>newnode->data;
        newnode->prev=0;
        newnode->next=0;
        while(i<pos-1) // 1 2->3* 3 [newnode->prev=3*/next->] 4 5 6
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        temp->next->prev=newnode;
    }
}
//Deletion operation
void deleteBeg()
{
    cout<<"\n\nDeletion from Begining."<<endl;
    struct node *temp;
    temp=head;
    head=head->next;
    head->prev=0;
    free(temp);
}
void deleteEnd()
{
    cout<<"\n\nDeletion from End."<<endl;
    struct node * temp;
    if(tail==0)
    {
        cout<<"List id empty!!!"<<endl;
    }
    else{
        temp=tail;
        tail=tail->prev;
        tail->next=0;
        free(temp);
    }
    //or i can write
   /* else{
            temp=tail;
       tail->prev->next=0;
       tail=tail->next;
       free(temp;)
    }*/
}
void deletePos()
{
    cout<<"\n\nDelete from specific position......"<<endl;
    int pos ,i=1,l;
    struct node *temp;
    temp=head;
    cout<<"Enter a position: ";
    cin>>pos;
    if(pos==1)
    {
        deleteBeg();
    }
    else if(pos==l)
    {
        deleteEnd();
    }
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}
//Reverse operation
void Reverse()
{
    cout<<"\n\nReverse of the list."<<endl;
    struct node *current, *nextnode;
    current=head;
    while(current!=0)
    {
        nextnode=current->next;
        current->next=current->prev;
        current->prev=nextnode;
        current=nextnode;
    }
    current =head;
    head=tail;
    tail=current;
    	/*struct node* temp = head;
	cout << "List is : " << endl;

	do {
		cout << temp->data <<" ";
	} while ((temp = temp->next) != NULL);*/
}
void display()
{
    cout<<"Now List is: ";;
    struct node *temp;
    temp=head;
    do{
       cout<<temp->data<<" ";
       temp=temp->next;
       }while(temp!=0);
}
int main()
{
    createdll();
    display();
    cout<<getlength();
    /*insertBeg();
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
    display();*/
    Reverse();
    display();
}
