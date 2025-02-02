/*
5%

<p>The Fibonacci sequence is defined by the recurrence relation:</p>
<blockquote>$F_n = F_{n - 1} + F_{n - 2}$, where $F_1 = 1$ and $F_2 = 1$.</blockquote>
<p>Hence the first $12$ terms will be:</p>
\begin{align}
F_1 &amp;= 1\\
F_2 &amp;= 1\\
F_3 &amp;= 2\\
F_4 &amp;= 3\\
F_5 &amp;= 5\\
F_6 &amp;= 8\\
F_7 &amp;= 13\\
F_8 &amp;= 21\\
F_9 &amp;= 34\\
F_{10} &amp;= 55\\
F_{11} &amp;= 89\\
F_{12} &amp;= 144
\end{align}
<p>The $12$th term, $F_{12}$, is the first term to contain three digits.</p>
<p>What is the index of the first term in the Fibonacci sequence to contain $1000$ digits?</p>
*/

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <queue>

using namespace std;

void add(const vector<int> &a, const vector<int> &b, vector<int> &c)
{
	int i = 0;
	int car = 0;

	while (i < a.size() && i < b.size() && i < c.size())
	{
		c[i] = a[i] + b[i] + car;
		car = c[i] / 10;
		c[i] %= 10;
		++ i;
	}

	while (i < a.size() && i < b.size())
	{
		c.push_back(a[i] + b[i] + car);
		car = c.back() / 10;
		c.back() %= 10;
		++ i;
	}

	while (i < a.size() && i < c.size())
	{
		c[i] = a[i] + car;
		car = c[i] / 10;
		c[i] %= 10;
		++ i;
	}

	while (i < a.size())
	{
		c.push_back(a[i] + car);
		car = c.back() / 10;
		c.back() %= 10;
		++ i;
	}

	while (i < b.size() && i < c.size())
	{
		c[i] = b[i] + car;
		car = c[i] / 10;
		c[i] %= 10;
		++ i;
	}

	while (i < b.size())
	{
		c.push_back(b[i] + car);
		car = c.back() / 10;
		c.back() %= 10;
		++ i;
	}

	if (car)
	{
		if (i < c.size())
			c[i] = car;
		else
			c.push_back(car);
	}
}

void print(vector<int> &v)
{
	for (int x : v)
		cout << x;
	cout << endl;
}

int euler(int n)
{
	vector<int> a = {1};
	vector<int> b = {1};
	vector<int> c;
	int i = 2;

	while(c.size() < n)
	{
		++ i;
		add(a, b, c);
		//print(c);
		a = b;
		b = c;
	}

	return i;
}

int main()
{
	cout << euler(1000) << endl;

	return 0;
}
