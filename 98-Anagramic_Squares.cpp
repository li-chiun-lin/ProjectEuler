/*
35%

<p>By replacing each of the letters in the word CARE with $1$, $2$, $9$, and $6$ respectively, we form a square number: $1296 = 36^2$. What is remarkable is that, by using the same digital substitutions, the anagram, RACE, also forms a square number: $9216 = 96^2$. We shall call CARE (and RACE) a square anagram word pair and specify further that leading zeroes are not permitted, neither may a different letter have the same digital value as another letter.</p>
<p>Using <a href="resources/documents/0098_words.txt">words.txt</a> (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, find all the square anagram word pairs (a palindromic word is NOT considered to be an anagram of itself).</p>
<p>What is the largest square number formed by any member of such a pair?</p>
<p class="smaller">NOTE: All anagrams formed must be contained in the given text file.</p>
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

bool check(const string& a, const string& b) {
    vector<int> cnt(26, 0);

    for (char c : a)
        ++cnt[c - 'A'];
    
    for (char c : b)
        --cnt[c - 'A'];

    for (int x : cnt)
        if (x != 0)
            return false;

    return true;
}

void generate_squares(int n, vector<int>& square) {
    int lb = ceil(sqrt(pow(10, n - 1)));
    int ub = floor(sqrt(pow(10, n) - 1));

    for (int i = lb; i <= ub; ++i)
        square.push_back(i * i);

    sort(square.begin(), square.end());  // Ensure squares are sorted for binary search
}

bool get_mapping(const string& word, const string& square, map<char, char>& mapping, set<char>& used) {
    if (word.size() != square.size())
        return false;

    mapping.clear();
    used.clear();

    for (size_t i = 0; i < word.size(); ++i) {
        if (mapping.count(word[i])) {
            if (mapping[word[i]] != square[i])
                return false;  // Inconsistent mapping
        } else {
            if (used.count(square[i]))
                return false;  // Digit already assigned to another letter

            mapping[word[i]] = square[i];
            used.insert(square[i]);
        }
    }
    return true;
}

int get_int(const string& word, const map<char, char>& mapping) {
    string num_str = "";
    for (char c : word) {
        if (!mapping.count(c))
            return -1;
        num_str += mapping.at(c);
    }

    if (num_str[0] == '0')  // Leading zero check
        return -1;

    return stoi(num_str);
}

int euler(vector<string>& words) {
    int max_square = 0;
    map<int, vector<string>> anagrams;

    for (auto& w : words)
        anagrams[w.size()].push_back(w);

    for (auto& [length, v] : anagrams) {
        vector<int> square;
        generate_squares(length, square);
        int n = v.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (check(v[i], v[j])) {
                    for (int s : square) {
                        map<char, char> mapping;
                        set<char> used;  // Track used digits to prevent duplicates

                        if (get_mapping(v[i], to_string(s), mapping, used)) {
                            int num = get_int(v[j], mapping);

                            if (num != -1 && binary_search(square.begin(), square.end(), num)) {
                                max_square = max(max_square, max(s, num));
                            }
                        }
                    }
                }
            }
        }
    }
    return max_square;
}

int main()
{
	ifstream ifs("p098_words.txt", ifstream::in);
	vector<string> words;
	string w;

	while (getline(ifs, w, ','))
		words.push_back(w.substr(1, w.size() - 2));

	cout << euler(words) << "\n";

	ifs.close();

	return 0;
}
