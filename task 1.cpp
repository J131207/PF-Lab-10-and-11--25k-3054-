#include<stdio.h>
int total_sum(int n);
int main(){
	int n;
	int sum=0;
	printf("enter the number of term you want to tke sum of ");
	scanf("%d",&n);
    sum= total_sum( n );
    printf("the sum is %d",sum);
	return 0;
}
int total_sum(int n){
    int a=0,b=0;
	if(n==0){
		return 0;
	}
	a=n%10;
	b=n/10;
	return a + total_sum(b);
}
