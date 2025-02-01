/*
5%

<p>There are exactly ten ways of selecting three from five, 12345:</p>
<p class="center">123, 124, 125, 134, 135, 145, 234, 235, 245, and 345</p>
<p>In combinatorics, we use the notation, $\displaystyle \binom 5 3 = 10$.</p>
<p>In general, $\displaystyle \binom n r = \dfrac{n!}{r!(n-r)!}$, where $r \le n$, $n! = n \times (n-1) \times ... \times 3 \times 2 \times 1$, and $0! = 1$.
</p>
<p>It is not until $n = 23$, that a value exceeds one-million: $\displaystyle \binom {23} {10} = 1144066$.</p>
<p>How many, not necessarily distinct, values of $\displaystyle \binom n r$ for $1 \le n \le 100$, are greater than one-million?</p>
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

int euler(int n) {
    // Initialize Pascal's Triangle with dimensions (n + 1) x (n + 1)
    vector<vector<unsigned long long>> pascal(n + 1, vector<unsigned long long>(n + 1, 0));

    int count = 0; // Variable to count values exceeding 1,000,000

    // Build Pascal's Triangle
    for (int i = 0; i <= n; ++i) {
        pascal[i][0] = pascal[i][i] = 1; // Boundary values in Pascal's Triangle

        for (int j = 1; j <= i; ++j) {
            // Compute the current value as the sum of two values from the previous row
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];

            // Cap the value at 1,000,001 if it exceeds 1,000,000
            if (pascal[i][j] > 1'000'000) {
                pascal[i][j] = 1'000'001;
            }

			// Count values in the current row exceeding 1,000,000
			if (pascal[i][j] > 1'000'000) {
                ++count;
            }
        }
    }

    return count; // Return the total count
}

int main()
{
	cout << euler(100) << "\n";

	return 0;
}
