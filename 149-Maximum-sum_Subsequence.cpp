/*
50%

<p>Looking at the table below, it is easy to verify that the maximum possible sum of adjacent numbers in any direction (horizontal, vertical, diagonal or anti-diagonal) <span style="white-space:nowrap;">is $16$ ($= 8 + 7 + 1$).</span></p>

<div class="center">
<table border="1" cellpadding="6" cellspacing="0" style="margin:auto;"><tbody align="right"><tr><td width="25">$-2$</td><td width="25">$5$</td><td width="25">$3$</td><td width="25">$2$</td></tr><tr><td>$9$</td><td>$-6$</td><td>$5$</td><td>$1$</td></tr><tr><td>$3$</td><td>$2$</td><td>$7$</td><td>$3$</td></tr><tr><td>$-1$</td><td>$8$</td><td>$-4$</td><td>$8$</td></tr></tbody></table></div>

<p>Now, let us repeat the search, but on a much larger scale:</p>

<p>First, generate four million pseudo-random numbers using a specific form of what is known as a "Lagged Fibonacci Generator":</p>

<p>For $1 \le k \le 55$, $s_k = [100003 - 200003 k + 300007 k^3] \pmod{1000000} - 500000$.<br>
For $56 \le k \le 4000000$, $s_k = [s_{k-24} + s_{k - 55} + 1000000] \pmod{1000000} - 500000$.</p>

<p>Thus, $s_{10} = -393027$ and $s_{100} = 86613$.</p>

<p>The terms of $s$ are then arranged in a $2000 \times 2000$ table, using the first $2000$ numbers to fill the first row (sequentially), the next $2000$ numbers to fill the second row, and so on.</p>

<p>Finally, find the greatest sum of (any number of) adjacent entries in any direction (horizontal, vertical, diagonal or anti-diagonal).</p>
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

#define NN 4000000
#define N 2000

union data
{
	int row[NN];
	int mat[N][N];
};

void print_mat(union data* s)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << s->mat[i][j] << " ";
		cout << "\n";
	}
}

void print_row(union data* s)
{
	for (int i = 0; i < NN; ++i)
		cout << s->row[i] << " ";
	cout << "\n";
}

void print(vector<long long>& v)
{
	for (auto x : v)
		cout << x << " ";
	cout << "\n";
}

void lagged_fibonacci_generator(union data* s)
{
	for (long long k = 1; k <= 55; ++k)
		s->row[k - 1] = (100003 - 200003 * k + 300007 * k * k * k) % 1000000 - 500000;

	for (long long k = 56; k <= 4000000; ++k)
		s->row[k - 1] = (s->row[k - 24 - 1] + s->row[k - 55 - 1] + 1000000) % 1000000 - 500000;
}

int euler()
{
	union data *s = new union data;
	lagged_fibonacci_generator(s);
	long long ans = INT_MIN;

	// row
	for (int i = 0; i < N; ++i)
	{
		long long glo = 0, loc = 0;

		for (int j = 0; j < N; ++j)
		{
			loc = max(loc + s->mat[i][j], 0LL);
			glo = max(glo, loc);
		}

		ans = max(ans, glo);
	}

	// column
	for (int j = 0; j < N; ++j)
	{
		long long glo = 0, loc = 0;

		for (int i = 0; i < N; ++i)
		{
			loc = max(loc + s->mat[i][j], 0LL);
			glo = max(glo, loc);
		}

		ans = max(ans, glo);
	}

	// diagonal

	for (int i = 0; i < N; ++i)
	{
		long long glo = 0, loc = 0;
		int r = i;
		int c = 0;

		for (int j = 0; j <= i; ++j)
		{
			loc = max(loc + s->mat[r --][c ++], 0LL);
			glo = max(glo, loc);
		}

		ans = max(ans, glo);
	}

	for (int i = 0; i < N; ++i)
	{
		long long glo = 0, loc = 0;
		int r = N - 1;
		int c = i;

		for (int j = 0; j + i < N; ++j)
		{
			loc = max(loc + s->mat[r --][c ++], 0LL);
			glo = max(glo, loc);
		}

		ans = max(ans, glo);
	}

	// anti-diagonal

	for (int i = 0; i < N; ++i)
	{
		long long glo = 0, loc = 0;
		int r = i;
		int c = N - 1;

		for (int j = 0; j <= i; ++j)
		{
			loc = max(loc + s->mat[r --][c --], 0LL);
			glo = max(glo, loc);
		}

		ans = max(ans, glo);
	}

	for (int i = 0; i < N; ++i)
	{
		long long glo = 0, loc = 0;
		int r = N - 1;
		int c = N - 1;

		for (int j = 0; j + i < N; ++j)
		{
			loc = max(loc + s->mat[r --][c --], 0LL);
			glo = max(glo, loc);
		}

		ans = max(ans, glo);
	}

	return ans;
}

int main()
{
	cout << euler() << "\n";

	return 0;
}
