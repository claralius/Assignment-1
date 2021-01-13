#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char name[50];
	int score;
	struct Node *next;
}*head,*tail;

struct Node *createNode (char *name, int score){
	Node *newNode= (Node*)malloc(sizeof(Node));
	strcpy(newNode->name,name);
	newNode->score= score;
	newNode->next = NULL;
	return newNode;
}


void pushHead(char *name, int score){
	Node *temp= createNode(name,score);
	
	if(!head){
		head = tail = temp;
	}else{
		temp->next= head;
		head= temp;
	}
	
}

//void pushTail (char *name, int score){
//	Node *temp= createNode(name,score);
//	
//	if(!=tail){
//		head=tail=temp;
//	}else{
//		temp->next= tail;
//		tail= temp;
//	}
//	
//}

void minMax(){
	Node *curr = head;
	Node *max = head;
	Node *min = head;
	
	while(curr){
		if(curr->score <= min->score){
			min = curr;
		}
		
		if(curr->score >= min->score){
			max = curr;
		}
		
		curr= curr->next;
	}
	
	printf("Max : %d\n", max->score);
	printf("Min : %d\n", min->score);
	printf("Range : %d\n", max->score- min->score);
	
}






int main(){
	
	pushHead("Clara",95);
	pushHead("Livia", 100);
	pushHead("Rio", 77);
	pushHead("Harris", 80);
	pushHead("Maria", 55);
	pushHead("Anna", 66);	
	
	minMax();
	
	
	return 0;
}
