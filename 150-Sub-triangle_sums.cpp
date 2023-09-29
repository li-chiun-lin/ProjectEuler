/*

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
	#if 1
	#define N 1000
	int T[N][N] = {0};
	//int* T[N];

	//for (int i = 0; i < N; ++i)
	//	T[i] = new int[N];

	//return 0;

#if 1
	long long t = 0;
	int mod = 1 << 20;
	int sub = 1 << 19;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j)
		{
			t = (t * 615949 + 797807) % mod;
			T[i][j] = t - sub;
		}

	cout << T[0][0] << " " << T[1][0] << " " << T[1][1] << "\n";
#endif
	//return 0;
	#else
	#define N 6
	int T[N][N] = {
		{15}, 
		{-14, -7}, 
		{20, -13, -5}, 
		{-3, 8, 23, -26}, 
		{1, -4, -5, -18, 5}, 
		{-16, 31, 2, 9, 28, 3}
	};
	#endif



	int accu[N][N + 1] = {0};

	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j)
			accu[i][j + 1] = accu[i][j] + T[i][j];

	

	int dp[2][N][N] = {0};
	int ans = INT_MAX;
	int pre = 1;
	int cur = 0;

#if 0

	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j)
		{
			dp[pre][i][j] = T[i][j];
			ans = min(ans, dp[pre][i][j]);
		}



	for (int h = 1; h < N; ++h)
	{
		for (int i = 0; i + h < N; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				//cout << h << " " << i << " " << j << "\n";
				dp[cur][i][j] = dp[pre][i][j] + accu[i + h][j + h + 1] - accu[i + h][j];
				ans = min(ans, dp[cur][i][j]);
			}
		}

		pre = cur;
		cur = 1 - cur;
	}
#endif

	#if 0
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i + 1; ++j)
			cout << accu[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";

	for (int h = 0; h < N; ++h)
	{
		cout << "h = " << h << "\n";
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				cout << dp[h][i][j] << " ";
			}
			cout << "\n";
		}
	}
	#endif

	//return ans;
	return 0;
}

int main()
{
	cout << euler() << "\n";

	return 0;
}
