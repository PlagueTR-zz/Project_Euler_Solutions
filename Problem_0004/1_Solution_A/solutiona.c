#include <stdio.h>

//A palindromic number reads the same both ways
//We can check whether a number is palindromic by checking whether the reverse of that number is equivalent to itself
//There are many ways to reverse a number, the method I chose to go with is:
// set reverse to 0
// while number is greater than 0:
//  multiply the reverse by 10
//  add the least significant digit of the number to reverse
//  divide number by 10 (integer division)

//For example, calculating the reverse of 319:
// reverse = 0, num = 319
// reverse = 0*10 + 319%10 = 9  , num = 31
// reverse = 9*10 +  31%10 = 91 , num = 3
// reverse = 91*10 +  3%10 = 913, num = 0
//  reverse of 319 is 913

//We want to get the largest palindromic number that is a multiple of two three digit
//so, one method would be starting a and b from the largest three digit number (999)
//and checking whether a*b is a palindromic number, storing the largest palindromic number ***
//we can decrement b by 1 until it is no longer a three digit number (until b<=99)
//once b is no longer a three digit number, we can decrement a by 1 and set b to a, repeating the cycle

//The reason we need to store the largest palindromic number, and not stop the loop is simple
// because if we were to break out of loop upon finding the first palindromic number that is multiple of a*b
// would be 995 * 583 = 580085, which is not the largest palindromic number
// since    962 * 924 = 888888 is also a palindromic number, and a greater one!
//However, we can stop our loop once a^2 (a*a) is less than or equal to the largest palindromic number we have found so far
// since any combination of a*b from that point will be less than the largest palindromic number

//find reverse of n, if reverse of n == n, n is palindromic, if not, n is not palindromic
int isPalindrome(int n){
	int copyn = n;
	int reverse = 0;
	while (copyn){
		reverse = reverse*10 + copyn%10;
		copyn /= 10;
	}
	return reverse == n;
}

int main(){
	
	int num1, num2;
	int max = 0; //set max to 0
	
	for (num1 = 999; num1 > 99 ; num1--){ //start num1 from 999, decrementing num1 by 1 until 99
	
		//every combination of num1 * num2 <= max, so if max >= num1 * num1, exit out of loop
		if (num1 * num1 <= max);
		
		for (num2 = num1; num2 > 99 ; num2--){ //start num2 from 999, decrementing num2 by 1 until 99
		
			//if num1 * num2 is palindromic AND num1 * num2 is greater than max
			if (isPalindrome(num1*num2) && num1*num2 > max) max = num1*num2; //set max to num1 * num2
			
		}
		
	}
	
	printf("%d\n", max);
	
	return 0;
	
}
