/*
15%

<p>By replacing the 1<sup>st</sup> digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.</p>
<p>By replacing the 3<sup>rd</sup> and 4<sup>th</sup> digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.</p>
<p>Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.</p>
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

using namespace std;

int euler(long long n)
{
    // Step 1: Generate primes up to n using the Sieve of Eratosthenes
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false; // 0 and 1 are not prime

    for (long long i = 2; i <= n; ++i) 
    {
        if (sieve[i]) 
        {
            // Mark all multiples of i as non-prime
            for (long long j = i * i; j <= n; j += i) 
            {
                sieve[j] = false;
            }
        }
    }

    // Step 2: Iterate over odd primes starting from 11
    for (int i = 11; i < n; i += 2) 
    {
        if (!sieve[i]) 
        {
            continue; // Skip non-prime numbers
        }

        string num = to_string(i); // Convert the prime to a string for manipulation
        int length = num.size(); // Get the number of digits in the prime

        // Step 3: Generate all digit replacement patterns using bitmasking
        for (int mask = (1 << length) - 1; mask > 0; --mask) 
        {
            // Skip masks with fewer than 1 bit set (no replacements)
            if (__builtin_popcount(mask) < 1) 
            {
                continue;
            }

            int count = 0; // Count of primes in the current family
            int first_value = INT_MAX; // Smallest prime in the family

            // Step 4: Replace digits according to the current mask
            for (char replacement = '9'; replacement >= '0'; --replacement) 
            {
                // Skip cases where replacement leads to a leading zero
                if (replacement == '0' && (mask & 1)) 
                {
                    continue;
                }

                string candidate = num; // Copy the original number as a candidate

                // Replace digits as per the mask
                for (int j = 0; j < size(candidate); ++j) 
                {
                    if (mask & (1 << j)) 
                    {
                        candidate[j] = replacement;
                    }
                }

                int value = stoi(candidate); // Convert the candidate back to an integer

                // Check if the candidate is a prime
                if (value >= 2 && value <= n && sieve[value]) 
                {
                    first_value = value; // Track the smallest prime
                    ++count; // Increment the count of primes in this family
                }
            }

            // Step 5: Check if the family contains exactly 8 primes
            if (count == 8) 
            {
                return first_value; // Return the smallest prime in the family
            }
        }
    }

    return -1; // Return -1 if no eight-prime family is found
}

int main()
{
	cout << euler(1000000) << "\n";

	return 0;
}
