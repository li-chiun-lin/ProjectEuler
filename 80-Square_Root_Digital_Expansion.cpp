/*
20%

<p>It is well known that if the square root of a natural number is not an integer, then it is irrational. The decimal expansion of such square roots is infinite without any repeating pattern at all.</p>
<p>The square root of two is $1.41421356237309504880\cdots$, and the digital sum of the first one hundred decimal digits is $475$.</p>
<p>For the first one hundred natural numbers, find the total of the digital sums of the first one hundred decimal digits for all the irrational square roots.</p>
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
#include <gmpxx.h> // GMP C++ wrapper

using namespace std;

// Function to compute the digital sum of the first 100 decimal digits of the square root
int digital_sum_sqrt(int n, int precision) 
{
    // Set GMP floating-point precision
    mpf_set_default_prec(precision * 4); // Extra precision to avoid rounding errors
    mpf_class num(n), sqrt_n;

    // Compute square root
    mpf_sqrt(sqrt_n.get_mpf_t(), num.get_mpf_t());

    // Allocate a char buffer to store the string representation
    char *buffer = new char[precision + 5]; // Extra space for null terminator and "0."
    mp_exp_t exp; // Exponent for scientific notation
    mpf_get_str(buffer, &exp, 10, precision + 1, sqrt_n.get_mpf_t());

    // Compute the digital sum directly from the buffer
    int sum = 0, count = 0;
    for (int i = 0; buffer[i] != '\0'; ++i) 
    {
        if (isdigit(buffer[i])) 
        {
            sum += buffer[i] - '0';
            if (++count == 100) 
                break; // Stop after 100 digits
        }
    }

    // Clean up buffer memory
    delete[] buffer;

    return sum;
}

int euler(int N)
{
    const int PRECISION = N + 10; // More than 100 digits for safety
    int total_sum = 0;

    for (int i = 1; i <= N; ++i) 
    {
        // Skip perfect squares
        int root = static_cast<int>(sqrt(i));
        if (root * root == i) 
            continue;

        total_sum += digital_sum_sqrt(i, PRECISION);
    }

	return total_sum;
}

int main()
{
	cout << euler(100) << "\n";

	return 0;
}
