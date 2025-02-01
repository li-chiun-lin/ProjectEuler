/*
30%

<p>If a box contains twenty-one coloured discs, composed of fifteen blue discs and six red discs, and two discs were taken at random, it can be seen that the probability of taking two blue discs, $P(\text{BB}) = (15/21) \times (14/20) = 1/2$.</p>
<p>The next such arrangement, for which there is exactly $50\%$ chance of taking two blue discs at random, is a box containing eighty-five blue discs and thirty-five red discs.</p>
<p>By finding the first arrangement to contain over $10^{12} = 1\,000\,000\,000\,000$ discs in total, determine the number of blue discs that the box would contain.</p>
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

long long euler(long long N)
{
	long long B = 3;
	long long T = 4;

	while (T <= N)
	{
		long long BB = 3 * B + 2 * T - 2;
		long long TT = 4 * B + 3 * T - 3;
		B = BB;
		T = TT;
	}

	return B;
}

int main()
{
	cout << euler(1'000'000'000'000LL) << "\n";

	return 0;
}
