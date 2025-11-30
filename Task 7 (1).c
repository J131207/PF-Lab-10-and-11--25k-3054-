#include<stdio.h>
int vowelCount(char str[], int i){
	if(str[i]=='\0'){
		return 0;
	}
	if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' 
	    ||str[i] == 'o' || str[i] == 'u' ||str[i] == 'A'
	    || str[i] == 'E' || str[i] == 'I' ||str[i] == 'O'
	    || str[i] == 'U'){
    	return 1 + vowelCount(str,i+1);	
	}
	else
		return vowelCount(str,i+1);
}

int main(){
	char str[100];
	printf("Enter string: ");
	scanf(" %[^\n]",&str);
	
	printf("Number of vowels in the given string: %d",vowelCount(str,0) );
	return 0;
}
