#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void red ();
void yellow ();
void reset ();
void bold_green();
void vigenere_cipher (char * plain_text, char * key);

int main(int argc , char ** argv) {
	
	char * key = "HOOK";
	char plain_text[101];
	
	bold_green ();
	printf("** 'HOOK' A KEY VALUE **\n");
	
	while(fgets(plain_text, sizeof(plain_text), stdin) != NULL) {
		
		reset ();
		printf("Please enter a sentence or word you want to encrypt: ");
		yellow ();
		fputs(plain_text, stdout);
		//scanf("%s", plain_text);
		//fgets(plain_text, sizeof(plain_text), stdin);
		reset ();
		printf("The ciphered text with key is : ");
		vigenere_cipher(plain_text, key);
	}
	return 0;
}
void vigenere_cipher (char * plain_text, char * key){
	
	char cipher;
	int cipher_value;
	int len = strlen(key);
	
	for (int i = 0; i<strlen(plain_text); i++){
		
		if(islower(plain_text[i])){
			cipher_value = ((int)plain_text[i]-97 + (int)tolower(key[i % len])-97) % 26 + 97;
			cipher = (char)cipher_value;
		}
		else {
			cipher_value = ((int)plain_text[i]-65 + (int)toupper(key[i % len])-65) % 26 + 65;
			cipher = (char)cipher_value;
		}
		if(isalpha(plain_text[i])){
			red();
			printf("%c", cipher);
		}
		else{
			red();
			printf("%c", plain_text[i]);
		}
	}
	
}

void reset () {
  printf("\033[0m");
}
void red () {
  printf("\033[1;31m");
}
void yellow () {
  printf("\033[1;33m");
}
void bold_green () {
  printf("\033[1;32m");
}

