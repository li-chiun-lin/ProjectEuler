/*
5%

<p>A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.</p>
<p>For example,
\begin{align}
&amp;44 \to 32 \to 13 \to 10 \to \mathbf 1 \to \mathbf 1\\
&amp;85 \to \mathbf{89} \to 145 \to 42 \to 20 \to 4 \to 16 \to 37 \to 58 \to \mathbf{89}
\end{align}
</p><p>Therefore any chain that arrives at $1$ or $89$ will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at $1$ or $89$.</p>
<p>How many starting numbers below ten million will arrive at $89$?</p>
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

int square_digit(int x)
{
	int sum = 0;

	while (x)
	{
		int d = x % 10;
		sum += d * d;
		x /= 10;
	}

	return sum;
}

int euler(int n)
{
	set<int> one, eighty_nine;

	one.insert(1);
	eighty_nine.insert(89);

	for (int i = 2; i < n; ++i)
	{
		int sd = i;

		while (sd = square_digit(sd))
		{
			if (one.count(sd))
			{
				one.insert(i);
				break;
			}
			else if (eighty_nine.count(sd))
			{
				eighty_nine.insert(i);
				break;
			}
		}
	}

	return eighty_nine.size();
}

int main()
{
	cout << euler(100) << "\n";
	cout << euler(1e7) << "\n";

	return 0;
}
