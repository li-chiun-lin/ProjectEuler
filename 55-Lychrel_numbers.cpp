/*
5%

If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

	349 + 943 = 1292,
	1292 + 2921 = 4213
	4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?

NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.
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

vector<int> to_digit(int n)
{
	vector<int> d;

	while (n)
	{
		d.push_back(n % 10);
		n /= 10;
	}

	return d;
}

void add(vector<int> &a, vector<int> &b)
{
	int c = 0;
	int n = a.size();

	for (int i = 0; i < n; ++i)
	{
		a[i] += b[i] + c;
		c = a[i] / 10;
		a[i] %= 10;
	}

	if (c)
		a.push_back(c);
}

bool isPal(vector<int> &a)
{
	int i = 0; 
	int j = a.size() - 1;

	while (i < j)
		if (a[i ++] != a[j --])
			return false;

	return true;
}

void print(vector<int> &v)
{
	for (int x : v)
		cout << x;
	cout << " ";
}

int euler(int n)
{
	int cnt = 0;

	for (int i = 1; i <= n; ++i)
	{
		cout << i << " : ";
		vector<int> a = to_digit(i);
		bool pal = false;

		for (int j = 0; j < 50 && ! pal; ++j)
		{
			vector<int> b = a;
			reverse(begin(b), end(b));
			add(a, b);

			pal = isPal(a);

			print(a);
		}
		
		cout << endl;

		cnt += ! pal;
	}

	return cnt;
}

int main()
{
	cout << euler(10000) << endl;

	return 0;
}
