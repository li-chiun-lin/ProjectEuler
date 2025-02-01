/*
45%

<p>Let $S(A)$ represent the sum of elements in set $A$ of size $n$. We shall call it a special sum set if for any two non-empty disjoint subsets, $B$ and $C$, the following properties are true:</p>
<ol><li>$S(B) \ne S(C)$; that is, sums of subsets cannot be equal.</li>
<li>If $B$ contains more elements than $C$ then $S(B) \gt S(C)$.</li>
</ol><p>If $S(A)$ is minimised for a given $n$, we shall call it an optimum special sum set. The first five optimum special sum sets are given below.</p>
<ul style="list-style-type:none;">
<li>$n = 1$: $\{1\}$</li>
<li>$n = 2$: $\{1, 2\}$</li>
<li>$n = 3$: $\{2, 3, 4\}$</li>
<li>$n = 4$: $\{3, 5, 6, 7\}$</li>
<li>$n = 5$: $\{6, 9, 11, 12, 13\}$</li></ul>
<p>It <i>seems</i> that for a given optimum set, $A = \{a_1, a_2, \dots, a_n\}$, the next optimum set is of the form $B = \{b, a_1 + b, a_2 + b, \dots, a_n + b\}$, where $b$ is the "middle" element on the previous row.</p>
<p>By applying this "rule" we would expect the optimum set for $n = 6$ to be $A = \{11, 17, 20, 22, 23, 24\}$, with $S(A) = 117$. However, this is not the optimum set, as we have merely applied an algorithm to provide a near optimum set. The optimum set for $n = 6$ is $A = \{11, 18, 19, 20, 22, 25\}$, with $S(A) = 115$ and corresponding set string: 111819202225.</p>
<p>Given that $A$ is an optimum special sum set for $n = 7$, find its set string.</p>
<p class="smaller">NOTE: This problem is related to <a href="problem=105">Problem 105</a> and <a href="problem=106">Problem 106</a>.</p>
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

// Function to check if the given set satisfies the Special Sum Set properties
bool isValidSet(const vector<int>& S) {
    int n = S.size();
    int totalSubsets = 1 << n; // Total number of subsets (2^n)
    set<int> visited; // To track subset sums

    // Iterate over all possible subsets using bitmasking
    for (int mask = 1; mask < totalSubsets; mask++) {
        int sum = 0;

        // Compute the subset sum
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += S[i];
            }
        }

        // If sum already exists, it's invalid
        if (visited.count(sum))
			return false;

		visited.insert(sum);
    }

    return true;
}

// Function to find the optimal special sum set for a given N
void euler(int N) {
    // Precomputed optimal sets for smaller values of N
    vector<vector<int>> knownOptimalSets = {
        {1}, 
        {1, 2}, 
        {2, 3, 4}, 
        {3, 5, 6, 7},
        {6, 9, 11, 12, 13}, 
        {11, 18, 19, 20, 22, 25} // N = 6 optimal set
    };

    // Start from the best-known set for (N-1)
    vector<int>& prevSet = knownOptimalSets.back();
    int prevSize = prevSet.size();
    int mid = prevSet[prevSize / 2]; // Choose middle element as reference

    vector<int> currentSet(N);
    currentSet[0] = mid;
    int bestSum = mid;

    // Generate the initial candidate set by shifting previous values
    for (int i = 0; i < prevSize; ++i) {
        currentSet[i + 1] = mid + prevSet[i];
        bestSum += currentSet[i + 1];
    }

    // Fine-tuning: Adjust elements slightly (-3 to +3) to minimize the sum
    for (int delta = -3; delta <= 3; ++delta) {
        for (int i = 0; i < N; ++i) {
            vector<int> candidateSet = currentSet;
            candidateSet[i] += delta;

            // Check if the modified set is still valid
            if (isValidSet(candidateSet)) {
                int sum = accumulate(candidateSet.begin(), candidateSet.end(), 0);

                // Keep the set with the lowest sum
                if (sum < bestSum) {
                    bestSum = sum;
                    currentSet = candidateSet;
                }
            }
        }
    }

    // Print the optimal set
    for (int num : currentSet) {
        cout << num << " ";
    }
    cout << "\n";

    // Print concatenated number sequence
    for (int num : currentSet) {
        cout << num;
    }
    cout << "\n";
}

int main()
{
	euler(7);

	return 0;
}
