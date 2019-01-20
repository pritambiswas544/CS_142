//some functions like insert,delete,intsertAt,deleteAt and counitems to be performed
#include<iostream>
using namespace std;

			//defining the class node for list

	class Node{
	public:
			//Data
	int data;
			//pointer to next and previous node
		Node * next;
		Node * prev;
			//constructor to make the pointers to point to NULL by default
	Node(){
		next=NULL;
		prev=NULL;
		
	}
};
			//creating the class of doubleylinkedlist

	class DLL{
	public:
			//ptr to the head
		Node * head;
		Node * tail;
			//creating a constructor so that the ptr points to head by default
	DLL(){
		head=NULL;
		tail=NULL;
	}
			//inserting a node at the end
	void insert(int value){
			//creating a node and pointing "temp" to it
		Node * temp= new Node;
		temp->data=value;
			//condition for the list being empty
	if(head==NULL){
		head=temp;
	}
			//condition for the list not being empty
	else{
		Node * current=head;
			//while loop to make the ptr current to point to the previous node of last node
	while(current->next!=NULL)
		current=current->next;
			//making ptr current to point to the last element
		current->next=temp;
		temp->prev=current;
	}
}
			//inserting is a particular position
	void insertAt (int pos,int value){
			//creating ptr current and making it point to the head
		Node * current = head;
			//creating a loop to reach towards the (pos-1)th node
		int i=1;
	while(i<pos-1){
		i++;
		current=current->next;
	}
			//creating a node and ptr to point to it
		Node * temp = new Node;
			//value
		temp->data=value;
			//moving the pointers
		temp->next=current->next;
		current->next->prev=temp;
		current->next=temp;
		temp->prev=current;
	}
			//deleting the last node
	void delet(){
			//a ptr tha t stores the address of the last element
		Node * temp=tail;
			//a pointer that points to the head
		Node * current = head;
			//a loop to reach to the previous node of last element
	while(current->next!=tail){
		current=current->next;
	}
			//the prevous node has to point to null
		current->next=NULL;
			//update the tail part
		tail=current;
			//deleting the last element
	delete temp;
	}
			//deleting a node at a particular position
	void deletAt(int pos){
			//storing the address of head to a new ptr
		Node*curr=head;
			//if 1st node has to be deleted i.e. head
	if(pos==1){
			//moving the head part
		head=curr->next;
		delete curr;
		return;
	}
			//for other positions 
	for(int i=1;i<pos-1;i++){
		curr=curr->next;
	}
		Node*temp1=curr->next;
		
			//adjust or moving the pointers
		curr->next=temp1->next;
		temp1->next->prev=curr;
			//deleteing the node
		delete temp1;
	}
			//counting the number of elements
	int countItemms(){
			//storing temp2 in head
		Node * temp2=head;
			//loop to go to the last node
		int j=0;
		while(temp2!=0){
			j++;
			temp2->next=temp2;
		}
		cout<<j;
	}
			//for displaying the value of nodes
void display(){
		Node * current = head;
		while(current!=NULL){
		cout<<current->data<<"->"<<endl;
		current=current->next;
		}
		cout<<endl;
	}
	
};		
			//main
	int main(){
		DLL dll1;
		
        	for(int i= 1; i < 11; i++){
       		dll1.insert(i);
    }
		dll1.display();
		dll1.insertAt(5,11);
		dll1.insertAt(9,12);
		
		dll1.display();
		
		dll1.delet();
		dll1.display();

		dll1.deletAt(6);
		dll1.display();
}
		
	
	
		
			

		
	
			
		
		
	
	
	 
	
	 

