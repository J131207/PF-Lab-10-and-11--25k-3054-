#include<stdio.h>
#define constant 1000
void convertMtoKM(float M){
	float KM;
	float MtoKm;
	static int count = 1;
	MtoKm = M/constant;
	
	printf("call %d:	%.2fm when converted to km is: %.2fKm\n", count, M, MtoKm);
	
	count++;
}

int main(){
	convertMtoKM(156000);
	convertMtoKM(200);
	convertMtoKM(7005);
}
