#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char password[] = "\x2c\x35\x32\x3f\x34\x31\x39";

int check(char* input){
	for(int i = 0; i < sizeof(password) - 1; ++i){
		password[i] ^= 0x5c;
	}
	return memcmp(password, input,sizeof(password)-1);
}

int main(int argc, char **argv){
	if (argc != 2){
		printf("Usage: %s <password>\n",argv[0]);
		return EXIT_FAILURE;
	}
	if (strlen(argv[1]) == (sizeof(password)-1) && check(argv[1])==0){
		puts("ACCESS GRANTED! YOU HAVE PASSED LEVEL 2!");
		return EXIT_SUCCESS;
	}
	puts("ACCESS DENIED! FAILED.");
	return EXIT_FAILURE;
}