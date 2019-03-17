//first include libary
#include<iostream>
using namespace std;
class node{		//creating the class node
public:
int data;		//creating the different nodes we need
node*left;
node*right;
node*parent;
	node(int value){		//defining the constructor
		data=value;
		left=NULL;
		right=NULL;
		parent=NULL;
	}
};
class bist{				//creating the class bist:-binary search tree
public:
node*root;
	bist(){				//defining constructor for the class
	root=NULL;	
	}
	void insert(int value){
		if(root==NULL){		//if empty
			root=new node(value);
		}
		else{			//else use recursion
			inserthelper(root,value);		
		}
	}
	void inserthelper(node*current,int value){
		if(current->data >= value){
			if(current->left==NULL){		//for left side values :- stopping condition
				current->left=new node(value);
			}
			else{
				inserthelper(current->left,value);
			}
		}
		else{
			if(current->right==NULL){			//for right side values
				current->right=new node(value);
			}
			else{
				inserthelper(current->right,value);
			}
		}
	}
	void display(){
		displayhelper(root);
		cout<<"NULL"<<endl;
	}
	void displayhelper(node*current){
		if(current==NULL) return;			//stopping condition
			else{
			displayhelper(current->left);
			cout<<current->data;
			cout<<"->";
			displayhelper(current->right);
			}
	}
	node*search(int value){
	return searchhelper(root,value);
	}
	node*searchhelper(node*current,int value){
		if(current==NULL or current->data==value) return current;
		else{
			if(current->data >= value) return searchhelper(current->left,value);
			else return searchhelper(current->right,value);		
		}
	}
	void print2d(){
		print2dhelper(root,0);
	}
	void print2dhelper(node*current,int space){
		if(current==NULL) return;
		else{
			print2dhelper(current->right,space+1);
			for(int i=0;i<space;i++){
				cout<<"  ";
			}		
			cout<<current->data<<endl;
			print2dhelper(current->left,space+1);
		}
		
	}


};

//main function
int main(){
bist b;
	for(int i=1;i<11;i++){
		b.insert(i);
	}
b.display();
	if(b.search(5)!=NULL) cout<<"TRUE"<<endl;
	else cout<<"FALSE"<<endl;
b.print2d();
}
