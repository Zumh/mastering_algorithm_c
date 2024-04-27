#include <stdio.h>
#define SIZE 3
void func1(int number);
void func2(int number);
void func3(int number);

int main(void){
    void (*func[SIZE])(int) = {func1, func2, func3};

    int i = 0;

    while(i < SIZE){
        func[i++](i);
    }
}

void func1(int number){
    printf("func %d\n", number);
}

void func2(int number){
    printf("func %d\n", number);
}

void func3(int number){
    printf("func %d\n", number);
}