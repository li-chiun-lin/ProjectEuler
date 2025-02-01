/*
5%

<p>
We define an $S$-number to be a natural number, $n$, that is a perfect square and its square root can be obtained by splitting the decimal representation of $n$ into $2$ or more numbers then adding the numbers.
</p>
<p>
For example, $81$ is an $S$-number because $\sqrt{81} = 8+1$.<br>
$6724$ is an $S$-number: $\sqrt{6724} = 6+72+4$. <br>
$8281$ is an $S$-number: $\sqrt{8281} = 8+2+81 = 82+8+1$.<br>
$9801$ is an $S$-number: $\sqrt{9801}=98+0+1$.
</p>
<p>
Further we define $T(N)$ to be the sum of all $S$ numbers $n\le N$. You are given $T(10^4) = 41333$.
</p>
<p>
Find $T(10^{12})$.
</p>
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

bool dfs(long long val, long long carry, long long p, long long target)
{
	if (val == 0)
		return carry == target;

	// case 1: cut
	if (carry != -1 && target >= carry && dfs(val, -1, 1, target - carry))
		return true;

	// case 2: carry
	if (carry == -1)
		return dfs(val / 10, val % 10, p * 10, target);
	else
		return dfs(val / 10, val % 10 * p + carry, p * 10, target);
}

long long euler(long long n)
{
	long long ub = sqrt(n);
	long long ans = 0;

	for (long long r = 2; r <= ub; ++r)
	{
		if (dfs(r * r, -1, 1, r))
		{
			cout << r << "\t" << (r * r) << "\n";
			ans += r * r;
		}
	}

	return ans;
}

int main()
{
	//cout << euler(1e4) << "\n";
	cout << euler(1e12) << "\n";

	return 0;
}
