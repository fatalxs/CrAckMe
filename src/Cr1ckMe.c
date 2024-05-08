#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char password[] = "pokeme";

int check(char* input){
	return memcmp(password, input,sizeof(password)-1);
}

int main(int argc, char **argv){
	if (argc != 2){
		printf("Usage: %s <password>\n",argv[0]);
		return EXIT_FAILURE;
	}
	if (strlen(argv[1]) == (sizeof(password)-1) && check(argv[1])==0){
		puts("ACCESS GRANTED! YOU HAVE PASSED LEVEL 1!");
		return EXIT_SUCCESS;
	}
	puts("ACCESS DENIED! FAILED.");
	return EXIT_FAILURE;
}