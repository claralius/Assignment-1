#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	char name[50];
	int age;
	struct student *next;
}*head1, *tail1, *head2, *head3, *tail2, *tail3;

struct student *createNode(char *name, int age){
	student *newNode = (student*)malloc(sizeof(student));
	strcpy(newNode->name,name);
	newNode->age= age;
	newNode->next=NULL;
	return newNode;
}



void pushTail1(char *name, int age){
	student *temp= createNode(name,age);
	
	if(!tail1){ 
		head1=tail1= temp;
	}else{
		tail1->next= temp;
		tail1=temp;
	}
	
}

void pushTail2(char *name, int age){
	student *temp= createNode(name,age);
	
	if(!tail2){ 
		head2=tail2= temp;
	}else{
		tail2->next= temp;
		tail2=temp;
	}
	
}

void pushTail3(char *name, int age){
	student *temp= createNode(name,age);
	
	if(!tail3){ 
		head3=tail3= temp;
	}else{
		tail3->next= temp;
		tail3=temp;
	}
	
}

void merge(){
	student *temp1= head1;
	student *temp2= head2;
	
	while(temp1 && temp2){
		if(temp1->age <= temp2->age){
			pushTail3(temp1->name, temp1->age);
			temp1= temp1->next;
			
		}else if(temp1->age >= temp2->age){
			pushTail3(temp2->name, temp2->age);
			temp2= temp2->next;
		}
	
	}
	
	
	while(temp1){
		pushTail3(temp1->name, temp1->age);
		temp1= temp1->next;
	}
	
	while(temp2){
		pushTail3(temp2->name, temp2->age);
		temp2= temp2->next;
	}
	
}

void print(){
	student *temp3= head3;

	while(temp3){
		printf("%s\n", temp3->name);
		printf("%d\n", temp3->age);
		temp3= temp3->next;
	}
	
}


int main(){
	
	pushTail1 ("Mama", 18);
	pushTail1 ("Papa", 20);
	pushTail1 ("Tante", 25);
	pushTail2 ("Adik", 21);
	pushTail2 ("Kakak", 22);
	pushTail2 ("Paman", 44);
	
	merge();
	print();
	
	return 0;
}
