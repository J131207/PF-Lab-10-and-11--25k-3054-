#include<stdio.h>
#include<string.h>
int main(){
	int i;
	 char input[20];
	 char words[5][100]={
	         "Racer",
			 "Cocomo",
			 "jojo",
			 "mojo",
			 "Hero"};
		
	printf("Enter word to search: ");
	scanf("%s", input);
	
	for(i=0; i<5; i++){
		if(strcmp(words[i],input)==0){
			printf("Found");
			break;
		}
	}if(strcmp(words[i],input)!=0){
		printf("Not Found");
	}	 
	
	
	return 0;
}
