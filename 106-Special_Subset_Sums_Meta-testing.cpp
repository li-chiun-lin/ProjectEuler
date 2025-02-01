/*
50%

<p>Let $S(A)$ represent the sum of elements in set $A$ of size $n$. We shall call it a special sum set if for any two non-empty disjoint subsets, $B$ and $C$, the following properties are true:</p>
<ol><li>$S(B) \ne S(C)$; that is, sums of subsets cannot be equal.</li>
<li>If $B$ contains more elements than $C$ then $S(B) \gt S(C)$.</li>
</ol><p>For this problem we shall assume that a given set contains $n$ strictly increasing elements and it already satisfies the second rule.</p>
<p>Surprisingly, out of the $25$ possible subset pairs that can be obtained from a set for which $n = 4$, only $1$ of these pairs need to be tested for equality (first rule). Similarly, when $n = 7$, only $70$ out of the $966$ subset pairs need to be tested.</p>
<p>For $n = 12$, how many of the $261625$ subset pairs that can be obtained need to be tested for equality?</p>
<p class="smaller">NOTE: This problem is related to <a href="problem=103">Problem 103</a> and <a href="problem=105">Problem 105</a>.</p>
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

bool requiresComparison(const vector<int>& a, const vector<int>& b)
{
    int n = a.size();
    int greaterCount = 0, smallerCount = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] > b[i])
            ++greaterCount;
        else if (a[i] < b[i])
            ++smallerCount;
    }

    return (greaterCount > 0 && smallerCount > 0);
}

int euler(int N)
{
    int comparisonCount = 0;
    int totalSubsets = 1 << N; // 2^N total subsets
    vector<int> elements(N);
    
    // Fill elements with values {1, 2, ..., N}
    iota(elements.begin(), elements.end(), 1);

    // Iterate through all possible subsets
    for (int mask1 = 0; mask1 < totalSubsets; ++mask1)
    {
        vector<int> subsetA;
        for (int i = 0; i < N; ++i)
        {
            if (mask1 & (1 << i))
                subsetA.push_back(elements[i]);
        }

        // Ignore subsets with size <= 1 (no valid comparison needed)
        if (subsetA.size() <= 1)
            continue;

        // Iterate over all remaining disjoint subsets
        for (int mask2 = mask1 + 1; mask2 < totalSubsets; ++mask2)
        {
            if (mask2 & mask1) // Ensure subsets are disjoint
                continue;

            vector<int> subsetB;
            for (int i = 0; i < N; ++i)
            {
                if (mask2 & (1 << i))
                    subsetB.push_back(elements[i]);
            }

            // Only compare equal-sized subsets
            if (subsetB.size() != subsetA.size())
                continue;

            // If a comparison is necessary, increment the count
            if (requiresComparison(subsetA, subsetB))
                ++comparisonCount;
        }
    }

    return comparisonCount;
}

int main()
{
	cout << euler(12) << "\n";

	return 0;
}
