/*
55%

<p>A triangular pyramid is constructed using spherical balls so that each ball rests on exactly three balls of the next lower level.</p>
<div class="center"><img src="resources/images/0154_pyramid.png?1678992052" class="dark_img" alt=""></div>
<p>Then, we calculate the number of paths leading from the apex to each position:</p>
<p>A path starts at the apex and progresses downwards to any of the three spheres directly below the current position.</p>
<p>Consequently, the number of paths to reach a certain position is the sum of the numbers immediately above it (depending on the position, there are up to three numbers above it).</p>
<p>The result is <strong>Pascal's pyramid</strong> and the numbers at each level $n$ are the coefficients of the trinomial expansion 
$(x + y + z)^n$.</p>
<p>How many coefficients in the expansion of $(x + y + z)^{200000}$ are multiples of $10^{12}$?</p>
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
	const int N = 200001;
	int div5[N + 1] = {0};
	int div2[N + 1] = {0};

	for (int i = 1; i < N; ++i)
	{
		int x = i;

		while (x % 2 == 0)
		{
			++ div2[i];
			x /= 2;
		}

		while (x % 5 == 0)
		{
			++ div5[i];
			x /= 5;
		}

		div5[i] += div5[i - 1];
		div2[i] += div2[i - 1];
	}

	long long ans = 0;

	for (int i = 0; i < N; ++i)
	{
		int cnt5 = div5[N - 1] - div5[N - 1 - i] - div5[i];
		int cnt2 = div2[N - 1] - div2[N - 1 - i] - div2[i];

		if (cnt2 >= 12 && cnt5 >= 12)
		{
			ans += i + 1;
			continue;
		}

		for (int j = 0; j <= (i + 1) / 2; ++j)
		{
			int c5 = div5[i] - div5[i - j] - div5[j];
			int c2 = div2[i] - div2[i - j] - div2[j];

			if (cnt2 + c2 >= 12 && cnt5 + c5 >= 12)
			{
				++ ans;

				if (j < i / 2)
					++ ans;
			}
		}
	}

	return ans;
}

int main()
{
	cout << euler() << "\n";

	return 0;
}
