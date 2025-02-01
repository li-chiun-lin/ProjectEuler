/*
25%

<p>The number $512$ is interesting because it is equal to the sum of its digits raised to some power: $5 + 1 + 2 = 8$, and $8^3 = 512$. Another example of a number with this property is $614656 = 28^4$.</p>
<p>We shall define $a_n$ to be the $n$th term of this sequence and insist that a number must contain at least two digits to have a sum.</p>
<p>You are given that $a_2 = 512$ and $a_{10} = 614656$.</p>
<p>Find $a_{30}$.</p>
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

int euler()
{
	int sum = 0;

	for (int a = 3; a <= 1000; ++a)
	{
		int a2 = a * a;
		int r_max = 2;

		for (int n = 1; 2 * n < a; ++n)
			r_max = max(r_max, (2 * n * a) % a2);

		sum += r_max;
	}

	return sum;
}

int main()
{
	cout << euler() << "\n";

	return 0;
}
