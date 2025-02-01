/*
5%

<p>By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.</p>
<p class="monospace center"><span class="red"><b>3</b></span><br><span class="red"><b>7</b></span> 4<br>
2 <span class="red"><b>4</b></span> 6<br>
8 5 <span class="red"><b>9</b></span> 3</p>
<p>That is, 3 + 7 + 4 + 9 = 23.</p>
<p>Find the maximum total from top to bottom in <a href="resources/documents/0067_triangle.txt">triangle.txt</a> (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.</p>
<p class="smaller"><b>NOTE:</b> This is a much more difficult version of <a href="problem=18">Problem 18</a>. It is not possible to try every route to solve this problem, as there are 2<sup>99</sup> altogether! If you could check one trillion (10<sup>12</sup>) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)</p>
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
#include <fstream>

using namespace std;

void print(vector<int> &v)
{
	for (int x : v)
		cout << x << " ";
	cout << endl;
}

int euler()
{
	ifstream ifs("p067_triangle.txt", ifstream::in);

	vector<vector<int>> tr;
	tr.push_back({});

	int n = 1;
	int d = 0;

	while (ifs >> d)
	{
		tr.back().push_back(d);

		if (tr.back().size() == n)
		{
			//print(tr.back());
			++ n;
			tr.push_back({});
		}
	}

	ifs.close();

	-- n;
	tr.pop_back();
	//cout << n << " " << tr.size() << " " << tr.back().size() << endl;

	vector<vector<int>> dp(2, vector<int>(n + 2));
	int prv = 0;
	int cur = 1 - prv;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < tr[i].size(); ++j)
			dp[cur][j + 1] = max(dp[prv][j], dp[prv][j + 1]) + tr[i][j];

		print(dp[cur]);
		
		prv = cur;
		cur = 1 - prv;
	}

	return *max_element(begin(dp[prv]), end(dp[prv]));
}

int main()
{
	cout << euler() << endl;

	return 0;
}
