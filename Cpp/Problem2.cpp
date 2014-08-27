/*
 *Each new term in the Fibonacci sequence is generated by adding the previous two terms.
 *By starting with 1 and 2, the first 10 terms will be:
 *
 *1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 *By considering the terms in the Fibonacci sequence whose values do not exceed four million,
 *find the sum of the even -valued terms.
 */

//Created on 26/08/14


#include <iostream>

void fib(int nc, int np, int& sum);

int main() {
	int result = 0;
	fib(1,1, result);
	std::cout << result;
}

void fib(int nc, int np, int& sum) {
	if (nc < 4000000) {
		if ((nc % 2) == 0) { sum += nc; }
		fib((nc + np), nc, sum);
	}
}
