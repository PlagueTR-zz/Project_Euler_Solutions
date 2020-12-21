#include <stdio.h>

//The naive approach to this problem would be:
//looping through the number 1 to 1000,
//adding multiples of 3 or 5 to our sum

//This approach can be optimised

//We do not need to loop through every number,
//we can loop by multiples of k

int main(){
	
	int i, n = 1000;
	int sum = 0;
	
	//loop i from 3 to 1000, incrementing i by 3
	for (i = 3 ; i < n ; i += 3){
		sum += i; //add i to sum
	}
	
	//loop i from 5 to 1000, incrementing i by 5
	for (i = 5 ; i < n ; i += 5){
		sum += i; //add i to sum
	}
	
	//So far we have added:
	
	//multiples of 3 from 1 to 1000 to sum
		//3 + 6 + 9 + 12 + *15* + 18 ...
	//multiples of 5 from 1 to 1000 to sum
		//5 + 10 + *15* + 20 + 25 + 30 ...
	
	//we have added multiples of (3*5) to sum twice
	//remove multiples of (3*5) from sum once
	
	//loop i from (3*5) to 1000, incrementing i by (3*5)
	for (i = 3*5 ; i < n ; i += 3*5){
		sum -= i; //subtract i from sum
	}
	
	printf("%d\n", sum);
		
	return 0;
}
