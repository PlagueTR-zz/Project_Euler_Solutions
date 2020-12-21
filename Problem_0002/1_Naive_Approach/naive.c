#include <stdio.h>
#include <stdbool.h>

//The naive approach is simply calculating fibonacci numbers
//until the calculated number is greater than 4000000 and
//add the even ones to sum 
//Note: if n is divisible by 2, n is even    'n%2==0' or '!(n%2)'
//		if least significant bit of n is 0, n is even    '!(n&1)'

//function to calculate nth fibonacci number
int fib(n){
	if (n == 1) return 1; //1st fibonacci number is 1
	if (n == 2) return 2; //2nd fibonacci number is 2
	//nth fibonacci number is (n-1)th fibonacci number + (n-2)th fibonacci number
	return fib(n-1) + fib(n-2);
}

int main(){
	
	//i   is used to calculate ith fibonacci number
	//cur is used to store the ith fibonacci number
	int i,sum,cur;
	i = 1; 	 //starting from 1st fibonacci number
	sum = 0;
	
	bool condition = true;
	
	while (condition){
		
		cur = fib(i++); //calculate ith fibonacci number and store it to cur, increment i by 1
		if (cur > 4E6) condition = false; //if cur is > 4000000 stop
		else if (!(cur%2)) sum += cur;    //if cur is divisible by 2, it's even, add cur to sum
		
	}
	
	printf("%d\n", sum);
	
	return 0;
	
}
