/*
5%

<p>Starting in the top left corner of a $2 \times 2$ grid, and only being able to move to the right and down, there are exactly $6$ routes to the bottom right corner.</p>
<div class="center">
<img src="resources/images/0015.png?1678992052" class="dark_img" alt=""></div>
<p>How many such routes are there through a $20 \times 20$ grid?</p>
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

void print(vector<vector<long long>> &dp)
{
	for (auto & r : dp)
	{
		for (auto &c : r)
			cout << c << " ";
		cout << endl;
	}
	cout << endl;
}

long long euler(int n)
{
	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 1));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];

	//print(dp);


	return dp[n][n];
}

int main()
{
	cout << euler(20) << endl;

	return 0;
}
