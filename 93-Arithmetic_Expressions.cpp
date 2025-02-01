/*
35%

<p>By using each of the digits from the set, $\{1, 2, 3, 4\}$, exactly once, and making use of the four arithmetic operations ($+, -, \times, /$) and brackets/parentheses, it is possible to form different positive integer targets.</p>
<p>For example,</p>
\begin{align}
8 &amp;= (4 \times (1 + 3)) / 2\\
14 &amp;= 4 \times (3 + 1 / 2)\\
19 &amp;= 4 \times (2 + 3) - 1\\
36 &amp;= 3 \times 4 \times (2 + 1)
\end{align}
<p>Note that concatenations of the digits, like $12 + 34$, are not allowed.</p>
<p>Using the set, $\{1, 2, 3, 4\}$, it is possible to obtain thirty-one different target numbers of which $36$ is the maximum, and each of the numbers $1$ to $28$ can be obtained before encountering the first non-expressible number.</p>
<p>Find the set of four distinct digits, $a \lt b \lt c \lt d$, for which the longest set of consecutive positive integers, $1$ to $n$, can be obtained, giving your answer as a string: <i>abcd</i>.</p>
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

// Definition of a TreeNode structure
struct TreeNode {
    int val;                // Value of the node
    TreeNode* left;         // Left child pointer
    TreeNode* right;        // Right child pointer

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {} // Constructor to initialize a node
};

// Function to generate all possible complete binary trees with `n` nodes
vector<TreeNode*> generateCompleteBinaryTrees(int n) {
    if (n % 2 == 0) return {}; // If `n` is even, no valid complete binary tree can be formed

    if (n == 1) return { new TreeNode(0) }; // Single-node tree

    vector<TreeNode*> result;

    // For a complete binary tree, left subtree nodes + right subtree nodes = Total nodes - 1 (root)
    for (int leftNodes = 1; leftNodes < n; leftNodes += 2) {
        int rightNodes = n - 1 - leftNodes;

        // Generate combinations of left and right subtrees
        vector<TreeNode*> leftTrees = generateCompleteBinaryTrees(leftNodes);
        vector<TreeNode*> rightTrees = generateCompleteBinaryTrees(rightNodes);

        for (TreeNode* left : leftTrees) {
            for (TreeNode* right : rightTrees) {
                TreeNode* root = new TreeNode(0); // Create root node with value 0
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }

    return result; // Return all the generated trees
}

// Function to evaluate the expression tree using numbers and operators
double eval(TreeNode* root, vector<int>& nums, vector<int>& operators, int& i, int& j) {
    if (i >= nums.size() || j >= operators.size()) {
        return NAN; // Return NaN if indices go out of bounds
    }

    if (!root) return NAN; // Return NaN if the current node is null

    // Leaf node: return the number
    if (!root->left && !root->right) {
        return nums[i++];
    }

    double left = eval(root->left, nums, operators, i, j); // Evaluate left subtree

    if (isnan(left)) return NAN; // Propagate NaN if left subtree evaluation is invalid

    double right = eval(root->right, nums, operators, i, j); // Evaluate right subtree

    if (isnan(right)) return NAN; // Propagate NaN if right subtree evaluation is invalid

    switch (operators[j++]) { // Apply the operator
        case 0: return left + right;   // Addition
        case 1: return left - right;   // Subtraction
        case 2: return left * right;   // Multiplication
        case 3: return (right == 0) ? NAN : left / right; // Division with zero check
        default: return NAN; // Default case should never be hit
    }
}

// Function to find the length of the longest consecutive sequence starting from 1 in a set
int longestConsecutive(const set<int>& target) {
    int count = 0;

    for (int i = 1; target.count(i); ++i) {
        ++count; // Increment the count as long as numbers are consecutive
    }

    return count;
}

// Main Euler problem-solving function
int euler() {
    int n = 7; // Number of nodes (must be odd for a complete binary tree)
    vector<TreeNode*> trees = generateCompleteBinaryTrees(n); // Generate all possible trees

    vector<vector<int>> operators; // Possible operators: +, -, *, /

    for (int op1 = 0; op1 < 4; ++op1)      // Generate all combinations of operators
        for (int op2 = 0; op2 < 4; ++op2)
            for (int op3 = 0; op3 < 4; ++op3)
                operators.push_back({op1, op2, op3});

    vector<vector<int>> nums; // Possible numbers to use in combinations

    for (int d1 = 1; d1 <= 9; ++d1)       // Generate all unique 4-digit combinations
        for (int d2 = d1 + 1; d2 <= 9; ++d2)
            for (int d3 = d2 + 1; d3 <= 9; ++d3)
                for (int d4 = d3 + 1; d4 <= 9; ++d4)
                    nums.push_back({d1, d2, d3, d4});

    int ans = 0;      // To store the best answer
    int max_length = 0; // To track the longest consecutive sequence

    // Iterate through all number combinations
    for (auto& num : nums) {
        set<int> target;

        // Permute the numbers and evaluate the expression tree with each permutation
        do {
            for (auto& op : operators) {
                for (auto& t : trees) {
                    int i = 0, j = 0;
                    auto r = eval(t, num, op, i, j);

                    if (!isnan(r) && r > 0 && floor(r) == r) {
                        target.insert((int)r); // Insert valid results into the set
                    }
                }
            }
        } while (next_permutation(begin(num), end(num))); // Generate all permutations of numbers

        int length = longestConsecutive(target); // Find the length of the longest consecutive sequence

        if (max_length < length) {
            max_length = length;    // Update the maximum length found
            ans = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3]; // Store the result as a 4-digit number
        }
    }

    cout << max_length << "\n";   // Output the length of the longest sequence

    return ans; // Return the 4-digit number that produces the longest sequence
}

int main() {
    cout << euler() << "\n";   // Call the Euler function and print the result
    return 0;
}