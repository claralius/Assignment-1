//Find the middle element of a linked list.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char name[50];
	int score;
	struct Node *next;
}*head, *tail;

struct Node *createNode(char *name, int score){
	Node *newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	newNode->score = score;
	newNode->next = NULL;
	
	return newNode;
}

void pushHead(char *name, int score){
	Node *temp= createNode(name, score);
	
	if(!head){
		head= tail= temp;
	}else{
		temp->next= head;
		head= temp;
	}
}


void pushTail (char *name, int score){
	Node *temp= createNode(name,score);
	
	if(!tail){
		head= tail= temp;
	}else{
		temp->next = tail;
		tail= temp;
	}
}

void findMid(){
	int count=0;
	
	Node *curr= head;
	
	while(curr){
		curr = curr->next;
		count++;
	}
	
	curr= head;
	int counter=0;
	while(curr){
		if(counter==count/2){
			printf("Mid : %d\n", curr->score);
			break;
		}
		counter++;
		curr = curr->next;
	}
	
}


int main(){
	
	pushHead("Clara",90);
	pushHead("Tom",85);
	pushHead("Jerry",66);
	pushHead ("Livia",77);
	pushHead("Mako",68);
	pushHead("Asami",89);
	
	findMid();
	
	
	return 0;
}
