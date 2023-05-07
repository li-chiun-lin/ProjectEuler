/*
30%

Let p_n be the nth prime: 2, 3, 5, 7, 11, ..., and let r be the remainder when (p_n−1)^n + (p_n+1)^n is divided by p_n^2.

For example, when n = 3, p3 = 5, and 4^3 + 6^3 = 280 ≡ 5 mod 25.

The least value of n for which the remainder first exceeds 10^9 is 7037.

Find the least value of n for which the remainder first exceeds 10^10.
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

int euler()
{
	int m = 1e6;
	vector<bool> sieve(m, true);
	int n = 1;

	for (long long p = 2; p < m; ++p)
		if (sieve[p])
		{
			for (long long j = p * p; j < m; j += p)
				sieve[j] = false;

			if (n % 2 && (p * n * 2) % (p * p) > 1e10)
				return n;
			
			++ n;
		}

	return -1;
}

int main()
{
	cout << euler() << "\n";

	return 0;
}
