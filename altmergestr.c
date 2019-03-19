/*Program to merge two strings.
 *Name: Shubham Mishra
 *Roll No: 18IE10022
 */
 
#include <stdio.h>
#include <string.h>

#define SIZE 101

int concat(char *dest, char **source, int *offset){
	//Appends a word from source to dest
	//Returns 0 if no word remains in source, else returns 1
	//Character being pointed by source has to be updated also.
	//That is why pointer to pointer to character is used.
	
	if (**source == '\0')
		return 0;
	else{
		while (**source != ' ' && **source != '\0'){
			dest[*offset] = **source;
			(*offset)++;
			(*source)++;
		}
		(*source)++;
		return 1;
	}
}

void mergestr(char *s, char *s1, char *s2){
	//Merges s1 and s2 in s taking words alternatively
	
	char **source = &s1;
	int offset = 0;
	
	while (concat(s, source, &offset)){
		s[offset++] = ' ';
		if (*source == s1)
			source = &s2;
		else 
			source = &s1;
	}
	
	//A string has finished.
	//Switch to the other string
	//and copy down the rest of it.
	
	if (*source == s1)
		source = &s2;
	else 
		source = &s1;
		
	while (**source != '\0'){
		s[offset] = **source;
		offset++;
		(*source)++;
	}
	
	s[offset] = '\0';
	
}

int main(){
	char s1[SIZE];
	char s2[SIZE];
	char s[2 * SIZE];
	
	printf("Enter s1:  ");
	scanf("%[^\n]", s1);
	getchar();
	printf("Enter s2:  ");
	scanf("%[^\n]", s2);
	getchar();
	
	//mergestr works only when there is a trailing space
	s1[strlen(s1) + 1] = '\0';
	s1[strlen(s1)] = ' ';
	s2[strlen(s2) + 1] = '\0';
	s2[strlen(s2)] = ' ';	


	mergestr(s, s1, s2);
	
	printf("%s\n", s);
	return 0;
}
	
	
		 
	
	
