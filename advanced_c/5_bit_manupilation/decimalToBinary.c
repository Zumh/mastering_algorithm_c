// Binary Numbers
// a binary number is a number that includes only ones and zeroes
// number could be any length
// 0b00000000
// 0b10000000
// 0b10101010
// computer understand binary number easier

#include <stdio.h>
#include <math.h>
/*
 * The code converts a binary number to its decimal equivalent. It does this by iterating through the binary digits (from right to left) and adding the appropriate power of 2 to the decimal number for each digit.
 */
int convertBinaryToDecimal(long long n);
int main(void){

	long long n;
	int result = 0;

	printf("Enter a binary number: ");
	scanf("%lld", &n);
	
	result = convertBinaryToDecimal(n);	

	printf("%lld in binary = %d in decimal\n", n, result);

	return 0;
}


int convertBinaryToDecimal(long long n){
	int decimalNumber = 0, i = 0, remainder = 0;

	while(n != 0){
		remainder = n % 10;
		n /= 10;
		decimalNumber += remainder * pow(2, i);
		// tally
		i++;
	}
	return decimalNumber;
}
