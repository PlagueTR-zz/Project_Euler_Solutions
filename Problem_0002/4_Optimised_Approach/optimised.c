#include <stdio.h>

//memoization is a method used to speed up calculations by storing the
//results of time intensive or repeatedly used calculations

//in every call to calculate nth fibonacci number, we calculate n-1th and n-2th fibonacci numbers over and over
//in order to optimise, we can store the results of previous fibonacci numbers so that we do not have to calculate
//their values again

//Odd + Odd = Even
//Even + Even = Even
//Odd + Even = Odd
//Even + Odd = Odd

//Since nth fibonacci number = (n-1)th fibonacci number + (n-2)th fibonacci number, and
//the first fibonacci number = 1, the second fibonacci number = 2, we get the following pattern:
//Odd + Even = Odd
//Even + Odd = Odd
//Odd + Odd = Even
//    . . .

//We don't need to calculate every fibonacci number, we can calculate every even fibonacci number
//let's give arbitrary values(a and b) to (n-1)th and (n-2)th fibonacci numbers:
//a + b = a+b
//b + a+b = a+2b
//a+b + a+2b = 2a+3b
//     . . .
// so if (n-2)th fibonacci number is a(odd) AND (n-1)th fibonacci number is b(even)
// then (n+1)th fibonacci number is a+2b(odd) AND (n+2)th fibonacci number is 2a+3b(even)

int main(){
	
	int f1,f2,sum,temp;
	
	f1 = 1; //first fibonacci number  (n-2)th (odd)
	f2 = 2; //second fibonacci number (n-1)th (even)
	sum = 0;
	
	//while (n-1)th fibonacci number is less than 4000000
	do{
		sum += f2; //add (n-1)th fibonacci number (even)
		
		temp = f1+f2*2;  //(n+1)th fibonaci number
		f2 = temp+f2+f1; //set (n-1)th fibonacci number to (n+2)th fibonacci number
		f1 = temp;       //set (n-2)th fibonacci number to (n+1)th fibonacci number
	}while (f2 < 4E6);
	
	printf("%d\n",sum);
	
	return 0;
	
}
