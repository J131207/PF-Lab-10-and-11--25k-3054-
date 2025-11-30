#include<stdio.h>
#include<string.h>
void reverse_string(char str[],int start,int end);
int main(){
	char str[100];
	printf("enter the string you want to reverse ");
	scanf("%s",&str);
	reverse_string(str,0,strlen(str) -1);
	printf("the reversed string is %s\n",str);
	return 0;
}
void reverse_string(char str[],int start,int end){
	if(start>=end){
		return ;
	}
	char temp=str[start];
	str[start]=str[end];
	str[end]=temp;
	reverse_string(str,(start+1),(end-1));
}
