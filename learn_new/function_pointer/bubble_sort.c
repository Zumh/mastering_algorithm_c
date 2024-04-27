// bubble sort algorithm
#include <stdio.h>
#include <stdbool.h>


#define SIZE 6

int bubble_sort(int arr[], int n, int (*compare)(int a, int b));
	
void display(int arr[], int n);

int swap(int *a, int *b);
int ascending(int a, int b);
int descending(int a, int b);
int main(void){
	// sort this array in ascending order and descending order
	int arr[SIZE] = {2,5,6,1,3,4};
	int order = 0;

	display(arr, SIZE);

	printf("\n\n");
	if (order == 0){
		bubble_sort(arr, SIZE, ascending);
	}else{
		bubble_sort(arr, SIZE, descending);
	}
	
	
	// display the sorted array 
	display(arr, SIZE);
}

void display(int arr[], int n){
	int i = 0;
	for (i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}
int swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int descending(int a, int b){
	return b > a;
}
int ascending(int a, int b){
	return a > b;
}
int bubble_sort(int arr[], int n, int (*compare)(int a, int b)){
	int i, j, temp;
	bool swapped = false;

	for (i = 0; i < n-1; i++){
		swapped = false;
		for (j = 0; j < n - i - 1; j++){
			if ((*compare)(arr[j], arr[j + 1])){
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false){
			break;
		}
	}
	return 0;

}

