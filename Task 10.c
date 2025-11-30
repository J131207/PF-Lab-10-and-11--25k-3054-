#include<stdio.h>
#include<string.h>
int main(){
	char words[5][20];
	int i,j,len;
	
	printf("Enter 5 words:\n");
	for(i=0;i<5;i++){
		scanf("%s", words[i]);
	}
	
	for(i=0;i<5;i++){
		len = strlen(words[i]);
		int ispalindrome =1;
		
		for(j=0;j<len/2;j++){
			if(words[i][j] != words[i][len-j-1]){
				ispalindrome = 0;
				break;
			}
		}
		if(ispalindrome){
			printf("%s is palindrome.\n", words[i]);
		}else{
			printf("%s is not palindrome.\n", words[i]);
		}
	}
	return 0;
}
