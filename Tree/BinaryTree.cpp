#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node*left;
	Node*right;
};
//New node creation
Node *createnode(int data){
	Node* newnode;
	newnode = new Node;
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return(newnode);
}
//Traverse PreOrdser
void traversePreorder(Node *temp){
	if(temp!=NULL){
		cout<<" "<<temp->data;
		traversePreorder(temp->left);
		traversePreorder(temp->right);
		
	}
}

//Traverse Inorder

void traverseInorder(Node *temp){
	if(temp!=NULL){
		traverseInorder(temp->left);
		cout<<" "<<temp->data;
		traverseInorder(temp->right);
	}
}

//Traverse Postorder

void traversePostorder(Node *temp){
	if(temp!=NULL){
		traversePostorder(temp->left);
		traversePostorder(temp->right);
		cout<<" "<<temp->data;
	}
}

int main()
{ 
  Node *root = createnode(1);
  root->left=createnode(2);
  root->right=createnode(3);
  root->left->left=createnode(4);
  
  cout<<"Preorder traversal: "<<endl;
  traversePreorder(root);
  cout<<"\nTraverse Inorder: "<<endl;
  traverseInorder(root);
  cout<<"\nTraverse Post oderder: ";
  traversePostorder(root);
}

