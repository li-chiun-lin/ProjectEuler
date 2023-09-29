/*
50%

We can easily verify that none of the entries in the first seven rows of Pascal's triangle are divisible by 7:
						
      1
     1 1
    1 2 1
   1 3 3 1
  1 4 6 4 1
 1 5 10 10 5 1
1 6 15 20 15 6 1
	
However, if we check the first one hundred rows, we will find that only 2361 of the entries are not divisible by 7.

Find the number of entries which are not divisible by 7 in the first one billion (10^9) rows of Pascal's triangle.
*/

#define _USE_MATH_DEFINES

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void print(vector<int>& row, int n)
{
	for (int i = 0; i <= n; ++i)
		cout << !! row[i] << " ";

	for (int i = n + 1; i < size(row); ++i)
		cout << "." << " ";
	cout << "\n";
}

long long convert(int n)
{
	long long cnt = 1;

	while (n)
	{
		cnt *= (n % 7) + 1;
		n /= 7;
	}

	return cnt;
}

long long euler(int n)
{
	long long cnt = 0;

	for (int i = 0; i < n; ++i)
		cnt += convert(i);

	return cnt;
}

int naive(int n)
{
	vector<int> row(n + 1, 1);
	int cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i - 1; j > 0; --j)
		{
			row[j] = (row[j] + row[j - 1]) % 7;
			cnt += !! row[j];
		}

		cnt += 2;

		cout << setw(3) << i << "   ";
		print(row, i);
	}

	cout << euler(n) << "\n";

	return cnt - 1;
}

int main()
{
	//cout << naive(7) << "\n";
	//cout << naive(21) << "\n";
	//cout << naive(23) << "\n";
	//cout << naive(52) << "\n";
	//cout << naive(15) << "\n";
	//cout << naive(1e5) << "\n";
	//cout << naive(9) << "\n";
	cout << euler(1e9) << "\n";

	return 0;
}

