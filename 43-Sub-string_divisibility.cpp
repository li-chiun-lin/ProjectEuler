/*
5%

<p>The number, $1406357289$, is a $0$ to $9$ pandigital number because it is made up of each of the digits $0$ to $9$ in some order, but it also has a rather interesting sub-string divisibility property.</p>
<p>Let $d_1$ be the $1$<sup>st</sup> digit, $d_2$ be the $2$<sup>nd</sup> digit, and so on. In this way, we note the following:</p>
<ul><li>$d_2d_3d_4=406$ is divisible by $2$</li>
<li>$d_3d_4d_5=063$ is divisible by $3$</li>
<li>$d_4d_5d_6=635$ is divisible by $5$</li>
<li>$d_5d_6d_7=357$ is divisible by $7$</li>
<li>$d_6d_7d_8=572$ is divisible by $11$</li>
<li>$d_7d_8d_9=728$ is divisible by $13$</li>
<li>$d_8d_9d_{10}=289$ is divisible by $17$</li>
</ul><p>Find the sum of all $0$ to $9$ pandigital numbers with this property.</p>
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

void print(vector<int> &v)
{
	for (int x : v)
		cout << x << " ";
	cout << endl;
}

void dfs(int i, vector<bool> selected, vector<int> &buf, long long &sum)
{
	if (i == 3)
	{
		for (int j = 0; j < 10; j += 2)
			if (! selected[j])
			{
				selected[j] = true;
				buf.push_back(j);
				dfs(i + 1, selected, buf, sum);
				buf.pop_back();
				selected[j] = false;
			}
	}
	else if (i == 4)
	{
		for (int j = 0; j < 10; ++j)
			if (! selected[j] && (j + buf[3] * 10 + buf[2] * 100) % 3 == 0)
			{
				selected[j] = true;
				buf.push_back(j);
				dfs(i + 1, selected, buf, sum);
				buf.pop_back();
				selected[j] = false;
			}
	}
	else if (i == 5)
	{
		if (! selected[5])
		{
			selected[5] = true;
			buf.push_back(5);
			dfs(i + 1, selected, buf, sum);
			buf.pop_back();
			selected[5] = false;
		}
	}
	else if (i == 6)
	{
		for (int j = 0; j < 10; ++j)
			if (! selected[j] && (j + buf[5] * 10 + buf[4] * 100) % 7 == 0)
			{
				selected[j] = true;
				buf.push_back(j);
				dfs(i + 1, selected, buf, sum);
				buf.pop_back();
				selected[j] = false;
			}
	}
	else if (i == 7)
	{
		for (int j = 0; j < 10; ++j)
			if (! selected[j] && (j + buf[6] * 10 + buf[5] * 100) % 11 == 0)
			{
				selected[j] = true;
				buf.push_back(j);
				dfs(i + 1, selected, buf, sum);
				buf.pop_back();
				selected[j] = false;
			}
	}
	else if (i == 8)
	{
		for (int j = 0; j < 10; ++j)
			if (! selected[j] && (j + buf[7] * 10 + buf[6] * 100) % 13 == 0)
			{
				selected[j] = true;
				buf.push_back(j);
				dfs(i + 1, selected, buf, sum);
				buf.pop_back();
				selected[j] = false;
			}
	}
	else if (i == 9)
	{
		for (int j = 0; j < 10; ++j)
			if (! selected[j] && (j + buf[8] * 10 + buf[7] * 100) % 17 == 0)
			{
				selected[j] = true;
				buf.push_back(j);
				dfs(i + 1, selected, buf, sum);
				buf.pop_back();
				selected[j] = false;
			}
	}
	else if (i == 10)
	{
		long long s = 0;

		for (int j = 0; j < 10; ++j)
		{
			s *= 10;
			s += buf[j];
		}

		sum += s;

		print(buf);
	}
	else 
	{
		for (int j = 0; j < 10; ++j)
			if (! selected[j])
			{
				selected[j] = true;
				buf.push_back(j);
				dfs(i + 1, selected, buf, sum);
				buf.pop_back();
				selected[j] = false;
			}
	}
}

long long euler()
{
	vector<bool> selected(10);
	vector<int> buf;
	long long sum = 0;

	dfs(0, selected, buf, sum);

	return sum;
}

int main()
{
	cout << euler() << endl;

	return 0;
}
