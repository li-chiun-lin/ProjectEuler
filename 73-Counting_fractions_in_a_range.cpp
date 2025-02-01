/*
15%

<p>Consider the fraction, $\dfrac n d$, where $n$ and $d$ are positive integers. If $n \lt d$ and $\operatorname{HCF}(n, d)=1$, it is called a reduced proper fraction.</p>
<p>If we list the set of reduced proper fractions for $d \le 8$ in ascending order of size, we get:
$$\frac 1 8, \frac 1 7, \frac 1 6, \frac 1 5, \frac 1 4, \frac 2 7, \frac 1 3, \mathbf{\frac 3 8, \frac 2 5, \frac 3 7}, \frac 1 2, \frac 4 7, \frac 3 5, \frac 5 8, \frac 2 3, \frac 5 7, \frac 3 4, \frac 4 5, \frac 5 6, \frac 6 7, \frac 7 8$$</p>
<p>It can be seen that there are $3$ fractions between $\dfrac 1 3$ and $\dfrac 1 2$.</p>
<p>How many fractions lie between $\dfrac 1 3$ and $\dfrac 1 2$ in the sorted set of reduced proper fractions for $d \le 12\,000$?</p>
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

	for (long long de = 3; de <= n; ++de)
	{
		cout << de << " ";
		for (long long nu = de / 3 + 1; nu <= de / 2; ++ nu)
		{
			if (gcd(nu, de) != 1)
				continue;

			++ cnt;

			//cout << nu << "/" << de << " ";
		}

		//cout << "\n";
		
	}

	return cnt;
}

int main()
{
	cout << euler(8) << "\n";
	cout << euler(12000) << "\n";

	return 0;
}
