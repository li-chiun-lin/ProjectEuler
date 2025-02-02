/*
5%

<p>The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form $2^{6972593} - 1$; it contains exactly $2\,098\,960$ digits. Subsequently other Mersenne primes, of the form $2^p - 1$, have been found which contain more digits.</p>
<p>However, in 2004 there was found a massive non-Mersenne prime which contains $2\,357\,207$ digits: $28433 \times 2^{7830457} + 1$.</p>
<p>Find the last ten digits of this prime number.</p>
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

long long euler()
{
	long long r = 28433;
	long long m = 1e10;

	for (int i = 0; i < 7830457; ++i)
		r = (r << 1) % m;

	return r + 1;
}

int main()
{
	cout << euler() << "\n";

	return 0;
}
