#include <stdio.h>

//This solution is very similar to the original solution.
// Please check the comments on the original solution before reading these.

//Since the only even prime number is 2,
// we can start our loop at 3 and increment i by 2 on each iteration
// which should be slightly faster since we are not checking every even number

int main(){
	
	//since 600851475143 is too large to fit in an int, using an unsigned long to store it
	unsigned long long int n = 600851475143UL; 
	unsigned long long int i = 3UL; //first odd prime number
	
	while ( !(n%2) ) n /= 2; //divide n by 2 until it is not divisible by 2
	
	//as long as i != n (meaning n/i == 1)
	while (n != i){
		if ( !(n%i) ) n /= i; //if n is divisible by i, divide n by i
		else i += 2;		  //if n is not divisible by i, increment i by 2
	}
	
	printf("%lu\n",i);
	
	return 0;
	
}
