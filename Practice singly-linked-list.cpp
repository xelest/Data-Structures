//Practice Singly Linked List
//Created by: Charlene Diana Schenk

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;


struct Node{
	int data;
	Node *next;
};

int main(){
	Node *head,*newNode,*current,*temp,*temp2;

	head=new Node();
	head->data=100;

	newNode=new Node();
	newNode->data=200;

	head->next=newNode;

	newNode=new Node();
	newNode->data=300;

	head->next->next=newNode;

	newNode->next=0;	

	newNode=new Node();
	newNode->data=50;
	newNode->next=head;
	head=newNode;

	current=head;
	do	{
		cout<<current->data<<endl;
		current=current->next;
	}while(current!=NULL);

	newNode=new Node();
	newNode->data=250;

	int pos=0;
	current=head;
	do{
		pos++;
		temp=current->next;
		if(temp->data>newNode->data)
			break;
	}while(current!=NULL);
	
	int pos2=0;
	do{
		pos2++;
		temp2
		if(pos2==pos)
			
	}while(pos2!=pos);

	cin.ignore();
	return 0;
}
