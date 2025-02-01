/*
5%

<p>Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
\begin{align}
1634 &amp;= 1^4 + 6^4 + 3^4 + 4^4\\
8208 &amp;= 8^4 + 2^4 + 0^4 + 8^4\\
9474 &amp;= 9^4 + 4^4 + 7^4 + 4^4
\end{align}
</p><p class="smaller">As $1 = 1^4$ is not a sum it is not included.</p>
<p>The sum of these numbers is $1634 + 8208 + 9474 = 19316$.</p>
<p>Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.</p>
*/

#include <algorithm>
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
	vector<int> p(10);

	for (int i = 0; i < 10; ++i)
		p[i] = pow(i, n);


	int sum = 0;

	for (long long i = 2; i < 10000000; ++i)
	{
		long long ds = 0;
		long long ii = i;

		while (ii)
		{
			ds += p[ii % 10];
			ii /= 10;
		}

		if (ds == i)
			sum += i;
	}

	return sum;
}

int main()
{
	cout << euler(4) << endl;
	cout << euler(5) << endl;

	return 0;
}
