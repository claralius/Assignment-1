//Find the Nth node from the end of the linked list.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char name[50];
	int score;
	struct Node *next;
}*head,*tail;

struct Node *createNode(char *name, int score){
	Node *createNode= (Node*)malloc(sizeof(Node));
	strcpy(createNode->name, name);
	createNode->score= score;
	createNode->next = NULL;
	return createNode;
}

void pushHead(char *name, int score){
	Node *temp= createNode(name, score);
	
	if(!head){
		head=tail=temp;
	}else{
		temp->next=head;
		head= temp;
	}
}


void finding(int n){
	Node *curr= head;
	int count=0;
	
	while(curr){
		curr= curr->next;
		count++;
	}
	
	int formula= count-n+1;
	
	curr= head;
	int counter=0;
	while(curr){
		counter++;
		if(counter==formula){
			printf("%s %d\n",curr->name, curr->score);
			break;
		}
		curr= curr->next;
	}
	
}



int main(){
	pushHead("Pli",100);
	pushHead("Tenzin",95);
	pushHead("Eska",85);
	pushHead("Livia",75);
	pushHead("Rio",65);
	pushHead("Maria",55);
	pushHead("Nata",45);
	
	finding(3);
	
	
	
	return 0;
}
