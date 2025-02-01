/*
20%

<p>Consider the fraction, $\dfrac n d$, where $n$ and $d$ are positive integers. If $n \lt d$ and $\operatorname{HCF}(n,d)=1$, it is called a reduced proper fraction.</p>
<p>If we list the set of reduced proper fractions for $d \le 8$ in ascending order of size, we get:
$$\frac 1 8, \frac 1 7, \frac 1 6, \frac 1 5, \frac 1 4, \frac 2 7, \frac 1 3, \frac 3 8, \frac 2 5, \frac 3 7, \frac 1 2, \frac 4 7, \frac 3 5, \frac 5 8, \frac 2 3, \frac 5 7, \frac 3 4, \frac 4 5, \frac 5 6, \frac 6 7, \frac 7 8$$</p>
<p>It can be seen that there are $21$ elements in this set.</p>
<p>How many elements would be contained in the set of reduced proper fractions for $d \le 1\,000\,000$?</p>
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
#include <stack>
#include <string>
#include <vector>

using namespace std;

long long euler(int n)
{
	long long cnt = 0;
	vector<int> prime;
	vector<bool> sieve(n + 1, true);

	for (long long i = 2; i <= n; ++i)
		if (sieve[i])
		{
			prime.push_back(i);

			for (long long j = i * i; j <= n; j += i)
				sieve[j] = false;
		}

	for (long long de = 2; de <= n; ++de)
	{
		long long phi = 1;

		int ii = de;
		for (auto p : prime)
		{
			if (p > ii || ii == 0)
				break;

			int k = 0;

			while (ii % p == 0)
			{
				ii /= p;
				++ k;
			}

			if (k)
				phi *= pow(p, k - 1) * (p - 1);
		}

		//cout << de << " " << phi << "\n";

		cnt += phi;
	}

	return cnt;
}

int main()
{
	cout << euler(8) << endl;
	cout << euler(1e4) << endl;
	cout << euler(1e5) << endl;
	cout << euler(1e6) << endl;

	return 0;
}
