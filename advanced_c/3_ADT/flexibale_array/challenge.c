#include <stdio.h>
#include <stdlib.h>
struct myArray {
    int length;
    int array[];
};

int main(void){
    size_t size = 0;
    struct myArray *tempArray;
    scanf("%zd", &size);

    tempArray = malloc(sizeof(struct myArray) + size * sizeof(int));

    tempArray->length = size;
 
    for(int i = 0; i < size; i++){
        tempArray->array[i] = i + 1;
    }

    printf("The array size is: %d\n", tempArray->length);
    for(int i = 0; i < size; i++){
        printf("%d ", tempArray->array[i]);
    }

    return 0;
}
