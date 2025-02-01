/*
30%

<p>Let $p(n)$ represent the number of different ways in which $n$ coins can be separated into piles. For example, five coins can be separated into piles in exactly seven different ways, so $p(5)=7$.</p>
<div class="margin_left">
OOOOO<br>
OOOO   O<br>
OOO   OO<br>
OOO   O   O<br>
OO   OO   O<br>
OO   O   O   O<br>
O   O   O   O   O
</div>
<p>Find the least value of $n$ for which $p(n)$ is divisible by one million.</p>
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

// Function to calculate pentagonal numbers
int pentagonal(int k) 
{
    return k * (3 * k - 1) / 2;
}

int euler()
{
	const int MOD = 1000000; // Modulus for divisibility check
    vector<int> partitions = {1}; // Base case: p(0) = 1
	int n = 0;

	while (true) 
    {
        ++n;
        int partition = 0;

        for (int k = 1; ; ++k) 
        {
            // Generalized pentagonal numbers for positive and negative k
            int pent1 = pentagonal(k);     // k > 0
            int pent2 = pentagonal(-k);    // k < 0

            // Stop if the pentagonal number exceeds n
            if (pent1 > n && pent2 > n)
                break;

            // Add or subtract terms based on the pentagonal number theorem
            if (pent1 <= n) 
                partition += (k % 2 ? 1 : -1) * partitions[n - pent1];
            if (pent2 <= n)
                partition += (k % 2 ? 1 : -1) * partitions[n - pent2];

            // Ensure the partition count stays within bounds of MOD
            partition %= MOD;
        }

        partitions.push_back(partition);

        // Check divisibility condition
        if (partition == 0) 
        {
            break;
        }
    }

	return n;
}

int main()
{
	cout << euler() << "\n";

	return 0;
}
