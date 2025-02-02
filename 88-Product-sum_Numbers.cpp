/*
40%

<p>A natural number, $N$, that can be written as the sum and product of a given set of at least two natural numbers, $\{a_1, a_2, \dots, a_k\}$ is called a product-sum number: $N = a_1 + a_2 + \cdots + a_k = a_1 \times a_2 \times \cdots \times a_k$.</p>
<p>For example, $6 = 1 + 2 + 3 = 1 \times 2 \times 3$.</p>
<p>For a given set of size, $k$, we shall call the smallest $N$ with this property a minimal product-sum number. The minimal product-sum numbers for sets of size, $k = 2, 3, 4, 5$, and $6$ are as follows.</p>
<ul style="list-style-type:none;">
<li>$k=2$: $4 = 2 \times 2 = 2 + 2$</li>
<li>$k=3$: $6 = 1 \times 2 \times 3 = 1 + 2 + 3$</li>
<li>$k=4$: $8 = 1 \times 1 \times 2 \times 4 = 1 + 1 + 2 + 4$</li>
<li>$k=5$: $8 = 1 \times 1 \times 2 \times 2 \times 2 = 1 + 1 + 2 + 2 + 2$</li><li>$k=6$: $12 = 1 \times 1 \times 1 \times 1 \times 2 \times 6 = 1 + 1 + 1 + 1 + 2 + 6$</li></ul>
<p>Hence for $2 \le k \le 6$, the sum of all the minimal product-sum numbers is $4+6+8+12 = 30$; note that $8$ is only counted once in the sum.</p>
<p>In fact, as the complete set of minimal product-sum numbers for $2 \le k \le 12$ is $\{4, 6, 8, 12, 15, 16\}$, the sum is $61$.</p>
<p>What is the sum of all the minimal product-sum numbers for $2 \le k \le 12000$?</p>
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

// Recursive function to find minimal product-sum numbers
void dfs(int product, int sum, int count, int start, int limit, vector<int>& minimal) 
{
    int k = product - sum + count;

    if (k < limit) 
    {
        if (product < minimal[k]) 
        {
            minimal[k] = product;
        }

        for (int i = start; product * i < 2 * limit; ++i) 
        {
            dfs(product * i, sum + i, count + 1, i, limit, minimal);
        }
    }
}

int euler(int N)
{
	vector<int> minimal(N + 1, INT_MAX);

    // Start the recursive search
    dfs(1, 0, 0, 2, N + 1, minimal);

    // Eliminate duplicates and compute the sum
    set<int> uniqueNumbers;

    for (int k = 2; k <= N; ++k) 
        uniqueNumbers.insert(minimal[k]);

    // Compute the sum of all unique minimal product-sum numbers
    return accumulate(uniqueNumbers.begin(), uniqueNumbers.end(), 0);
}

int main()
{
	cout << euler(12000) << "\n";

	return 0;
}
