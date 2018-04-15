//Practice Doubly Linked List
//Created by: Charlene Diana Schenk
//DoublyLinkedList Stack - PALINDROME

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;


struct nodeType{
	char data;
	struct nodeType *next;
	struct nodeType *prev;
} *head,*newNode,*myList,*current,*top;

void Push(char e){
	newNode=new nodeType;
	newNode->data=e;
	newNode->prev=top;
	newNode->next=NULL;
	top->next=newNode;
	top=newNode;
};

char Pop(){
	char e=top->data;
	top=top->prev;
	return e;
};

char Top(){
	char e=top->data;
	return e;
};

int main(){
	myList=new nodeType;

	head=myList;
	top=head;
	
	char palindrome[1000];
	cout<<"Input a word, phrase or sentence: ";
	cin.getline(palindrome,1000);

	int i=0,size=0;
	char temp[1000];
	while(palindrome[i]!='\0'){
		if(palindrome[i]!=' '){
			temp[size]=tolower(palindrome[i]);
			size++;
		}
		i++;
	}

	for(i=0;i<=size/2-1;i++)
		Push(temp[i]);

	if(size%2==1)
		i++;

	bool palindrometf=true;
	while(i<size){
		if(Pop()!=temp[i]){
			palindrometf=false;
			break;
		}
		i++;
	}

	if(palindrometf)
		cout<<"IS a palindrome!";
	else
		cout<<"IS NOT a palindrome!";

	getch();
	return 0;
}
