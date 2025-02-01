/*
25%

<p>Consider quadratic Diophantine equations of the form:
$$x^2 - Dy^2 = 1$$</p>
<p>For example, when $D=13$, the minimal solution in $x$ is $649^2 - 13 \times 180^2 = 1$.</p>
<p>It can be assumed that there are no solutions in positive integers when $D$ is square.</p>
<p>By finding minimal solutions in $x$ for $D = \{2, 3, 5, 6, 7\}$, we obtain the following:</p>
\begin{align}
3^2 - 2 \times 2^2 &amp;= 1\\
2^2 - 3 \times 1^2 &amp;= 1\\
{\color{red}{\mathbf 9}}^2 - 5 \times 4^2 &amp;= 1\\
5^2 - 6 \times 2^2 &amp;= 1\\
8^2 - 7 \times 3^2 &amp;= 1
\end{align}
<p>Hence, by considering minimal solutions in $x$ for $D \le 7$, the largest $x$ is obtained when $D=5$.</p>
<p>Find the value of $D \le 1000$ in minimal solutions of $x$ for which the largest value of $x$ is obtained.</p>
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
#include <gmpxx.h> // GMP C++ wrapper

using namespace std;

bool isPerfectSquare(int n) 
{
    int root = static_cast<int>(sqrt(n));
    return root * root == n;
}

mpz_class solvePellEquation(int D) 
{
    mpz_class m = 0, d = 1, a = static_cast<int>(sqrt(D));
    mpz_class num1 = 1, num2 = a; // Previous and current numerators
    mpz_class denom1 = 0, denom2 = 1; // Previous and current denominators

    while (num2 * num2 - D * denom2 * denom2 != 1) 
    {
        m = d * a - m;
        d = (D - m * m) / d;
        a = (static_cast<int>(sqrt(D)) + m) / d;

        mpz_class nextNum = a * num2 + num1;
        mpz_class nextDenom = a * denom2 + denom1;

        num1 = num2;
        num2 = nextNum;
        denom1 = denom2;
        denom2 = nextDenom;
    }

    return num2; // Minimal x as an arbitrary-precision integer
}

int euler(int n)
{
	mpz_class largestX = 0;
    int resultD = 0;

    for (int D = 2; D <= n; D++) 
    {
        if (isPerfectSquare(D)) 
        {
            continue; // Skip perfect squares
        }

        mpz_class x = solvePellEquation(D);
        if (x > largestX) 
        {
            largestX = x;
            resultD = D;
        }
    }

	return resultD;
}

int main()
{
	cout << euler(1000) << "\n";

	return 0;
}
