/*
5%

<p>The series, $1^1 + 2^2 + 3^3 + \cdots + 10^{10} = 10405071317$.</p>
<p>Find the last ten digits of the series, $1^1 + 2^2 + 3^3 + \cdots + 1000^{1000}$.</p>
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <queue>

using namespace std;

const unsigned long long m = 1e10;

unsigned long long mul(unsigned long long a, unsigned long long b)
{
	unsigned long long ret = 0;

	while (b)
	{
		if (b & 1)
			ret = (ret + a) % m;

		a = (a + a) % m;
		b >>= 1;
	}

	return ret;
}

unsigned long long power(unsigned long long a, unsigned long long b)
{
	unsigned long long ret = 1;

	while (b)
	{
		if (b & 1)
			ret = mul(ret, a) % m;

		a = mul(a, a) % m;
		b >>= 1;
	}

	return ret;
}

unsigned long long euler(int n)
{
	unsigned long long sum = 0;

	for (long long i = 1; i <= n; ++i)
		sum = (sum + power(i, i)) % m;

	return sum;
}

int main()
{
	cout << 1e2 << endl;
	cout << euler(10) << endl;
	cout << euler(100) << endl;
	cout << euler(1000) << endl;

	return 0;
}
