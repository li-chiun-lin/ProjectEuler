/*
5%

<p>If $p$ is the perimeter of a right angle triangle with integral length sides, $\{a, b, c\}$, there are exactly three solutions for $p = 120$.</p>
<p>$\{20,48,52\}$, $\{24,45,51\}$, $\{30,40,50\}$</p>
<p>For which value of $p \le 1000$, is the number of solutions maximised?</p>
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

int euler(int n)
{
	vector<long long> square(n + 1);
	int ret = 0;
	int mm = 0;

	for (long long i = 0; i <= n; ++i)
		square[i] = i * i;

	for (int p = 1; p <= n; ++p)
	{
		cout << p << " : " << endl;
		int c = 0;
		for (int a = 1; a + a < p; ++a)
			for (int b = a + 1; b + b < p; ++b)
				if (square[a] + square[b] == square[p - a - b])
				{
					cout << "  " << a << " " << b << " " << p - a - b << endl;
					++ c;
				}

		if (mm < c)
		{
			mm = c;
			ret = p;
		}
	}

	return ret;
}

int main()
{
	cout << euler(120) << endl;
	cout << euler(1000) << endl;

	return 0;
}
