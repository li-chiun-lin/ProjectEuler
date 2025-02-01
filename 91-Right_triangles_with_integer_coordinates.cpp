/*
25%

<p>The points $P(x_1, y_1)$ and $Q(x_2, y_2)$ are plotted at integer co-ordinates and are joined to the origin, $O(0,0)$, to form $\triangle OPQ$.</p>

<div class="center">
<img src="resources/images/0091_1.png?1678992052" class="dark_img" alt=""><br></div>

<p>There are exactly fourteen triangles containing a right angle that can be formed when each co-ordinate lies between $0$ and $2$ inclusive; that is, $0 \le x_1, y_1, x_2, y_2 \le 2$.</p>

<div class="center">
<img src="resources/images/0091_2.png?1678992052" alt=""><br></div>

<p>Given that $0 \le x_1, y_1, x_2, y_2 \le 50$, how many right triangles can be formed?</p>
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

int euler(int n)
{
	int cnt = 0;

	for (int px = 1; px <= n; ++px)
		for (int py = 1; py <= n; ++py)
		{
			int g = gcd(px, py);
			int dx = px / g;
			int dy = py / g;

			for (int qx = px - dy, qy = py + dx; qx >= 0 && qy <= n; qx -= dy, qy += dx) ++ cnt;
			for (int qx = px + dy, qy = py - dx; qx <= n && qy >= 0; qx += dy, qy -= dx) ++ cnt;
		}

	return cnt + n * n * 3;
}

int main()
{
	cout << euler(50) << "\n";

	return 0;
}
