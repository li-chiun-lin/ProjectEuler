/*
15%

<p>The square root of $2$ can be written as an infinite continued fraction.</p>
<p>$\sqrt{2} = 1 + \dfrac{1}{2 + \dfrac{1}{2 + \dfrac{1}{2 + \dfrac{1}{2 + ...}}}}$</p>
<p>The infinite continued fraction can be written, $\sqrt{2} = [1; (2)]$, $(2)$ indicates that $2$ repeats <i>ad infinitum</i>. In a similar way, $\sqrt{23} = [4; (1, 3, 1, 8)]$.</p>
<p>It turns out that the sequence of partial values of continued fractions for square roots provide the best rational approximations. Let us consider the convergents for $\sqrt{2}$.</p>
<p>$\begin{align}
&amp;1 + \dfrac{1}{2} = \dfrac{3}{2} \\
&amp;1 + \dfrac{1}{2 + \dfrac{1}{2}} = \dfrac{7}{5}\\
&amp;1 + \dfrac{1}{2 + \dfrac{1}{2 + \dfrac{1}{2}}} = \dfrac{17}{12}\\
&amp;1 + \dfrac{1}{2 + \dfrac{1}{2 + \dfrac{1}{2 + \dfrac{1}{2}}}} = \dfrac{41}{29}
\end{align}$</p>
<p>Hence the sequence of the first ten convergents for $\sqrt{2}$ are:</p>
<p>$1, \dfrac{3}{2}, \dfrac{7}{5}, \dfrac{17}{12}, \dfrac{41}{29}, \dfrac{99}{70}, \dfrac{239}{169}, \dfrac{577}{408}, \dfrac{1393}{985}, \dfrac{3363}{2378}, ...$</p>
<p>What is most surprising is that the important mathematical constant,<br>$e = [2; 1, 2, 1, 1, 4, 1, 1, 6, 1, ... , 1, 2k, 1, ...]$.</p>
<p>The first ten terms in the sequence of convergents for $e$ are:</p>
<p>$2, 3, \dfrac{8}{3}, \dfrac{11}{4}, \dfrac{19}{7}, \dfrac{87}{32}, \dfrac{106}{39}, \dfrac{193}{71}, \dfrac{1264}{465}, \dfrac{1457}{536}, ...$</p>
<p>The sum of digits in the numerator of the $10$<sup>th</sup> convergent is $1 + 4 + 5 + 7 = 17$.</p>
<p>Find the sum of digits in the numerator of the $100$<sup>th</sup> convergent of the continued fraction for $e$.</p>
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

/**
 * Add two large numbers represented as reversed strings.
 */
string addReversedStrings(const string& a, const string& b) {
    string result;
    int carry = 0, i = 0, j = 0;

    while (i < a.size() || j < b.size() || carry > 0) {
        int sum = carry;
        if (i < a.size()) sum += a[i++] - '0';
        if (j < b.size()) sum += b[j++] - '0';

        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    return result; // Already reversed
}

/**
 * Multiply a large number (reversed string) by an integer.
 */
string multiplyReversedStringByInt(const string& num, int multiplier) {
    string result;
    int carry = 0;

    for (int i = 0; i < num.size(); ++i) {
        int product = (num[i] - '0') * multiplier + carry;
        carry = product / 10;
        result.push_back((product % 10) + '0');
    }

    while (carry > 0) {
        result.push_back((carry % 10) + '0');
        carry /= 10;
    }

    return result; // Already reversed
}

int euler(int n)
{
	// Generate the sequence for the continued fraction of e
	vector<int> sequence;
	sequence.push_back(2);

	for (int i = 1; size(sequence) < n; ++i)
	{
		sequence.push_back(1);
		sequence.push_back(2 * i);
		sequence.push_back(1);
	}

	while (size(sequence) > n)
	{
		sequence.pop_back();
	}

	string numerator = "1";
	string denominator = "0";

	for (auto it = sequence.rbegin(); it != sequence.rend(); ++it)
	{
		string temp = numerator;
        numerator = addReversedStrings(
            multiplyReversedStringByInt(numerator, *it), denominator);
        denominator = temp;
	}

	// Calculate the sum of the digits of the numerator
	return accumulate(begin(numerator), end(numerator), 0, [](int sum, char c) { return sum + c - '0'; });
}

int main()
{
	cout << euler(100) << "\n";

	return 0;
}
