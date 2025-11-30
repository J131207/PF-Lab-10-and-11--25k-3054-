#include<stdio.h>
int linearsearch(int arr[], int size, int target, int index){
	if(index == size){
		return -1;
	}
	
	if(arr[index] == target){
		return index;
	}
	
	return linearsearch(arr, size, target, index+1);
}

int main(){
	int arr[100]; 
	int i, n, target;
	
	printf("Enter size of array: ");
	scanf("%d", &n);
	
	printf("Enter elements of the array: ");
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	printf("Enter target element to search: ");
	scanf("%d", &target);
	
	int result = linearsearch(arr, n, target, 0);
	
	if(result == -1){
		printf("\nTarget element not found.");
	}else{
		printf("\nTarget element found at index %d.", result);
	}
	
	return 0;
}
