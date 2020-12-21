#include <stdio.h>

//We are looking for the largest palindromic number
// that is the product of two, three digit numbers n and m

//The largest three digit number is 999
//since 999 * 999 < 1000 * 1000 (1M),
// the result of n * m is at most six digits in length

//A palindromic number that is six digits in length can be expressed as:
//p = [a][b][c][c][b][a] where a!=0, which can be broken down into:
//p = 100001a + 10010b + 1100c

//Using this information, we can generate all the six digit palindromic numbers
// (from largest to smallest: 999999 -> 998899 -> ... -> 101101 -> 100001)
// and check whether the palindromic number p, is divisible by any three digit number n
// we must also check whether p/n is < 1000, since 999999/999 = 1001 (result is not a three digit number)

int main(){
	
	int a, b, c;
	int palindrome; // palindrome = 100001*a + 10010*b + 1100*c ([a][b][c][c][b][a])
	int div;        // try dividing palindrome by 999 .. 100
	
	for (a = 9 ; a > 0 ; a--){
		for (b = 9; b > -1 ; b--){
			for (c = 9; c > -1; c--){
				
				palindrome = 100001*a + 10010*b + 1100*c;
				
				for (div = 999; div > 99 ; div--){ //starting from div = 999 to 99 
				
					//if palindrome is divisible by div AND palindrome/div < 1000, we have found the answer
					if (!(palindrome%div) && (palindrome/div < 1000)) break;
					
				}
				
				if (div != 99) break; //-
			}						  // |  if we broke out of previous loop before div = 99 
			if (div != 99) break;	  // |- then palindrome is divisible by div AND palindrome/div is < 1000
		}							  // |  Thus, we have found the answer, break
		if (div != 99) break;		  //-
	}
	
	printf("%d\n", palindrome);
	
	return 0;
	
}
