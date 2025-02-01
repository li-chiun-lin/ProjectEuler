/*
55%

In a triangular array of positive and negative integers, we wish to find a sub-triangle such that the sum of the numbers it contains is the smallest possible.

In the example below, it can be easily verified that the marked triangle satisfies this condition having a sum of −42.

 15
-14,  -7
 20, -13, -5
 -3,   8, 23, -23
  1,  -4, -5, -18,  5
-16,  31,  2,   9, 28, 3

We wish to make such a triangular array with one thousand rows, so we generate 500500 pseudo-random numbers sk in the range ±2^19, using a type of random number generator (known as a Linear Congruential Generator) as follows:

t := 0
for k = 1 up to k = 500500:
    t := (615949*t + 797807) modulo 2^20
    sk := t−2^19

Thus: s1 = 273519, s2 = −153582, s3 = 450905 etc

Our triangular array is then formed using the pseudo-random numbers thus:
s1
s2  s3
s4  s5  s6 
s7  s8  s9  s10
...

Sub-triangles can start at any element of the array and extend down as far as we like (taking-in the two elements directly below it from the next row, the three elements directly below from the row after that, and so on).
The "sum of a sub-triangle" is defined as the sum of all the elements it contains.
Find the smallest possible sub-triangle sum.

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

long long euler()
{
	#define N 1000
	int accu[N][N + 1] = {0};
	long long ans = LLONG_MAX;
	long long t = 0;
	int mod = 1 << 20;
	int sub = 1 << 19;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j)
		{
			t = (t * 615949 + 797807) % mod;
			accu[i][j + 1] = accu[i][j] + t - sub;
		}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j)
		{
			long long val = 0;

			for (int k = 0; i + k < N; ++k)
				ans = min(ans, val += accu[i + k][j + k + 1] - accu[i + k][j]);
		}

	return ans;
}

int main()
{
	cout << euler() << "\n";

	return 0;
}
