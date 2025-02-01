/*
45%

<p>Let $S(A)$ represent the sum of elements in set $A$ of size $n$. We shall call it a special sum set if for any two non-empty disjoint subsets, $B$ and $C$, the following properties are true:</p>
<ol><li>$S(B) \ne S(C)$; that is, sums of subsets cannot be equal.</li>
<li>If $B$ contains more elements than $C$ then $S(B) \gt S(C)$.</li>
</ol><p>For example, $\{81, 88, 75, 42, 87, 84, 86, 65\}$ is not a special sum set because $65 + 87 + 88 = 75 + 81 + 84$, whereas $\{157, 150, 164, 119, 79, 159, 161, 139, 158\}$ satisfies both rules for all possible subset pair combinations and $S(A) = 1286$.</p>
<p>Using <a href="resources/documents/0105_sets.txt">sets.txt</a> (right click and "Save Link/Target As..."), a 4K text file with one-hundred sets containing seven to twelve elements (the two examples given above are the first two sets in the file), identify all the special sum sets, $A_1, A_2, \dots, A_k$, and find the value of $S(A_1) + S(A_2) + \cdots + S(A_k)$.</p>
<p class="smaller">NOTE: This problem is related to <a href="problem=103">Problem 103</a> and <a href="problem=106">Problem 106</a>.</p>
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
#include <unordered_set>
#include <vector>
//#include <gmpxx.h> // GMP C++ wrapper

using namespace std;

// Function to check if a set satisfies the special sum property
bool isValidSet(const vector<int>& S) {
    int n = S.size();
    int totalSubsets = 1 << n; // 2^n subsets
    unordered_set<int> subsetSums;

    // Generate all subset sums using bitmasking
    vector<pair<int, int>> subsets(n + 1, {INT_MAX, INT_MIN}); // subsets[i] stores subset sums of size i

    for (int mask = 1; mask < totalSubsets; mask++) {
        int sum = 0, count = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += S[i];
                count++;
            }
        }

        // Condition 1: Check if sum already exists (violates property)
        if (subsetSums.find(sum) != subsetSums.end()) 
            return false;
        subsetSums.insert(sum);

		auto [lb, ub] = subsets[count];
		subsets[count] = {min(lb, sum), max(ub, sum)};
    }

    // Condition 2: Ensure larger subsets have greater sums than smaller ones
    for (int i = 1; i + 1 < n; i++) {
		if (subsets[i].second >= subsets[i + 1].first) {
			return false;
		}
    }

	return true;
}

int euler(vector<vector<int>>& SS)
{
	int sum = 0;

	for (auto& S : SS)
	{
		sort(begin(S), end(S));

		if (isValidSet(S))
			sum += accumulate(begin(S), end(S), 0);

	}

	return sum;
}

int main()
{
	ifstream ifs("p105_sets.txt", ifstream::in);
	vector<vector<int>> SS;
	string line = "";

	while (getline(ifs, line))
	{
		SS.push_back({});
		stringstream ss(line);
		int x;

		while (ss >> x)
		{
			SS.back().push_back(x);

			if (ss.peek() == ',')
				ss.ignore();
		}
	}

	cout << euler(SS) << "\n";

	ifs.close();

	return 0;
}
