/*A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * 
 *Find the largest palindrome made from the product of two 3-digit numbers.
 */

//Created 27/08/14

//Brute force style
#include <iostream>
#include <vector>

bool checkPalindrome(int mult) ;

int main() {
	std::vector<int> digits;
	int mult = 0;
	int currentLargest = 0;
	int a = 100, b = 100;
	bool isPalindrome = false;

	//Set b equal to a.
	//To understand, consider this small table:
	//*---*---*---*
	//| 1 | 2 | 3 |
	//*---*---*---*
	//| 2 | 4 | 6 |
	//*---*---*---*
	//| 3 | 6 | 9 |
	//*---*---*---*
	//There is already redundancy here. We only need to calculate half of the table.
	//So for each pass, increase b by 1.

	while(a != 1000) {
		b = a;
		while(b != 1000) {
			mult = a*b;
			if (checkPalindrome(mult) && mult > currentLargest) {
				currentLargest = mult;
			}
		++b;
		}
	++a;
	}
	std::cout << "Largest palindrome is " << currentLargest << '\n';
}

bool checkPalindrome(int mult) {
	std::vector<int> digits;
	int dig = 0;
	while (mult > 0) {
		dig = mult % 10;
		mult /= 10;
		digits.push_back(dig);
	}
	int i = 1, n = digits.size();
	while (digits[i-1] == digits[n-i]) {
		if( i == (digits.size()/2) ) {
			return true;
		}
		else {
			i++;
		}
	}
	return false;
}
