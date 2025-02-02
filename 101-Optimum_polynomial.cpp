/*
35%

<p>If we are presented with the first $k$ terms of a sequence it is impossible to say with certainty the value of the next term, as there are infinitely many polynomial functions that can model the sequence.</p>
<p>As an example, let us consider the sequence of cube numbers. This is defined by the generating function,<br>$u_n = n^3$: $1, 8, 27, 64, 125, 216, \dots$</p>
<p>Suppose we were only given the first two terms of this sequence. Working on the principle that "simple is best" we should assume a linear relationship and predict the next term to be $15$ (common difference $7$). Even if we were presented with the first three terms, by the same principle of simplicity, a quadratic relationship should be assumed.</p>
<p>We shall define $\operatorname{OP}(k, n)$ to be the $n$<sup>th</sup> term of the optimum polynomial generating function for the first $k$ terms of a sequence. It should be clear that $\operatorname{OP}(k, n)$ will accurately generate the terms of the sequence for $n \le k$, and potentially the <dfn>first incorrect term</dfn> (FIT) will be $\operatorname{OP}(k, k+1)$; in which case we shall call it a <dfn>bad OP</dfn> (BOP).</p>
<p>As a basis, if we were only given the first term of sequence, it would be most sensible to assume constancy; that is, for $n \ge 2$, $\operatorname{OP}(1, n) = u_1$.</p>
<p>Hence we obtain the following $\operatorname{OP}$s for the cubic sequence:</p>
<div class="margin_left">
<table><tr><td>$\operatorname{OP}(1, n) = 1$</td>
<td>$1, {\color{red}\mathbf 1}, 1, 1, \dots$</td>
</tr><tr><td>$\operatorname{OP}(2, n) = 7n - 6$</td>
<td>$1, 8, {\color{red}\mathbf{15}}, \dots$</td>
</tr><tr><td>$\operatorname{OP}(3, n) = 6n^2 - 11n + 6$     </td>
<td>$1, 8, 27, {\color{red}\mathbf{58}}, \dots$</td>
</tr><tr><td>$\operatorname{OP}(4, n) = n^3$</td>
<td>$1, 8, 27, 64, 125, \dots$</td>
</tr></table></div>
<p>Clearly no BOPs exist for $k \ge 4$.</p>
<p>By considering the sum of FITs generated by the BOPs (indicated in <span class="red"><b>red</b></span> above), we obtain $1 + 15 + 58 = 74$.</p>
<p>Consider the following tenth degree polynomial generating function:
$$u_n = 1 - n + n^2 - n^3 + n^4 - n^5 + n^6 - n^7 + n^8 - n^9 + n^{10}.$$</p>
<p>Find the sum of FITs for the BOPs.</p>
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

long long u(int n)
{
	long long r = 0;
	long long b = 1;
	long long s = 1;

	for (int i = 0; i <= 10; ++i)
	{
		r += s * b;
		b *= n;
		s *= -1;
	}

	return r;

	//return n * n * n;
}

double lagrange(vector<pair<double, double>>& k, int x)
{
	int n = k.size();
	double y = 0;

	for (int i = 0; i < n; ++i)
	{
		vector<double> nu, de;
		auto [x1, y1] = k[i];

		for (int j = 0; j < n; ++j)
		{
			if (j == i)
				continue;

			auto [x2, y2] = k[j];

			nu.push_back(x - x2);
			de.push_back(x1 - x2);
		}

		nu.push_back(y1);

		double sim = 1;

		for (auto a : nu)
			sim *= a;

		for (auto b : de)
			sim /= b;

		y += sim;
	}

	return y;
}

void test_lagrange()
{
	vector<pair<double, double>> k = {
		{4, 10}, 
		{5, 5.25}, 
		{6, 1}
	};

	cout << lagrange(k, 18) << "\n";
}

long long euler()
{
	vector<pair<double, double>> k = {
		{1, 1}
	};

	long long ret = 0;

	for (int i = 2; ; ++i)
	{
		auto op = lagrange(k, i);
		auto un = u(i);

		if (op == un)
			break;

		ret += op;

		cout << i << " " << op << "\n";
		k.push_back({i, un});
	}

	return ret;
}

int main()
{
	//test_lagrange();
	cout << euler() << "\n";

	return 0;
}
