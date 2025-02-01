/*
5%

<p>A unit fraction contains $1$ in the numerator. The decimal representation of the unit fractions with denominators $2$ to $10$ are given:</p>
\begin{align}
1/2 &amp;= 0.5\\
1/3 &amp;=0.(3)\\
1/4 &amp;=0.25\\
1/5 &amp;= 0.2\\
1/6 &amp;= 0.1(6)\\
1/7 &amp;= 0.(142857)\\
1/8 &amp;= 0.125\\
1/9 &amp;= 0.(1)\\
1/10 &amp;= 0.1
\end{align}
<p>Where $0.1(6)$ means $0.166666\cdots$, and has a $1$-digit recurring cycle. It can be seen that $1/7$ has a $6$-digit recurring cycle.</p>
<p>Find the value of $d \lt 1000$ for which $1/d$ contains the longest recurring cycle in its decimal fraction part.</p>
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

int recurring(int x)
{
	vector<int> hit(x);
	int c = 1;
	int r = 1;
	int a = 1;

	while (r)
	{
		r = a % x;

		if (hit[r])
			break;

		hit[r] = c ++;
		a = r * 10;
	}

	return r ? c - hit[r] : 0;
}

int euler(int n)
{
	int ret = 0;
	int ma = 0;

	for (int i = 2; i < n; ++i)
	{
		int r = recurring(i);
		cout << r << endl;
		
		if (ret < r)
		{
			ret = r;
			ma = i;
		}
	}

	return ma;
}

int main()
{
	cout << euler(1000) << endl;

	return 0;
}
