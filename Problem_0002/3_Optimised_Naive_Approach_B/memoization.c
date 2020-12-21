#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//memoization is a method used to speed up calculations by storing the
//results of time intensive or repeatedly used calculations

//in every call to calculate nth fibonacci number, we calculate n-1th and n-2th fibonacci numbers over and over
//in order to optimise, we can store the results of previous fibonacci numbers so that we do not have to calculate
//their values again

int main(){
	
	int f1,f2,sum,cur;
	f1 = 1; //first fibonacci number  (n-2 th)
	f2 = 2; //second fibonacci number (n-1 th)
	sum = 0;
	
	//find the next fibonacci number until it is greater than 4000000
	while (true){
		
		cur = f1 + f2; //nth fibonacci number = (n-1)th + (n-2)th fibonacci number
		
		if (f2 > 4E6) break;
		
		//if (n-1)th fibonacci number is divisible by 2(even), add (n-1)th fibonacci number to sum
		if (!(f2%2)) sum += f2;
		
		f1 = f2;  //set (n-2)th fibonacci number to (n-1)th
		f2 = cur; //set (n-1)th fibonacci number to nth
		
	}
	
	printf("%d\n",sum);
	
	return 0;
	
}
