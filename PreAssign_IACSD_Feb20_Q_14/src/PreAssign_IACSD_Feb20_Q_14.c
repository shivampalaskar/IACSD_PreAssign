/*
 ============================================================================
 Name        : PreAssign_IACSD_Feb20_Q_14.c
 Author      : Shivam Palaskar
 Version     :
 Copyright   : Open source
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printPermStr(char[],int,int);

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	char string[20];
	printf("\nEnter a string : ");
	scanf("%s",string);
	int len = strlen(string);
	for (int pos = 0; pos < len; pos++) {
		printPermStr(string,len,pos);
		printf(" ");
	}
	return EXIT_SUCCESS;
}

void printPermStr(char string[], int len, int pos) {
	int loop=len;
	while (loop--) {
		if (pos == len)
			pos = 0;
		printf("%c",string[pos++]);
	}
}
