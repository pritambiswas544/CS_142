#include<iostream>
using namespace std;

			//creating a class named NODE



 class Node{
	public:


			//inserting the contents or the members of the class
	int data;
	
			//Pointer to the next Node
	Node * next;
			//default constructor to make the ptr part of the node to 					point to NULL
	Node(){
		next=NULL;	
	}
};

			//creating the linked list class to link up the nodes after 				creating
 class LinkedList{
	public:
	

			//Head-node type ptr

	Node * head;
	Node * tail;

			//creating a default constructor that assings each ptr to 				initially point to NULL when the list is empty
	LinkedList(){
		head=NULL;
		tail=NULL;
	}
			//performing some operations on the node
			//Insertion at the 1st position
			//creating a function for insertion
void insert(int value){
			//If 1st Node is added
		Node * temp= new Node;
			//insert value in the node
		temp->data=value;
			//1st Node only
		if(head==NULL){
			head=temp;
			tail=temp;
			
		}
		
		
			//if Node enters other i.e. at last position
		else{

			tail->next=temp;
			tail=temp;
			
		}
			
	}
			
			//for inserting the node at any other position
			//creating the function

void insertAt(int pos,int value){
			//Reach the position before the pos
		Node*current=head;
			//creating a loop for accessing the (pos-1)th element of 				linked list
		int i=0;
		while(i<pos-2){
			i++;
			current=current->next;
		}
			//create a node
		Node * temp= new Node;
			//inserting value
		temp->data=value;
			//moving ptrs
		temp->next=current->next;
		current->next=temp;


		}

	
			//Deletion of the last element

void delet(){
			//store the tail in temp
		Node*temp=tail;
			//before tail has to point to null
		Node * current = head;
		while(current->next !=tail){
		
		current=current->next;
		}
		current->next=NULL;
			//update tail
		tail=current;
		
		}

void deleteAt(int pos){
	Node*temp1=head;
			//if there is only 1 element
	if(pos==1){
		head=temp1->next;
		delete temp1;
	return;
	}
			//for any other position
	for(int i=0;i<pos-2;i++){
		temp1=temp1->next;
	}
	Node*temp2=temp1->next;
	temp1->next=temp2->next;
		delete temp2;
}
			//for displaying the elements
				

//countItems
int countItems(){
		Node *current = head;
		int c=0;
		while(current !=NULL){
			current = current->next;
			c++;
		}
		return c;
}
void display(){
		Node * current = head;
		while(current!=NULL){
		cout<<current->data<<"->"<<endl;
		current=current->next;
		}
		cout<<endl;
	}
	
};		
	

int main(){
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insertAt(1,4);

	l1.display();
	l1.delet();
	l1.display();
	l1.deleteAt(2);
	l1.display();
	cout<<"The number of items is:"<<l1.countItems()<<endl;
	return 0;
 }

