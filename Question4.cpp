//Given a sorted linked list, remove all the duplicates.
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

void removeDuplicate(){
	int counter=0;
	Node *curr= head;
	Node *temp= curr->next;
	
	while(curr){
		while(temp){
			
			if(curr->score < temp->score){
				break;
			}
			if(curr->score == temp->score){
				Node *hapus=temp;
				curr->next= hapus->next;
				hapus->next= NULL;
				free(hapus);
			}
			temp= temp->next;
		}
		curr= curr->next;
	}
	
}

void print(){
	Node *curr= head;
	while(curr){
		printf("%d\n", curr->score);
		curr= curr->next;
	}
}




int main(){
	pushHead("aska",99);
	pushHead("baska",100);
	pushHead("ceska",150);
	pushHead("deska",160);
	pushHead("eska",200);
	pushHead("haksa",200);
	
	removeDuplicate();
	print();
	return 0;
}
