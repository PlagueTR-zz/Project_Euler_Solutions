#include <stdio.h>

//sum of numbers from 1 to n is given by the mathematical formula:
// sum(i=1, n) i = 1 + 2 + 3 + ... + n = n*(n+1)/2
//                '---------.--------'
//                       n terms

//sum of numbers that are multiples of k from k to n is:
// k + 2k + 3k + ... + m*k, where m*k <= n
// if we take the common multiple k:
// k*sum(i=1, n/k) k*i = k*(1 + 2 + 3 + ... + m), where m <= n/k and m is an integer
//                         '---------.--------'
//                                m terms
// m has to be an integer, thus, it is given by floor(n/k), which gives the formula:
// sum(i=k, n) k*i = k*floor(n/k)*(floor(n/k)+1)/2

int sumMultiplesK_1_N(int k, int n){
	int term = n/k; //integer division, equal to floor(n/k)
	return k*((term*(term+1))/2);
}

int main(){
	
	int n = 1000;
	
	// sum = sum of multiples of 3 from 1 to 1000 + sum of multiples of 5 from 1 to 1000
	int sum = sumMultiplesK_1_N(3, n-1)
			  +sumMultiplesK_1_N(5, n-1);
			  
	//So far we have added:
	
	//sum of multiples of 3 from 1 to 1000
		//3 + 6 + 9 + 12 + *15* + 18 ...
	//sum of multiples of 5 from 1 to 1000
		//5 + 10 + *15* + 20 + 25 + 30 ...
	
	//we have added multiples of (3*5) to sum twice
	//remove multiples of (3*5) from sum once
	
	// sum = sum - sum of multiples of (3*5) from 1 to 1000
	sum -= sumMultiplesK_1_N(3*5, n-1);
	
	printf("%d\n", sum);
		
	return 0;
	
}
