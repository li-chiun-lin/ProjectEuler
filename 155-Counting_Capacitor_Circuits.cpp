/*
65%

<p>An electric circuit uses exclusively identical capacitors of the same value $C$.
<br>
The capacitors can be connected in series or in parallel to form sub-units, which can then be connected in series or in parallel with other capacitors or other sub-units to form larger sub-units, and so on up to a final circuit.</p>
<p>Using this simple procedure and up to $n$ identical capacitors, we can make circuits having a range of different total capacitances. For example, using up to $n=3$ capacitors of $\pu{60 \mu F}$ each, we can obtain the following $7$ distinct total capacitance values: </p>
<div class="center"><img src="resources/images/0155_capacitors1.gif?1678992055" class="dark_img" alt=""></div>
<p>If we denote by $D(n)$ the number of distinct total capacitance values we can obtain when using up to $n$ equal-valued capacitors and the simple procedure described above, we have: $D(1)=1$, $D(2)=3$, $D(3)=7$, $\dots$</p>
<p>Find $D(18)$.</p>
<p><i>Reminder:</i> When connecting capacitors $C_1, C_2$ etc in parallel, the total capacitance is $C_T = C_1 + C_2 + \cdots$,
<br>
whereas when connecting them in series, the overall capacitance is given by: $\dfrac{1}{C_T} = \dfrac{1}{C_1} + \dfrac{1}{C_2} + \cdots$</p>
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

class Num
{
	int nu;
	int de;

public:
	Num(int n = 0, int d = 1) : nu(n), de(d) {}
	
	bool operator<(const Num& that) const
	{
		return nu * that.de < that.nu * de;
	}

	bool operator==(const Num& that) const
	{
		return nu * that.de == that.nu * de;
	}

	void simplify()
	{
		int g = 1;

		while ((g = gcd(nu, de)) != 1)
		{
			nu /= g;
			de /= g;
		}
	}

	Num operator+(const Num& that) const
	{
		Num val;

		val.de = de * that.de;
		val.nu = nu * that.de + that.nu * de;
		val.simplify();
		
		return val;
	}

	Num reciprocal() const
	{
		return Num(de, nu);
	}

	friend ostream& operator<<(ostream& os, const Num& that);
};

ostream& operator<<(ostream& os, const Num& that)
{
	os << that.nu << "/" << that.de;
	return os;
}

int euler(int n)
{
	vector<set<Num>> vec(n + 1);
	vec[1] = { 1 };

	for (int i = 2; i <= n; ++i)
		for (int j = 1, k = i - 1; j <= i / 2; ++j, --k)
			for (auto& x : vec[j])
				for (auto& y : vec[k])
				{
					vec[i].insert(x + y);
					vec[i].insert((x.reciprocal() + y.reciprocal()).reciprocal());
				}

	set<Num> total;

	for (auto& v : vec)
		total.insert(begin(v), end(v));

	return size(total);
}

int main()
{
	cout << euler(3) << "\n";
	cout << euler(18) << "\n";

	return 0;
}
