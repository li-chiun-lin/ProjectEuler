/*
10%

<p>Euler's totient function, $\phi(n)$ [sometimes called the phi function], is defined as the number of positive integers not exceeding $n$ which are relatively prime to $n$. For example, as $1$, $2$, $4$, $5$, $7$, and $8$, are all less than or equal to nine and relatively prime to nine, $\phi(9)=6$.</p>
<div class="center">
<table class="grid center"><tr><td><b>$n$</b></td>
<td><b>Relatively Prime</b></td>
<td><b>$\phi(n)$</b></td>
<td><b>$n/\phi(n)$</b></td>
</tr><tr><td>2</td>
<td>1</td>
<td>1</td>
<td>2</td>
</tr><tr><td>3</td>
<td>1,2</td>
<td>2</td>
<td>1.5</td>
</tr><tr><td>4</td>
<td>1,3</td>
<td>2</td>
<td>2</td>
</tr><tr><td>5</td>
<td>1,2,3,4</td>
<td>4</td>
<td>1.25</td>
</tr><tr><td>6</td>
<td>1,5</td>
<td>2</td>
<td>3</td>
</tr><tr><td>7</td>
<td>1,2,3,4,5,6</td>
<td>6</td>
<td>1.1666...</td>
</tr><tr><td>8</td>
<td>1,3,5,7</td>
<td>4</td>
<td>2</td>
</tr><tr><td>9</td>
<td>1,2,4,5,7,8</td>
<td>6</td>
<td>1.5</td>
</tr><tr><td>10</td>
<td>1,3,7,9</td>
<td>4</td>
<td>2.5</td>
</tr></table></div>
<p>It can be seen that $n = 6$ produces a maximum $n/\phi(n)$ for $n\leq 10$.</p>
<p>Find the value of $n\leq 1\,000\,000$ for which $n/\phi(n)$ is a maximum.</p>
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

void print(vector<int>& v)
{
	for (auto x : v)
		cout << x << " ";
	cout << "\n";
}

int euler(int n)
{
	vector<int> prime;
	vector<bool> sieve(n + 1, true);
	int mi = 0;
	double mv = 0;

	for (long long i = 2; i <= n; ++i)
		if (sieve[i])
		{
			prime.push_back(i);

			for (long long j = i * i; j <= n; j += i)
				sieve[j] = false;
		}

	//print(prime);

	for (int i = 2; i <= n; ++i)
	{
		double v = 1;

		int ii = i;
		for (auto p : prime)
		{
			if (p > ii || ii == 0)
				break;

			if (ii % p == 0)
			{
				v = v * p / (p - 1);

				while (ii % p == 0)
					ii /= p;
			}
		}

		//cout << i << " " << v << "\n";

		if (mv < v)
		{
			mv = v;
			mi = i;
		}
	}

	return mi;
}

int main()
{
	cout << euler(1e6) << endl;

	return 0;
}
