/*
 ============================================================================
 Name        : PreAssign_IACSD_Feb20_Q_16.c
 Author      : Shivam Palaskar
 Version     :
 Copyright   : Open source
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 ============================================================================
 Name        : PreAssign_IACSD_Feb20_Q_3.c
 Author      : Shivam Palaskar
 Version     :
 Copyright   : Open source
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *nextPtr;
}NODE;

struct Node* createNode(int);
struct Node* getLastNode();
struct Node* get2ndLastNode();
void addNodeAtLast(int);
void addNodeAtFirst(int);
void addNodeAtGivenPos(int,int);
int isEmpty();
int getLength();
int verifyPos(int);
void delFirst();
void delLast();
void delAtPos(int);
void displayNodes();
int getData();
NODE* getNodeAtGivenPos(int pos);
void subConNum();
int getDifference(int);

struct Node *head = NULL;

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int choice, num,pos;
	do {
		printf("\nChose operation to perform : ");
		printf("\n1) Add at First Position");
		printf("\n2) Add at Last Position");
		printf("\n3) Add at given Position");
		printf("\n4) Display");
		printf("\n5) Subtract Consecutive Numbers");
		printf("\n6)Exit");
		printf("\n Enter Choice : ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			num = getData();
			addNodeAtFirst(num);
			printf("\n Added Successfully");
			break;
		case 2:
			num = getData();
			addNodeAtLast(num);
			printf("\n Added Successfully");
			break;
		case 3:
			printf("\n Enter Position Number : ");
			scanf("%d",&pos);
			if (verifyPos(pos)) {
				num = getData();
				addNodeAtGivenPos(num,pos);
				printf("\n Added Successfully at %d Position", pos);
			}else
				printf("\n Invalid Position");
			break;
		case 4:
			if(isEmpty())
				printf("\nLinked List is Empty");
			else
				displayNodes();
			break;
		case 5:
			if (isEmpty())
				printf("\nLinked List is Empty");
			else {
				subConNum();
				printf("\n Successfully Subtracted");
			}
			break;
		}
	} while (choice != 6);
	return EXIT_SUCCESS;
}

void subConNum(){
	NODE* trav = head;
	int i=1;
	while (trav->nextPtr != NULL) {
		int subValue = getDifference(i);
		i = i + 2;
		addNodeAtGivenPos(subValue, i);
		trav = getNodeAtGivenPos(i);
		if (trav->nextPtr != NULL && (trav->nextPtr)->nextPtr != NULL)
			trav = getNodeAtGivenPos(i++);
		else
			break;
	}
}

int getDifference(int pos){
	NODE *node1,*node2;
	node1 = getNodeAtGivenPos(pos);
	pos++;
	node2 = getNodeAtGivenPos(pos);
	int subValue = (node1->data - node2->data);
	return subValue;
}

void delFirst(){
	head = head->nextPtr;
}

void delLast(){
	if(getLength()==1)
		head=NULL;
	else {
		struct Node* sndLastNode;
		sndLastNode = get2ndLastNode();
		printf("\n last node data : %d",sndLastNode->data);
		sndLastNode->nextPtr = NULL;
	}
}

void delAtPos(int pos) {
	struct Node* tempPtr;
	tempPtr = head;
	if(pos==1){
		delFirst();
		return;
	} else {
		while ((--pos) > 1) {   // this will give (position-1)th index
			tempPtr = tempPtr->nextPtr;
		}
		if (pos == 1) {
			tempPtr->nextPtr = (tempPtr->nextPtr)->nextPtr;
		}
	}
}

int isEmpty(){
	if(head==NULL)
		return 1;
	else
		return 0;
}

int getData(){
	int num;
	printf("\n Enter Number : ");
	scanf("%d",&num);
	return num;
}

struct Node* createNode(int num){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = num;
	newNode->nextPtr=NULL;
	return newNode;
}

void addNodeAtFirst(int num) {
	struct Node* newNode;
	struct Node* tempPtr;
	newNode = createNode(num);
	if (head == NULL)
		head = newNode;
	else {
		tempPtr = head;
		head = newNode;
		newNode->nextPtr = tempPtr;
	}
}
void addNodeAtLast(int num){
	struct Node* newNode;
	struct Node* tempPtr;
	newNode = createNode(num);
	if(head == NULL)
		head = newNode;
	else{
		tempPtr = getLastNode();
		tempPtr->nextPtr = newNode;
	}
}

int verifyPos(int pos){
	if (pos > 0 && pos <= getLength())
		return 1;
	else
		return 0;
}

void addNodeAtGivenPos(int num,int pos){
	struct Node* newNode;
	struct Node* tempPtr;
	newNode=createNode(num);
	tempPtr = head;
		if (pos == 1) {
			addNodeAtFirst(num);
			return;
		}
		while ((--pos) > 1) {  // this will give (position-1)th index
			tempPtr = tempPtr->nextPtr;
		}
		if (pos == 1) {
			newNode->nextPtr = tempPtr->nextPtr;
			tempPtr->nextPtr = newNode;
		}
	return;
}

NODE* getNodeAtGivenPos(int pos) {
	struct Node* tempPtr;
	tempPtr = head;
	if (pos == 1)
		return tempPtr;
	while ((--pos) > 0) {  // this will give (position-1)th index
		tempPtr = tempPtr->nextPtr;
	}
	return tempPtr;
}

int getLength() {
	struct Node* tempPtr = head;
	int len=0;
	while (tempPtr != NULL) {
		len++;
		tempPtr = tempPtr->nextPtr;
	}
	return len;
}

struct Node* getLastNode(){
	struct Node* tempPtr;
	tempPtr=head;
	struct Node *lastNode=head;
	while(tempPtr!=NULL){
		lastNode = tempPtr;
		tempPtr = tempPtr->nextPtr;
	}
	return lastNode;
}

struct Node* get2ndLastNode(){
	struct Node* tempPtr=head;
	struct Node *sndLastNode=head;
		while ((tempPtr->nextPtr) != NULL) {
			sndLastNode = tempPtr;
			tempPtr = tempPtr->nextPtr;
		}
	return sndLastNode;
}

void displayNodes(){
	struct Node* tempPtr;
	tempPtr=head;
	while(tempPtr!=NULL){
		printf("%d ",tempPtr->data);
		tempPtr = tempPtr->nextPtr;
	}
}

