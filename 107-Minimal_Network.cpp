/*
35%

<p>The following undirected network consists of seven vertices and twelve edges with a total weight of 243.</p>
<div class="center">
<img src="resources/images/0107_1.png?1678992052" class="dark_img" alt=""><br></div>
<p>The same network can be represented by the matrix below.</p>
<table cellpadding="5" cellspacing="0" border="1" align="center"><tr><td>    </td><td><b>A</b></td><td><b>B</b></td><td><b>C</b></td><td><b>D</b></td><td><b>E</b></td><td><b>F</b></td><td><b>G</b></td>
</tr><tr><td><b>A</b></td><td>-</td><td>16</td><td>12</td><td>21</td><td>-</td><td>-</td><td>-</td>
</tr><tr><td><b>B</b></td><td>16</td><td>-</td><td>-</td><td>17</td><td>20</td><td>-</td><td>-</td>
</tr><tr><td><b>C</b></td><td>12</td><td>-</td><td>-</td><td>28</td><td>-</td><td>31</td><td>-</td>
</tr><tr><td><b>D</b></td><td>21</td><td>17</td><td>28</td><td>-</td><td>18</td><td>19</td><td>23</td>
</tr><tr><td><b>E</b></td><td>-</td><td>20</td><td>-</td><td>18</td><td>-</td><td>-</td><td>11</td>
</tr><tr><td><b>F</b></td><td>-</td><td>-</td><td>31</td><td>19</td><td>-</td><td>-</td><td>27</td>
</tr><tr><td><b>G</b></td><td>-</td><td>-</td><td>-</td><td>23</td><td>11</td><td>27</td><td>-</td>
</tr></table><p>However, it is possible to optimise the network by removing some edges and still ensure that all points on the network remain connected. The network which achieves the maximum saving is shown below. It has a weight of 93, representing a saving of 243 − 93 = 150 from the original network.</p>
<div class="center">
<img src="resources/images/0107_2.png?1678992052" class="dark_img" alt=""><br></div>
<p>Using <a href="resources/documents/0107_network.txt">network.txt</a> (right click and 'Save Link/Target As...'), a 6K text file containing a network with forty vertices, and given in matrix form, find the maximum saving which can be achieved by removing redundant edges whilst ensuring that the network remains connected.</p>
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
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
#include <unordered_set>
#include <vector>

//#include <gmpxx.h> // GMP C++ wrapper

using namespace std;

int euler(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    vector<tuple<int, int, int>> edges; // Stores edges as (weight, node1, node2)
    int totalWeight = 0; // Sum of all edges in the original graph

    // Extract all edges from the adjacency matrix and compute the total weight
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (matrix[i][j] != 0) // If there is an edge
            {
                edges.push_back({matrix[i][j], i, j});
                totalWeight += matrix[i][j]; // Sum up the total weight
            }

    // Sort edges by weight for Kruskal’s Algorithm
    sort(begin(edges), end(edges));

    // Disjoint Set (Union-Find) to track connected components
    vector<int> parent(n);
    iota(begin(parent), end(parent), 0); // Initialize each node as its own parent

    // Find function with path compression
    function<int(int)> find = [&](int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    };

    // Union function to merge sets
    auto join = [&](int x, int y) {
        parent[find(x)] = find(y);
    };

    int mstWeight = 0; // Weight of the MST
    int edgesUsed = 0; // Number of edges used in MST

    // Process edges in increasing order of weight
    for (auto& [w, u, v] : edges)
    {
        if (find(u) != find(v)) // If u and v are in different components
        {
            join(u, v); // Merge components
            mstWeight += w; // Add edge weight to MST

            if (++edgesUsed == n - 1) // Stop when MST is complete
                break;
        }
    }

    return totalWeight - mstWeight; // Weight saved
}

int main()
{
	vector<vector<int>> matrix;
	ifstream ifs("p107_network.txt", ifstream::in);
	string line = "";

	while (getline(ifs, line))
	{
		stringstream ss(line);
		string token = "";
		matrix.push_back(vector<int>());

		while (getline(ss, token, ','))
		{
			if (token != "-")
				matrix.back().push_back(stoi(token));
			else
				matrix.back().push_back(0);
		}
	}

	cout << euler(matrix) << "\n";

	return 0;
}
