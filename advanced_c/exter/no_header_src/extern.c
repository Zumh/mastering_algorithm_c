// extern is how we access global variable that define in other .c file
extern int number;

extern void displayFunction(void){
    printf("The global variable is %d\n", ++number);
}