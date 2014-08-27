/*The prime factors of 13195 are 5, 7, 13 and 29.
 *What is the largest prime factor of the number 600851475143 ?
 */
 
/*
 *Technically is able to return each prime factor, not just the largest.
 *Checks that the returned prime factors indeed make up the number again.
 *Decided to build a list of primes rather than check them for each number...
 */

#include <iostream>
#include <vector>
#include <cmath>

void findFactors(std::vector<int>& primeFactors, std::vector<bool>& primes, long long int nr);

int main() {
    long long int nr = 600851475143;
    const int NUMBER_OF_PRIMES = 100000;

    //Create a list of integers up to 100.
    //bool flag is true when it has been seen
    std::vector<bool> primes;
    for(int i = 0; i != NUMBER_OF_PRIMES; ++i) {
    primes.push_back(true);
    }

    //Use Sieve of Eratosthenes
    for(int i = 2; i < sqrt(primes.size()); ++i) {
        if (primes[i] == true) {
            for(int j = i*i; j <= primes.size(); j += i) {
                primes[j] = false;
            }
        }
    }
    
    //Find the factors of a number.
    std::vector<int> primeFactors;
    findFactors(primeFactors, primes, nr);
    
    //Check the factors to make sure number of primes calculated wasn't too small!
    long long int sum = 1;
    for(int i : primeFactors) {
        sum *= i;
    }
    
    if (sum == nr) {
        std::cout << "All is correct. Largest prine is ";
        int largestPrime = 0;
        for (int i : primeFactors) {
            if (i > largestPrime) {
                largestPrime = i;
            }
        }
        std::cout << largestPrime << '\n';
    }
    else {
        std::cout << sum;
        std::cout << "Factors do not make up the nr...\n";
    }
}

void findFactors(std::vector<int>& primeFactors, std::vector<bool>& primes, long long int nr) {
    //Divide first by the first prime. If the division does not produce a remainder of 0,
    //the next prime is tried.
    //If the remainder is 0, then take the result and check if the number isn't a prime.
    //Divide by prime again until number is a prime.
    
    //If passed number is 1, means that the last factor divided only by itself.
    //This means we have found all the factors. Hence exit the function.
    if (nr == 1) {
        return;
    }
    
    //Check number which factors it can be broken down into
    for(long long int i = 2; i != primes.size(); ++i) {
        if (primes[i] == true && nr % i == 0) {
            primeFactors.push_back(i);
            nr /= i;
            findFactors(primeFactors, primes, nr);
            return;
        }
    }
}
