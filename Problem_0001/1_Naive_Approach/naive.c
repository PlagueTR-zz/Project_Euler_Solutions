#include <stdio.h>

//The naive approach is simply looping through the numbers
//1 to 1000, adding multiples of 3 or 5 to our sum

int main(){
	
	int i, n = 1000;
	
	int sum = 0;
	
	for (i = 1 ; i < n ; i++){ 			//loop i from 1 to 1000, incrementing i by 1
		if (!(i%3) || !(i%5)) sum += i;	//if i is divisible by 3 or 5, add i to sum
	}
	
	printf("%d\n", sum);
		
	return 0;
}
