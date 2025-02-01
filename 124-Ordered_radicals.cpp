/*
25%

<p>The radical of $n$, $\operatorname{rad}(n)$, is the product of the distinct prime factors of $n$. For example, $504 = 2^3 \times 3^2 \times 7$, so $\operatorname{rad}(504) = 2 \times 3 \times 7 = 42$.</p>
<p>If we calculate $\operatorname{rad}(n)$ for $1 \le n \le 10$, then sort them on $\operatorname{rad}(n)$, and sorting on $n$ if the radical values are equal, we get:</p>
<table class="center">
<tr>
   <th colspan="2">Unsorted</th>
   <td class="w25"> </td>
   <th colspan="3">Sorted</th>
</tr>
<tr>
   <th class="w50"><i>n</i></th>
   <th class="w50">rad(<i>n</i>)</th>
   <td> </td>
   <th class="w50"><i>n</i></th>
   <th class="w50">rad(<i>n</i>)</th>
   <th class="w50">k</th>
</tr>
<tr>
   <td>1</td><td>1</td>
   <td> </td>
   <td>1</td><td>1</td><td>1</td>
</tr>
<tr>
   <td>2</td><td>2</td>
   <td> </td>
   <td>2</td><td>2</td><td>2</td>
</tr>
<tr>
   <td>3</td><td>3</td>
   <td> </td>
   <td>4</td><td>2</td><td>3</td>
</tr>
<tr>
   <td>4</td><td>2</td>
   <td> </td>
   <td>8</td><td>2</td><td>4</td>
</tr>
<tr>
   <td>5</td><td>5</td>
   <td> </td>
   <td>3</td><td>3</td><td>5</td>
</tr>
<tr>
   <td>6</td><td>6</td>
   <td> </td>
   <td>9</td><td>3</td><td>6</td>
</tr>
<tr>
   <td>7</td><td>7</td>
   <td> </td>
   <td>5</td><td>5</td><td>7</td>
</tr>
<tr>
   <td>8</td><td>2</td>
   <td> </td>
   <td>6</td><td>6</td><td>8</td>
</tr>
<tr>
   <td>9</td><td>3</td>
   <td> </td>
   <td>7</td><td>7</td><td>9</td>
</tr>
<tr>
   <td>10</td><td>10</td>
   <td> </td>
   <td>10</td><td>10</td><td>10</td>
</tr>
</table>
<p>Let $E(k)$ be the $k$-th element in the sorted $n$ column; for example, $E(4) = 8$ and $E(6) = 9$.</p>
<p>If $\operatorname{rad}(n)$ is sorted for $1 \le n \le 100000$, find $E(10000)$.</p>
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

long long rad(vector<int>& prime, int n)
{
	long long r = 1;

	for (auto p : prime)
	{
		if (n < p)
			break;

		if (n % p)
			continue;

		r *= p;

		while (n % p == 0)
			n /= p;
	}

	return r;
}

int euler()
{
	int m = 1e6;
	vector<bool> sieve(m, true);
	vector<int> prime;

	for (long long i = 2; i < m; ++i)
		if (sieve[i])
		{
			prime.push_back(i);

			for (long long j = i * i; j < m; j += i)
				sieve[j] = false;
		}

	vector<pair<long long, int>> vec;

	for (int i = 1; i <= 1e5; ++i)
		vec.push_back({rad(prime, i), i});

	sort(begin(vec), end(vec));

	return vec[9999].second;
}

int main()
{
	cout << euler() << "\n";

	return 0;
}
