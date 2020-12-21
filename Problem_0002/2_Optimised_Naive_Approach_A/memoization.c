#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//memoization is a method used to speed up calculations by storing the
//results of time intensive or repeatedly used calculations

//in every call to calculate nth fibonacci number, we calculate n-1th and n-2th fibonacci numbers over and over
//in order to optimise, we can store the results of previous fibonacci numbers so that we do not have to calculate
//their values again

//an array to store fibonacci numbers, starting with the first two fibonacci numbers (1, 2)
int fibs[0xFFFF] = { 1, 2 };

//function to calculate nth fibonacci number
int findFibs(int n){
	
	//use stored values to calculate nth fibonacci number, store nth fibonacci number
	fibs[n] = fibs[n-1] + fibs[n-2]; 
	
	//return nth fibonacci number
	return fibs[n];
	
}

int main(){
	
	int i,sum,cur;
	i = 2;
	sum = 0;
	
	bool condition = true;
	
	//find the next fibonacci number until it is greater than 4000000
	while (condition){
		cur = findFibs(i++);
		if (cur > 4E6) condition = false;
	}
	
	//starting from the first fibonacci number 
	//until the last fibonacci number whose value is less than 4000000
	for (cur=0 ; cur<i-1 ; cur++){
		
		//if current fibonacci number is divisible by 2(even), add current fibonacci number to sum
		if (!(fibs[cur]%2)) sum += fibs[cur];
		
	}
	
	printf("%d\n",sum);
	
	return 0;
	
}
