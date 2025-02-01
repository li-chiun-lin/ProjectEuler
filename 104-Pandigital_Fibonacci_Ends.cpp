/*
25%

<p>The Fibonacci sequence is defined by the recurrence relation:</p>
<blockquote>$F_n = F_{n - 1} + F_{n - 2}$, where $F_1 = 1$ and $F_2 = 1$.</blockquote>
<p>It turns out that $F_{541}$, which contains $113$ digits, is the first Fibonacci number for which the last nine digits are $1$-$9$ pandigital (contain all the digits $1$ to $9$, but not necessarily in order). And $F_{2749}$, which contains $575$ digits, is the first Fibonacci number for which the first nine digits are $1$-$9$ pandigital.</p>
<p>Given that $F_k$ is the first Fibonacci number for which the first nine digits AND the last nine digits are $1$-$9$ pandigital, find $k$.</p>
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
//#include <gmpxx.h> // GMP C++ wrapper

using namespace std;

// Function to check if a number is 1-9 pandigital
#include <iostream>
#include <cmath>

using namespace std;

// Function to check if a number is 1-9 pandigital
bool isPandigital(long long num) {
    int mask = 0;

    while (num) {
        mask |= 1 << (num % 10); // Set the bit corresponding to the digit
        num /= 10;
    }

    return mask == 0x3FE; // Binary 0b1111111110 (digits 1-9 set, no 0)
}

// Function to find the smallest Fibonacci index where both the first 9 and last 9 digits are pandigital
int euler() {
    const long long MOD = 1e9; // To track the last 9 digits of Fibonacci numbers
    long long a = 1, b = 1, c = 0;
    int index = 2;

    // Constants for computing first 9 digits
    const double sqrt5 = sqrt(5);
    const double phi = (1 + sqrt5) / 2; // Golden Ratio
    const double logPhi = log10(phi);   // log10(Phi)
    const double logSqrt5 = log10(sqrt5); // log10(sqrt(5))

    while (true) {
        ++index;

        // Compute last 9 digits using modulo arithmetic
        c = (a + b) % MOD;
        a = b;
        b = c;

        // Compute first 9 digits using logarithm approximation
        double logFib = index * logPhi - logSqrt5; 
        double first9Digits = pow(10, logFib - floor(logFib) + 8);

        // Check if both first and last 9 digits are pandigital
        if (isPandigital(static_cast<long long>(first9Digits)) && isPandigital(b)) {
            return index;
        }
    }

    return -1; // This line will never be reached
}

int main()
{
	cout << euler() << "\n";

	return 0;
}
