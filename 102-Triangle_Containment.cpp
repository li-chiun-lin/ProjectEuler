/*
15%

<p>Three distinct points are plotted at random on a Cartesian plane, for which $-1000 \le x, y \le 1000$, such that a triangle is formed.</p>
<p>Consider the following two triangles:</p>
\begin{gather}
A(-340,495), B(-153,-910), C(835,-947)\\
X(-175,41), Y(-421,-714), Z(574,-645)
\end{gather}
<p>It can be verified that triangle $ABC$ contains the origin, whereas triangle $XYZ$ does not.</p>
<p>Using <a href="resources/documents/0102_triangles.txt">triangles.txt</a> (right click and 'Save Link/Target As...'), a 27K text file containing the co-ordinates of one thousand "random" triangles, find the number of triangles for which the interior contains the origin.</p>
<p class="smaller">NOTE: The first two examples in the file represent the triangles in the example given above.</p>
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

// Function to calculate the signed area of a triangle formed by (x1, y1), (x2, y2), (x3, y3)
double area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
}

int euler(vector<tuple<int, int, int, int, int, int>>& triangles) {
	int cnt = 0;

	for (auto& [x1, y1, x2, y2, x3, y3] : triangles)
	{
		// Calculate the area of the main triangle
		double mainArea = abs(area(x1, y1, x2, y2, x3, y3));
		
		// Calculate the areas of the three sub-triangles formed with the origin
		double area1 = abs(area(0, 0, x2, y2, x3, y3));
		double area2 = abs(area(x1, y1, 0, 0, x3, y3));
		double area3 = abs(area(x1, y1, x2, y2, 0, 0));
		
		// The origin is inside the triangle if the sum of the areas of the sub-triangles is equal to the area of the main triangle
		if (area1 + area2 + area3 == mainArea)
			++ cnt;
	}

    return cnt;
}

int main()
{
	ifstream ifs("p102_triangles.txt", ifstream::in);
	vector<tuple<int, int, int, int, int, int>> triangles;

	int x1 = 0, y1 = 0;
	int x2 = 0, y2 = 0;
	int x3 = 0, y3 = 0;
	string line;

	while (getline(ifs, line))
	{
		stringstream ss(line);

		ss >> x1;
		ss.ignore(1);
		ss >> y1;
		ss.ignore(1);
		ss >> x2;
		ss.ignore(1);
		ss >> y2;
		ss.ignore(1);
		ss >> x3;
		ss.ignore(1);
		ss >> y3;

		triangles.push_back({x1, y1, x2, y2, x3, y3});
	}

	cout << euler(triangles) << "\n";

	ifs.close();

	return 0;
}
