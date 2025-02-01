/*
25%

<p class="small_notice">NOTE: This problem is a significantly more challenging version of <a href="problem=81">Problem 81</a>.</p>
<p>In the $5$ by $5$ matrix below, the minimal path sum from the top left to the bottom right, by moving left, right, up, and down, is indicated in bold red and is equal to $2297$.</p>
<div class="center">
$$
\begin{pmatrix}
\color{red}{131} &amp; 673 &amp; \color{red}{234} &amp; \color{red}{103} &amp; \color{red}{18}\\
\color{red}{201} &amp; \color{red}{96} &amp; \color{red}{342} &amp; 965 &amp; \color{red}{150}\\
630 &amp; 803 &amp; 746 &amp; \color{red}{422} &amp; \color{red}{111}\\
537 &amp; 699 &amp; 497 &amp; \color{red}{121} &amp; 956\\
805 &amp; 732 &amp; 524 &amp; \color{red}{37} &amp; \color{red}{331}
\end{pmatrix}
$$
</div>
<p>Find the minimal path sum from the top left to the bottom right by moving left, right, up, and down in <a href="resources/documents/0083_matrix.txt">matrix.txt</a> (right click and "Save Link/Target As..."), a 31K text file containing an $80$ by $80$ matrix.</p>
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

long long euler(vector<vector<int>>& matrix)
{
	// Directions for moving in the matrix: up, down, left, right
const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int N = matrix.size();
    vector<vector<long long>> dist(N, vector<long long>(N, LLONG_MAX)); // Distance array
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq; // Min-heap

    // Start from the top-left corner
    dist[0][0] = matrix[0][0];
    pq.emplace(matrix[0][0], 0, 0);

    while (!pq.empty()) 
    {
        auto [cost, x, y] = pq.top();
        pq.pop();

        // If this cell has already been processed with a smaller cost, skip it
        if (cost > dist[x][y]) 
        {
            continue;
        }

        // Process all neighbors
        for (auto [dx, dy] : directions) 
        {
            int nx = x + dx, ny = y + dy;

            // Check bounds
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) 
            {
                long long newCost = cost + matrix[nx][ny];
                if (newCost < dist[nx][ny]) 
                {
                    dist[nx][ny] = newCost;
                    pq.emplace(newCost, nx, ny);
                }
            }
        }
    }

    // Return the distance to the bottom-right corner
    return dist[N - 1][N - 1];
}

int main()
{
	vector<vector<int>> matrix(80, vector<int>(80));

    // Read the matrix from the file
    ifstream file("p083_matrix.txt");
    if (!file.is_open()) 
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    for (int i = 0; i < 80; ++i) 
    {
        for (int j = 0; j < 80; ++j) 
        {
            char comma;
            file >> matrix[i][j];
            if (j < 79) 
            {
                file >> comma; // To skip commas
            }
        }
    }

	cout << euler(matrix) << "\n";

	return 0;
}
