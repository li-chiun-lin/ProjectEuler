/*
30%

<p>A row of five grey square tiles is to have a number of its tiles replaced with coloured oblong tiles chosen from red (length two), green (length three), or blue (length four).</p>
<p>If red tiles are chosen there are exactly seven ways this can be done.</p>

<div class="center">
<img src="resources/images/0116_1.png?1678992052" alt="png116_1.png">
</div>

<p>If green tiles are chosen there are three ways.</p>

<div class="center">
<img src="resources/images/0116_2.png?1678992052" alt="png116_2.png">
</div>

<p>And if blue tiles are chosen there are two ways.</p>

<div class="center">
<img src="resources/images/0116_3.png?1678992052" alt="png116_3.png">
</div>

<p>Assuming that colours cannot be mixed there are $7 + 3 + 2 = 12$ ways of replacing the grey tiles in a row measuring five units in length.</p>
<p>How many different ways can the grey tiles in a row measuring fifty units in length be replaced if colours cannot be mixed and at least one coloured tile must be used?</p>
<p class="note">NOTE: This is related to <a href="problem=117">Problem 117</a>.</p>
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

long long euler(int m, int n)
{
	// all index shift by m, for convenient
	vector<long long> dp(n + 1 + m);
	dp[m] = 1;

	for (int len = 1, len_m = m + 1; len <= n; ++len, ++len_m)
		dp[len_m] =  
			+ dp[len_m - 1] 
			+ dp[len_m - m];

	// exclude the sole case that fills with all gray tiles
	return dp[n + m] - 1;
}

int main()
{
	cout << (euler(2, 50) + euler(3, 50) + euler(4, 50)) << "\n";

	return 0;
}
