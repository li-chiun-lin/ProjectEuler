/*
40%

<p>Each of the six faces on a cube has a different digit ($0$ to $9$) written on it; the same is done to a second cube. By placing the two cubes side-by-side in different positions we can form a variety of $2$-digit numbers.</p>

<p>For example, the square number $64$ could be formed:</p>

<div class="center">
<img src="resources/images/0090.png?1678992052" class="dark_img" alt=""><br></div>

<p>In fact, by carefully choosing the digits on both cubes it is possible to display all of the square numbers below one-hundred: $01$, $04$, $09$, $16$, $25$, $36$, $49$, $64$, and $81$.</p>

<p>For example, one way this can be achieved is by placing $\{0, 5, 6, 7, 8, 9\}$ on one cube and $\{1, 2, 3, 4, 8, 9\}$ on the other cube.</p>

<p>However, for this problem we shall allow the $6$ or $9$ to be turned upside-down so that an arrangement like $\{0, 5, 6, 7, 8, 9\}$ and $\{1, 2, 3, 4, 6, 7\}$ allows for all nine square numbers to be displayed; otherwise it would be impossible to obtain $09$.</p>

<p>In determining a distinct arrangement we are interested in the digits on each cube, not the order.</p>

<ul style="list-style-type:none;"><li>$\{1, 2, 3, 4, 5, 6\}$ is equivalent to $\{3, 6, 4, 1, 2, 5\}$</li>
<li>$\{1, 2, 3, 4, 5, 6\}$ is distinct from $\{1, 2, 3, 4, 5, 9\}$</li></ul>

<p>But because we are allowing $6$ and $9$ to be reversed, the two distinct sets in the last example both represent the extended set $\{1, 2, 3, 4, 5, 6, 9\}$ for the purpose of forming $2$-digit numbers.</p>

<p>How many distinct arrangements of the two cubes allow for all of the square numbers to be displayed?</p>
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
//#include <gmpxx.h> // GMP C++ wrapper

using namespace std;

// List of two-digit square numbers as pairs of digits
vector<pair<int, int>> squares = {
    {0, 1}, {0, 4}, {0, 9},
    {1, 6}, {2, 5}, {3, 6},
    {4, 9}, {6, 4}, {8, 1}
};

// Function to check if two cubes can display all the square numbers
bool canDisplayAllSquares(const set<int>& cube1, const set<int>& cube2) {
    for (const auto& [digit1, digit2] : squares) {
        // Check if the pair (digit1, digit2) can be formed
        bool valid = (cube1.count(digit1) && cube2.count(digit2)) ||
                     (cube1.count(digit2) && cube2.count(digit1));
        if (!valid) return false;
    }
    return true;
}

void dfs(int start, int depth, vector<int>& combination, vector<vector<int>>& combinations) {
	if (depth == size(combination))
	{
		combinations.push_back(combination);
		return ;
	}
	
	for (int i = start; i < 10; ++i) 
	{
		combination[depth] = i;
		dfs(i + 1, depth + 1, combination, combinations);
	}
}

int euler()
{
	// Generate all combinations of 6 digits for a cube
    vector<vector<int>> combinations;
    vector<int> combination(6);

	dfs(0, 0, combination, combinations);

	int count = 0;
	int n = size(combinations);

	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
		{
			set<int> cube1(begin(combinations[i]), end(combinations[i]));
			set<int> cube2(begin(combinations[j]), end(combinations[j]));

			if (cube1.count(6))
				cube1.insert(9);
			else if (cube1.count(9))
				cube1.insert(6);

			if (cube2.count(6))
				cube2.insert(9);
			else if (cube2.count(9))
				cube2.insert(6);

			if (canDisplayAllSquares(cube1, cube2))
				++ count;
		}

	return count;
}

int main()
{
	cout << euler() << "\n";

	return 0;
}
