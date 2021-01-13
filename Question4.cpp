//Given a sorted (ascending) linked list, manipulate it to become a sorted (descending) linked list.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char name[50];
	int score;
	struct Node *next;
}*head,*tail,*head2,*tail2;

struct Node *createNode(char *name, int score){
	Node *newNode= (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	newNode->score = score;
	newNode->next= NULL;
	return newNode;
	
}

void pushHead(char *name, int score){
	Node *temp= createNode(name,score);
	
	if(!head){
		head= tail= temp;
	}else{
		temp->next= head;
		head= temp; 
	}
}

void pushHead2(char *name, int score){
	Node *temp2= createNode(name,score);
	
	if(!head2){
		head2=tail2=temp2;
	}else{
		temp2->next= head2;
		head2= temp2; 
	}
	
}

void manipulate(){
	Node *curr=head;
	
	while(curr){
		pushHead2(curr->name, curr->score);
		curr= curr->next;
	}
}

void print(){
	Node *curr= head2;
	
	while(curr){
		printf("%s %d\n", curr->name, curr->score);
		curr= curr->next;
	}
	
}


int main(){
	
	pushHead("Abdul",95);
	pushHead("Baba",85);
	pushHead("Caca",75);
	
	print();
	manipulate();
	print();
	
	return 0;
}
