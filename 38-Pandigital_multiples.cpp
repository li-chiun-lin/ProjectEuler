/*
5%

<p>Take the number $192$ and multiply it by each of $1$, $2$, and $3$:</p>
\begin{align}
192 \times 1 &amp;= 192\\
192 \times 2 &amp;= 384\\
192 \times 3 &amp;= 576
\end{align}
<p>By concatenating each product we get the $1$ to $9$ pandigital, $192384576$. We will call $192384576$ the concatenated product of $192$ and $(1,2,3)$.</p>
<p>The same can be achieved by starting with $9$ and multiplying by $1$, $2$, $3$, $4$, and $5$, giving the pandigital, $918273645$, which is the concatenated product of $9$ and $(1,2,3,4,5)$.</p>
<p>What is the largest $1$ to $9$ pandigital $9$-digit number that can be formed as the concatenated product of an integer with $(1,2, \dots, n)$ where $n \gt 1$?</p>
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

const int target = (1 << 10) - 2;

void check(int from, int to)
{
	for (int p = from; p <= to; ++p)
	{
		int bit = 0;
		bool good = true;

		for (int i = 1; bit < target && good; ++i)
		{
			long long pp = p * i;

			while (pp && good)
			{
				int b = 1 << (pp % 10);

				if (bit & b)
					good = false;
				else
					bit |= b;

				pp /= 10;
			}
		}

		if (good && bit == target)
			cout << p << " " << p * 2 << " " << p * 3 << endl;
	}
}

int euler()
{
	check(9, 10);
	check(90, 99);
	check(900, 999);
	check(9000, 9999);

	return 0;
}

int main()
{
	cout << euler() << endl;

	return 0;
}
