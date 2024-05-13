#include <stdio.h>

int main(void){
    size_t size = 0;
    int total = 0;

    printf("Enter the number of eelements you want to store:");
    scanf("%zd", &size);

    int values[size];

    for(int i = 0; i < size; i++){
        scanf("%d", &values[i]);

        total += values[i];
    }

    printf("The total is %d\n", total);

    return 0;
}