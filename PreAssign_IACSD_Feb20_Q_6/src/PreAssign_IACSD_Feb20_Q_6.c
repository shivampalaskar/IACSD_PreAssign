/*
 ============================================================================
 Name        : PreAssign_IACSD_Feb20_Q_6.c
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
} NODE;

struct Node* createNode(int);
void addNodeAtFirst(int);
void addAtFirst(NODE*);
void addNodeAtLast(int);
void addAtLast(NODE*);
void addNodeAtGivenPos(int, int);
void addAtPos(NODE*, int);
void delFirst();
void delLast();
void delAtPos(int);
struct Node* getLastNode();
struct Node* get2ndLastNode();
NODE* getNodeAtPos(int pos);
int isEmpty();
int getLength();
int verifyPos(int);
void displayNodes();
int getData();
void swapNodes();
void changeNodePos();

struct Node *head = NULL;

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int choice, num, pos;
	do {
		printf("\nChose operation to perform : ");
		printf("\n1) Add at First Position");
		printf("\n2) Add at Last Position");
		printf("\n3) Add at given Position");
		printf("\n4) Display");
		printf("\n5) Change Node Position");
		printf("\n6) Exit");
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
			scanf("%d", &pos);
			if (verifyPos(pos)) {
				num = getData();
				addNodeAtGivenPos(num, pos);
				printf("\n Added Successfully at %d Position", pos);
			} else
				printf("\n Invalid Position");
			break;
		case 4:
			if (isEmpty())
				printf("\nLinked List is Empty");
			else
				displayNodes();
			break;
		case 5:
			if (isEmpty())
				printf("\nLinked List is Empty");
			else{
				changeNodePos();
				printf("\nPosition Changed Successfully");
			}
			break;
		}
	} while (choice != 6);
	return EXIT_SUCCESS;
}

void changeNodePos(){
	int pos;
	NODE* node;
	printf("\n Enter Node Position to change : ");
	scanf("%d",&pos);
	node = getNodeAtPos(pos);
	delAtPos(pos);
	printf("\n Enter New Position : ");
	scanf("%d",&pos);
	addAtPos(node,pos);
}

NODE* getNodeAtPos(int pos) {
	struct Node* tempPtr;
	tempPtr = head;
	if (pos == 1)
		return tempPtr;
	while ((--pos) > 0) {  // this will give (position-1)th index
		tempPtr = tempPtr->nextPtr;
	}
	return tempPtr;
}
void swapNodes(){
	NODE* trav=head;
	NODE* temp=head;
	int i=1;
	while(trav->nextPtr!=NULL){
		temp = trav;
		delAtPos(i++);
		addAtPos(temp,i++);
		if(trav->nextPtr==NULL){
			break;
		}
		else{
			trav = trav->nextPtr;
		}
	}
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
	if (pos == 1) {
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

int isEmpty() {
	if (head == NULL)
		return 1;
	else
		return 0;
}

int getData() {
	int num;
	printf("\n Enter Number : ");
	scanf("%d", &num);
	return num;
}

struct Node* createNode(int num) {
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = num;
	newNode->nextPtr = NULL;
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

void addAtFirst(NODE* temp) {
	struct Node* tempPtr;
	if (head == NULL)
		head = temp;
	else {
		tempPtr = head;
		head = temp;
		temp->nextPtr = tempPtr;
	}
}

void addNodeAtLast(int num) {
	struct Node* newNode;
	struct Node* tempPtr;
	newNode = createNode(num);
	if (head == NULL)
		head = newNode;
	else {
		tempPtr = getLastNode();
		tempPtr->nextPtr = newNode;
	}
}

void addAtLast(NODE* temp) {
	struct Node* tempPtr;
	temp->nextPtr=NULL;
	if (head == NULL)
		head = temp;
	else {
		tempPtr = getLastNode();
		tempPtr->nextPtr = temp;
	}
}

int verifyPos(int pos) {
	if (pos > 0 && pos <= (getLength()+1))
		return 1;
	else
		return 0;
}

void addNodeAtGivenPos(int num, int pos) {
	struct Node* newNode;
	struct Node* tempPtr;
	newNode = createNode(num);
	tempPtr = head;
	if (pos == 1) {
		addNodeAtFirst(num);
		return;
	}
	if(pos == (getLength()+1)){
		addNodeAtLast(num);
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

void addAtPos(NODE *temp, int pos) {
	struct Node* tempPtr;
	tempPtr = head;
	if (pos == 1) {
		addAtFirst(temp);
		return;
	}
	if (pos == (getLength() + 1)) {
		printf("\n ADD LAST");
		addAtLast(temp);
		return;
	}
	while ((--pos) > 1) {  // this will give (position-1)th index
		tempPtr = tempPtr->nextPtr;
	}
	if (pos == 1) {
		temp->nextPtr = tempPtr->nextPtr;
		tempPtr->nextPtr = temp;
	}
	return;
}

int getLength() {
	struct Node* tempPtr = head;
	int len = 0;
	while (tempPtr != NULL) {
		len++;
		tempPtr = tempPtr->nextPtr;
	}
	return len;
}

struct Node* getLastNode() {
	struct Node* tempPtr;
	tempPtr = head;
	struct Node *lastNode = head;
	while (tempPtr != NULL) {
		lastNode = tempPtr;
		tempPtr = tempPtr->nextPtr;
	}
	return lastNode;
}

struct Node* get2ndLastNode() {
	struct Node* tempPtr = head;
	struct Node *sndLastNode = head;
	while ((tempPtr->nextPtr) != NULL) {
		sndLastNode = tempPtr;
		tempPtr = tempPtr->nextPtr;
	}
	return sndLastNode;
}

void displayNodes() {
	struct Node* tempPtr;
	tempPtr = head;
	while (tempPtr != NULL) {
		printf("%d ", tempPtr->data);
		tempPtr = tempPtr->nextPtr;
	}
}
