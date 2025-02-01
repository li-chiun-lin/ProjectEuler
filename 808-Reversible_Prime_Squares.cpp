/*
5%

<p>
Both $169$ and $961$ are the square of a prime. $169$ is the reverse of $961$.
</p>
<p>
We call a number a <dfn>reversible prime square</dfn> if:</p>
<ol>
<li>It is not a palindrome, and</li>
<li>It is the square of a prime, and</li>
<li>Its reverse is also the square of a prime.</li>
</ol>
<p>
$169$ and $961$ are not palindromes, so both are reversible prime squares.
</p>
<p>
Find the sum of the first $50$ reversible prime squares.
</p>
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
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
#include <unordered_set>
#include <vector>
//#include <gmpxx.h> // GMP C++ wrapper

using namespace std;

// Function to reverse the digits of a number x
long long inv(long long x)
{
    long long res = 0;
    // Reversing the digits of x
    while (x > 0)
    {
        res = res * 10 + x % 10;  // Add the last digit of x to res
        x /= 10;  // Remove the last digit from x
    }
    return res;
}

// Main function to compute the sum of reversible prime squares
long long euler(int N)
{
    set<long long> prime2;  // Set to store the squares of primes
    vector<bool> sieve(N + 1, true);  // Sieve of Eratosthenes for prime checking

    sieve[0] = sieve[1] = false;  // 0 and 1 are not prime

    // Applying the Sieve of Eratosthenes to find primes up to N
    for (long long i = 2; i <= N; i++)
    {
        if (sieve[i])  // If i is prime
        {
            // Insert the square of the prime number into the prime2 set
            prime2.insert((long long)i * i);

            // Mark all multiples of i as non-prime
            for (long long j = i * 2; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    long long sum = 0;  // Variable to store the sum of reversible prime squares
    int cnt = 0;  // Counter to keep track of valid numbers found

    // Iterate through all the prime squares
    for (auto x : prime2)
    {
        // Reverse the digits of x
        long long y = inv(x);

        // Check if the reversed number is different and also a prime square
        if (x != y && prime2.count(y))
        {
            // If both conditions are met, add the number to the sum
            sum += x;

            // Print progress: counter, current number, its reverse, and the sum so far
            cout << (++cnt) << " " << x << " " << y << " " << sum << "\n";
        }
    }

    return sum;  // Return the final sum
}

int main()
{
	cout << euler(1e8) << "\n";

	return 0;
}
