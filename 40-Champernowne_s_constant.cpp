/*
5%

<p>An irrational decimal fraction is created by concatenating the positive integers:
$$0.12345678910{\color{red}\mathbf 1}112131415161718192021\cdots$$</p>
<p>It can be seen that the $12$<sup>th</sup> digit of the fractional part is $1$.</p>
<p>If $d_n$ represents the $n$<sup>th</sup> digit of the fractional part, find the value of the following expression.
$$d_1 \times d_{10} \times d_{100} \times d_{1000} \times d_{10000} \times d_{100000} \times d_{1000000}$$</p>
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

int digit(vector<vector<long long>> &seg, long long n)
{
	for (auto &s : seg)
	{
		if (n > s[1])
			n -= s[1];
		else
		{
			long long val = s[0] + n / s[2];
			long long rev = 0;

			while (val)
			{
				rev *= 10;
				rev += val % 10;
				val /= 10;
			}

			long long idx = n % s[2];

			while (idx --)
				rev /= 10;

			return rev % 10;
		}
	}

	return -1;
}

int euler(int n)
{
	vector<vector<long long>> seg = {
		{0, 10, 1}, 
		{10, 90 * 2, 2}, 
		{100, 900 * 3, 3}, 
		{1000, 9000 * 4, 4}, 
		{10000, 90000 * 5, 5},
		{100000, 900000 * 6, 6}
	};

	for (int i = 10; i < 20; ++i)
		cout << digit(seg, i);
	cout << endl;

	cout << digit(seg, 1)
		* digit(seg, 10)
		* digit(seg, 100)
		* digit(seg, 1000)
		* digit(seg, 10000)
		* digit(seg, 100000)
		* digit(seg, 1000000)
		<< endl;

	return 0;
}

int main()
{
	cout << euler(0) << endl;

	return 0;
}
