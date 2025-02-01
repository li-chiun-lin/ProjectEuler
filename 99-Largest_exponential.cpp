/*
10%

<p>Comparing two numbers written in index form like $2^{11}$ and $3^7$ is not difficult, as any calculator would confirm that $2^{11} = 2048 \lt 3^7 = 2187$.</p>
<p>However, confirming that $632382^{518061} \gt 519432^{525806}$ would be much more difficult, as both numbers contain over three million digits.</p>
<p>Using <a href="resources/documents/0099_base_exp.txt">base_exp.txt</a> (right click and 'Save Link/Target As...'), a 22K text file containing one thousand lines with a base/exponent pair on each line, determine which line number has the greatest numerical value.</p>
<p class="smaller">NOTE: The first two lines in the file represent the numbers in the example given above.</p>
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
	ifstream ifs("p099_base_exp.txt", ifstream::in);
	string line = "";
	int idx = 1;
	int b = 1;
	int e = 1;
	double l = 0;
	int i = 0;
	
	while (ifs >> line)
	{
		string base = "";
		string exp = "";
		stringstream ss(line);

		getline(ss, base, ',');
		getline(ss, exp, ',');

		int bb = stoi(base);
		int ee = stoi(exp);
		double ll = ee * log(bb);

		if (l < ll)
		{
			cout << idx << ": " << b << "^" << e << " < " << bb << "^" << ee << "\n";
			b = bb;
			e = ee;
			l = ll;
			i = idx;
		}

		++ idx;
	}

	ifs.close();

	return i;
}

int main()
{
	cout << euler() << "\n";

	return 0;
}
