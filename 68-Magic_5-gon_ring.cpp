/*
25%

<p>Consider the following "magic" 3-gon ring, filled with the numbers 1 to 6, and each line adding to nine.</p>
<div class="center">
<img src="resources/images/0068_1.png?1678992052" class="dark_img" alt=""><br></div>
<p>Working <b>clockwise</b>, and starting from the group of three with the numerically lowest external node (4,3,2 in this example), each solution can be described uniquely. For example, the above solution can be described by the set: 4,3,2; 6,2,1; 5,1,3.</p>
<p>It is possible to complete the ring with four different totals: 9, 10, 11, and 12. There are eight solutions in total.</p>
<div class="center">
<table width="400" cellspacing="0" cellpadding="0"><tr><td width="100"><b>Total</b></td><td width="300"><b>Solution Set</b></td>
</tr><tr><td>9</td><td>4,2,3; 5,3,1; 6,1,2</td>
</tr><tr><td>9</td><td>4,3,2; 6,2,1; 5,1,3</td>
</tr><tr><td>10</td><td>2,3,5; 4,5,1; 6,1,3</td>
</tr><tr><td>10</td><td>2,5,3; 6,3,1; 4,1,5</td>
</tr><tr><td>11</td><td>1,4,6; 3,6,2; 5,2,4</td>
</tr><tr><td>11</td><td>1,6,4; 5,4,2; 3,2,6</td>
</tr><tr><td>12</td><td>1,5,6; 2,6,4; 3,4,5</td>
</tr><tr><td>12</td><td>1,6,5; 3,5,4; 2,4,6</td>
</tr></table></div>
<p>By concatenating each group it is possible to form 9-digit strings; the maximum string for a 3-gon ring is 432621513.</p>
<p>Using the numbers 1 to 10, and depending on arrangements, it is possible to form 16- and 17-digit strings. What is the maximum <b>16-digit</b> string for a "magic" 5-gon ring?</p>
<div class="center">
<img src="resources/images/0068_2.png?1678992052" class="dark_img" alt=""><br></div>
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

void print(set<int>& v)
{
	for (auto x : v)
		cout << x << "";
	cout << "\n";
}

void print(vector<int>& v)
{
	for (auto x : v)
		cout << x << "";
	cout << "\n";
}

void print(vector<vector<int>>& line)
{
	for (auto& l : line)
	{
		for (auto x : l)
			cout << x;
		cout << "\n";
	}
}

int euler()
{
	vector<vector<int>> solutions;

	int limit = 1 << 9;

	for (int i = 0x1f; i < limit; ++i)
	{
		if (__builtin_popcount(i) != 5)
			continue;

		int internal_sigma = 0;

		for (int j = 0; j < 9; ++j)
			if ((1 << j) & i)
				internal_sigma += j + 1;

		if (internal_sigma % 5)
			continue;

		vector<int> external_nodes, internal_nodes;

		for (int j = 0; j < 9; ++j)
		{
			if ((1 << j) & i)
				internal_nodes.push_back(j + 1);
			else
				external_nodes.push_back(j + 1);
		}

		external_nodes.push_back(10);

		int q = internal_sigma / 5;
		int line_sum = 11 + q;

#if 0
		cout << "A: ";
		print(external_nodes);
		cout << "B: ";
		print(internal_nodes);
		cout << "sigma B " << internal_sigma << "\n";
		cout << "line sum " << line_sum << "\n";
		cout << "\n";
#endif

		do
		{
			bool check = true;

			for (int j = 0; j < 5 && check; ++j)
				if (external_nodes[j] + internal_nodes[j] + internal_nodes[(j + 1) % 5] != line_sum)
					check = false;
			
			if (! check)
				continue;

			int min_ext_i = min_element(begin(external_nodes), end(external_nodes)) - begin(external_nodes);

			solutions.push_back({});

			for (int j = 0; j < 5; ++j)
			{
				solutions.back().push_back(external_nodes[(min_ext_i + j) % 5]);
				solutions.back().push_back(internal_nodes[(min_ext_i + j) % 5]);
				solutions.back().push_back(internal_nodes[(min_ext_i + j + 1) % 5]);
			}

		} while (next_permutation(begin(internal_nodes), end(internal_nodes)));
	}

	if (solutions.size())
	{
		sort(begin(solutions), end(solutions), greater<>());
		print(solutions);
	}

	return 0;
}

int main()
{
	cout << euler() << endl;

	return 0;
}
