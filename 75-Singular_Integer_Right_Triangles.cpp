/*
25%

<p>It turns out that $\pu{12 cm}$ is the smallest length of wire that can be bent to form an integer sided right angle triangle in exactly one way, but there are many more examples.</p>
<ul style="list-style-type:none;">
<li>$\pu{\mathbf{12} \mathbf{cm}}$: $(3,4,5)$</li>
<li>$\pu{\mathbf{24} \mathbf{cm}}$: $(6,8,10)$</li>
<li>$\pu{\mathbf{30} \mathbf{cm}}$: $(5,12,13)$</li>
<li>$\pu{\mathbf{36} \mathbf{cm}}$: $(9,12,15)$</li>
<li>$\pu{\mathbf{40} \mathbf{cm}}$: $(8,15,17)$</li>
<li>$\pu{\mathbf{48} \mathbf{cm}}$: $(12,16,20)$</li></ul>
<p>In contrast, some lengths of wire, like $\pu{20 cm}$, cannot be bent to form an integer sided right angle triangle, and other lengths allow more than one solution to be found; for example, using $\pu{120 cm}$ it is possible to form exactly three different integer sided right angle triangles.</p>
<ul style="list-style-type:none;">
<li>$\pu{\mathbf{120} \mathbf{cm}}$: $(30,40,50)$, $(20,48,52)$, $(24,45,51)$</li></ul>

<p>Given that $L$ is the length of the wire, for how many values of $L \le 1\,500\,000$ can exactly one integer sided right angle triangle be formed?</p>
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

int euler(int N)
{
	vector<int> count(N + 1);

	// Generate all Pythagorean triples using the Euclid's formula
    for (int m = 2; m * m < N; ++m) 
    {
        for (int n = 1; n < m; ++n) 
        {
            if ((m - n) % 2 == 1 && gcd(m, n) == 1) 
            {
                int a = m * m - n * n;
                int b = 2 * m * n;
                int c = m * m + n * n;
                int perimeter = a + b + c;

                // Scale the primitive triple to all multiples
                while (perimeter <= N) 
                {
                    ++count[perimeter];
                    perimeter += a + b + c;
                }
            }
        }
    }

	return count_if(count.begin(), count.end(), [](int x) { return x == 1; });
}

int main()
{
	cout << euler(1500000) << "\n";

	return 0;
}
