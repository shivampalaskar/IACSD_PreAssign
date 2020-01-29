/*
 ============================================================================
 s Name        : PreAssign_IACSD_Feb20_Q_4.c
 Author      : Shivam Palaskar
 Version     :
 Copyright   : Open source
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void printNum(int, int);
void setSpace(int);

int main(void) {
	int len = 5; // Only set this len and output will generate accordingly
	for (int i = 0; i < (len * 2 + 1); i++) {
		if (i <= len) {
			printNum(i, (len * 2 + 1));
			printf("\n");
		} else {
			printNum(((len * 2 + 1) - 1) - i, (len * 2 + 1));
			printf("\n");
		}
	}
	return EXIT_SUCCESS;
}

void printNum(int num, int height) {
	int loop = num + (num + 1), check = 1;
	setSpace(height - loop);
	while (loop--) {
		if (num >= 0 && check == 1) {
			printf("%d", num--);
		}
		if (num >= 0 && check == 0) {
			printf("%d", num++);
		}
		if (num < 0) {
			num = 1;
			check = 0;
		}

	}
}

void setSpace(int pos) {
	for (int i = 0; i < pos; i++)
		printf(" ");
}
