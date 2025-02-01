/*
5%

<p>Starting with the number $1$ and moving to the right in a clockwise direction a $5$ by $5$ spiral is formed as follows:</p>
<p class="monospace center"><span class="red"><b>21</b></span> 22 23 24 <span class="red"><b>25</b></span><br>
20  <span class="red"><b>7</b></span>  8  <span class="red"><b>9</b></span> 10<br>
19  6  <span class="red"><b>1</b></span>  2 11<br>
18  <span class="red"><b>5</b></span>  4  <span class="red"><b>3</b></span> 12<br><span class="red"><b>17</b></span> 16 15 14 <span class="red"><b>13</b></span></p>
<p>It can be verified that the sum of the numbers on the diagonals is $101$.</p>
<p>What is the sum of the numbers on the diagonals in a $1001$ by $1001$ spiral formed in the same way?</p>
*/

#include <algorithm>
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

void print(vector<vector<int>> &m)
{
	for (auto &r : m)
	{
		for (auto c : r)
			cout << setw(3) << c;
		cout << endl;
	}
	cout << endl;
}

int euler(int n)
{
	int val = n * n;
	vector<vector<int>> matrix(n, vector<int>(n));
	int di[] = {0, 1, 0, -1};
	int dj[] = {-1, 0, 1, 0};
	int i = 0;
	int j = n;
	int k = 0;

	while (val)
	{
		int ii = i + di[k];
		int jj = j + dj[k];

		if (0 <= ii && ii < n && 0 <= jj && jj < n && matrix[ii][jj] == 0)
		{
			i = ii;
			j = jj;
			matrix[ii][jj] = val --;
		}
		else
		{
			k = (k + 1) % 4;
		}
	}

	print(matrix);

	int sum = 0;

	for (int k = 0; k < n; ++k)
		sum += matrix[k][k] + matrix[k][n - 1 - k];

	return sum - matrix[n / 2][n / 2];
}

int main()
{
	cout << euler(1001) << endl;

	return 0;
}
