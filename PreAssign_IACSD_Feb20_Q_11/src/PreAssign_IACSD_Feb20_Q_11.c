/*
 ============================================================================
 Name        : PreAssign_IACSD_Feb20_Q_11.c
 Author      : Shivam Palaskar
 Version     :
 Copyright   : Open source
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	FILE *fp1,*fp2;
	fp1 = fopen("file1.txt","r");
	fp2 = fopen("file2.txt","w+");
	char string[10];
	int loop=0;
	while(fgets(string,10,fp1)!=NULL)
		loop++;
	fseek(fp1,0,SEEK_SET); // No Need to set this function as after reading whole file fp1 will automatically reset
	while (loop>0) {
		printf("\n Loop : %d",loop);
		for(int i=0;i<loop;i++)
			fgets(string,10,fp1);
		fputs(string, fp2);
		fseek(fp1,0,SEEK_SET);
		loop--;
	}
	fclose(fp1);
	fclose(fp2);
	return EXIT_SUCCESS;
}
