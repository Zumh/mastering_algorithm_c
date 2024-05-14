/*
 The volatile type qualifier tells the compiler explicitly that the specified variable will change its value

 it is provided so that a program can tell the compiler to suppress various kinds of optimizations

 prevents the compiler from optimizing away seemingly redundant assignments to a variable

 prevents the compiler from repeated examination of a vriable without its value seemingly chaning

 essentially, prevents the compiler from "caching" variables

 the reason for having this type qualifier is mainly because of the problems that are encountered in real-time or embedded systems programming

 programs that have a lot of threading
 programs where resources are scarce
 */

/*
When to use VOLATILE
   a vriable should be declared volatile whenever its value could cahnge unexpectedly

 the optimizer must be careful to reload the variable every time it is used instead of holding a copy in a register

 only three types of variables should use volatile

 - memory-mapped peripheral registers
 - global variables (non stack variables) modified by an interrupt service routine

 - global variables accessed by multiple tasks within a multi-threaded application
 */

volatile int loc1 ; // loc1 is a volatile variable
volatile int * plocl; // plocl is a volatile pointer	

loc1 = 5; // loc1 is a volatile variable
plocl = &loc1; // plocl is a volatile pointer
	       val 1 = x; 
	       // some code not using x
	       val2 = x;

	       // we don't want x to be cache it while doing something else
	       // we don't want to load x into register
	      
// we don't want compiler to optimize a process 
const volatile int * ploc;
// value can be both const and volatile
// harware clock setting normally should not be changed by the program
// - make it const
// however it can be changed by an agency other than the program
// - make it volatile
// use both qualifiers in the declaration (order does not matter)
