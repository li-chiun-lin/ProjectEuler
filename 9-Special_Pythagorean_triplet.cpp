/*
5%

<p>A Pythagorean triplet is a set of three natural numbers, $a \lt b \lt c$, for which,
$$a^2 + b^2 = c^2.$$</p>
<p>For example, $3^2 + 4^2 = 9 + 16 = 25 = 5^2$.</p>
<p>There exists exactly one Pythagorean triplet for which $a + b + c = 1000$.<br>Find the product $abc$.</p>
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

int euler(int n)
{
	vector<int> square(n);

	for (int i = 1; i < n; ++i)
		square[i] = i * i;

	for (int a = 1; a < n; ++a)
	{
		for (int b = a + 1; b < n; ++b)
		{
			int c = n - a - b;

			if (square[a] + square[b] == square[c])
				return a * b * c;
		}
	}

	return 0;
}

int main()
{
	cout << euler(1000) << endl;

	return 0;
}
