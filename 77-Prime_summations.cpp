/*
10%

<p>It is possible to write ten as the sum of primes in exactly five different ways:</p>
\begin{align}
&amp;7 + 3\\
&amp;5 + 5\\
&amp;5 + 3 + 2\\
&amp;3 + 3 + 2 + 2\\
&amp;2 + 2 + 2 + 2 + 2
\end{align}
<p>What is the first value which can be written as the sum of primes in over five thousand different ways?</p>
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

int euler()
{
	int n = 1000;
	vector<int> prime;
	vector<int> dp(n);

	dp[0] = 1;

	for (int i = 2; i < n; ++i)
	{
		bool isPrime = true;

		for (int p : prime)
			if (i % p == 0)
			{
				isPrime = false;
				break;
			}

		if (! isPrime)
			continue;

		prime.push_back(i);

		for (int j = 0; j + i < n; ++j)
			dp[j + i] += dp[j];
	}

	for (int i = 0; i < n; ++i)
		if (dp[i] > 5000)
			return i;

	return -1;
}

int main()
{
	cout << euler() << "\n";

	return 0;
}
