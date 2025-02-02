/*
35%

<p>It is easily proved that no equilateral triangle exists with integral length sides and integral area. However, the <dfn>almost equilateral triangle</dfn> $5$-$5$-$6$ has an area of $12$ square units.</p>
<p>We shall define an <dfn>almost equilateral triangle</dfn> to be a triangle for which two sides are equal and the third differs by no more than one unit.</p>
<p>Find the sum of the perimeters of all <dfn>almost equilateral triangles</dfn> with integral side lengths and area and whose perimeters do not exceed one billion ($1\,000\,000\,000$).</p>
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

long long euler(int n)
{
	long long sum = 0;

	for (long long a = 3; ; a += 2)
	{
		for (long long b = a - 1; b <= a + 1; b += 2)
		{
			long long aab = a + a + b;
			long long s = aab / 2;

			if (aab > n)
				return sum;

			long long ssb = s * (s - b);
			long long rt = sqrt(ssb);

			if (rt * rt == ssb)
				sum += aab;
		}
	}

	return -1;
}

int main()
{
	cout << euler(1e9) << "\n";

	return 0;
}
