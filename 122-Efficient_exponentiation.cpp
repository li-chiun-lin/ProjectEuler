/*
40%

<p>The most naive way of computing $n^{15}$ requires fourteen multiplications:
$$n \times n \times \cdots \times n = n^{15}.$$</p>
<p>But using a "binary" method you can compute it in six multiplications:</p>
\begin{align}
n \times n &amp;= n^2\\
n^2 \times n^2 &amp;= n^4\\
n^4 \times n^4 &amp;= n^8\\
n^8 \times n^4 &amp;= n^{12}\\
n^{12} \times n^2 &amp;= n^{14}\\
n^{14} \times n &amp;= n^{15}
\end{align}
<p>However it is yet possible to compute it in only five multiplications:</p>
\begin{align}
n \times n &amp;= n^2\\
n^2 \times n &amp;= n^3\\
n^3 \times n^3 &amp;= n^6\\
n^6 \times n^6 &amp;= n^{12}\\
n^{12} \times n^3 &amp;= n^{15}
\end{align}
<p>We shall define $m(k)$ to be the minimum number of multiplications to compute $n^k$; for example $m(15) = 5$.</p>
<p>Find $\sum\limits_{k = 1}^{200} m(k)$.</p>
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

void dfs(vector<int>& cache, int power, int depth, int& ret)
{
	if (depth >= ret)
		return;

	for (int i = cache.size() - 1; i >= 0; --i)
	{
		if (cache[i] + cache.back() > power)
			continue;

		if (cache[i] + cache.back() == power)
		{
			ret = min(ret, depth + 1);
			return;
		}

		cache.push_back(cache[i] + cache.back());
		dfs(cache, power, depth + 1, ret);
		cache.pop_back();
	}
}

int euler(int n)
{
	vector<int> cache = {1};
	int ret = n;
	dfs(cache, n, 0, ret);

	return ret;
}

int main()
{
	int sum = 0;

	for (int i = 2; i <= 200; ++i)
		sum += euler(i);

	cout << sum << "\n";

	return 0;
}
