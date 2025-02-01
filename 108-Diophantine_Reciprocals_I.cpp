/*
30%

<p>In the following equation $x$, $y$, and $n$ are positive integers.</p>
$$\dfrac{1}{x} + \dfrac{1}{y} = \dfrac{1}{n}$$
<p>For $n = 4$ there are exactly three distinct solutions:</p>
$$\begin{align}
\dfrac{1}{5} + \dfrac{1}{20} &amp;= \dfrac{1}{4}\\
\dfrac{1}{6} + \dfrac{1}{12} &amp;= \dfrac{1}{4}\\
\dfrac{1}{8} + \dfrac{1}{8} &amp;= \dfrac{1}{4}
\end{align}
$$

<p>What is the least value of $n$ for which the number of distinct solutions exceeds one-thousand?</p>
<p class="note">NOTE: This problem is an easier version of <a href="problem=110">Problem 110</a>; it is strongly advised that you solve this one first.</p>
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

int countDivisorsOfSquare(int x)
{
    map<int, int> factors; // Stores prime factorization of x

    // Factorize x using trial division
    for (int i = 2; i * i <= x; ++i)
    {
        while (x % i == 0)
        {
            ++factors[i]; // Increment exponent for prime factor i
            x /= i;
        }
    }

    if (x > 1) // If x is still greater than 1, it's a prime factor
        ++factors[x];

    int divisorCount = 1;

    // Compute d(x²) = ∏ (2e + 1) for each prime factor e
    for (auto& [prime, exp] : factors)
    {
        divisorCount *= (2 * exp + 1);
    }

    return divisorCount;
}

int euler()
{
	for (int x = 1;; ++x) // Incrementally test x until condition is met
    {
        if ((countDivisorsOfSquare(x) + 1) / 2 > 1000) // Solution formula
            return x;
    }
	
    return 0; // Unreachable, but included for completeness
}

int main()
{
	cout << euler() << "\n";

	return 0;
}
