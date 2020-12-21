#include <stdio.h>

//The solution to this problem is a very simple one

// If a number is not divisible by k, it also is not divisible by any multiple of k
// Thus, if we divide a number by k until it is no longer divisible by k, it also is not divisible by m*k, m>=1 AND m is an integer

// By definition, a prime number(p) is only divisible by 1 and itself(p)
// Since m*p is divisible by m, m*p is not a prime number, where m>=2 AND m is an integer

// If we let k be the first prime number(2), and divide the number until it is no longer divisible by k(2),
// then it is also not divisible by any multiple of k(2) (which are not prime numbers)
// by this point, if the number is equal to k, we have found the largest prime factor of our number
//				  if number is not equal to k, we can simply increment k by 1 and repeat

int main(){
	
	//since 600851475143 is too large to fit in an int, using an unsigned long to store it
	unsigned long long int n = 600851475143UL; 
	unsigned long long int i = 2UL; //first prime number
	
	//as long as i != n (meaning n/i == 1)
	while (n != i){
		if ( !(n%i) ) n /= i; //if n is divisible by i, divide n by i
		else i++;			  //if n is not divisible by i, increment i by 1
	}
	
	printf("%lu\n",i);
	
	return 0;
	
}
