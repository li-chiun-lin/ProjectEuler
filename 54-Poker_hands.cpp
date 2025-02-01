/*
10%

<p>In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:</p>
<ul><li><b>High Card</b>: Highest value card.</li>
<li><b>One Pair</b>: Two cards of the same value.</li>
<li><b>Two Pairs</b>: Two different pairs.</li>
<li><b>Three of a Kind</b>: Three cards of the same value.</li>
<li><b>Straight</b>: All cards are consecutive values.</li>
<li><b>Flush</b>: All cards of the same suit.</li>
<li><b>Full House</b>: Three of a kind and a pair.</li>
<li><b>Four of a Kind</b>: Four cards of the same value.</li>
<li><b>Straight Flush</b>: All cards are consecutive values of same suit.</li>
<li><b>Royal Flush</b>: Ten, Jack, Queen, King, Ace, in same suit.</li>
</ul><p>The cards are valued in the order:<br>2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.</p>
<p>If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.</p>
<p>Consider the following five hands dealt to two players:</p>
<div class="center">
<table><tr><td><b>Hand</b></td><td> </td><td><b>Player 1</b></td><td> </td><td><b>Player 2</b></td><td> </td><td><b>Winner</b></td>
</tr><tr><td><b>1</b></td><td> </td><td>5H 5C 6S 7S KD<br><div class="smaller">Pair of Fives</div></td><td> </td><td>2C 3S 8S 8D TD<br><div class="smaller">Pair of Eights</div></td><td> </td><td>Player 2</td>
</tr><tr><td><b>2</b></td><td> </td><td>5D 8C 9S JS AC<br><div class="smaller">Highest card Ace</div></td><td> </td><td>2C 5C 7D 8S QH<br><div class="smaller">Highest card Queen</div></td><td> </td><td>Player 1</td>
</tr><tr><td><b>3</b></td><td> </td><td>2D 9C AS AH AC<br><div class="smaller">Three Aces</div></td><td> </td><td>3D 6D 7D TD QD<br><div class="smaller">Flush  with Diamonds</div></td><td> </td><td>Player 2</td>
</tr><tr><td><b>4</b></td><td> </td><td>4D 6S 9H QH QC<br><div class="smaller">Pair of Queens<br>Highest card Nine</div></td><td> </td><td>3D 6D 7H QD QS<br><div class="smaller">Pair of Queens<br>Highest card Seven</div></td><td> </td><td>Player 1</td>
</tr><tr><td><b>5</b></td><td> </td><td>2H 2D 4C 4D 4S<br><div class="smaller">Full House<br>With Three Fours</div></td><td> </td><td>3C 3D 3S 9S 9D<br><div class="smaller">Full House<br>with Three Threes</div></td><td> </td><td>Player 1</td>
</tr></table></div>
<p>The file, <a href="resources/documents/0054_poker.txt">poker.txt</a>, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.</p>
<p>How many hands does Player 1 win?</p>
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <queue>
#include <vector>

using namespace std;

map<char, int> v_val = {
	{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, 
	{'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}, 
};

map<char, int> v_suit = {
	{'S', 4}, {'H', 3}, {'D', 2}, {'C', 1}
};

bool sort_card(string &a, string &b)
{
	return ((v_val[a[0]] << 4) + v_suit[a[1]]) < ((v_val[b[0]] << 4) + v_suit[b[1]]);
}

void print(vector<string> &p)
{
	for (string &s : p)
		cout << s << " ";
	cout << endl;
}

pair<long long, int> evaluate(vector<string> &p)
{
	sort(begin(p), end(p), sort_card);
	//print(p);

	bool isStraight = true;

	for (int i = 1; i < p.size() && isStraight; ++i)
		isStraight = v_val[p[i][0]] == v_val[p[i - 1][0]] + 1;

	map<char, int> same_val;
	map<char, int> same_suit;

	bool isFlush = false;

	for (auto &c : p)
	{
		++same_val[c[0]];

		if (++same_suit[c[1]] == 5)
			isFlush = true;
	}

	char max_val = 0;
	vector<int> cntPair;

	for (auto &h : same_val)
	{
		if (h.second > same_val[max_val])
			max_val = h.first;

		if (h.second == 2)
			cntPair.push_back(h.first);
	}

	bool isFour = same_val[max_val] == 4;
	bool isThree = same_val[max_val] == 3;
	bool isFullHouse = isThree && cntPair.size() == 1;
	bool isStraightFlush = isStraight && isFlush;
	//bool isRoyalFlush = isStraightFlush && p[0][0] == 'T';

	if (isStraightFlush)
		return {(long long)v_val[p.back()[0]] << 32, v_suit[p.back()[1]]};
	else if (isFour)
		return {v_val[max_val] << 28, 0};
	else if (isFullHouse)
		return {v_val[max_val] << 24, 0};
	else if (isFlush)
		return {v_suit[p.back()[1]] << 20, v_suit[p.back()[1]]};
	else if (isStraight)
		return {v_val[p.back()[0]] << 16, v_suit[p.back()[1]]};
	else if (isThree)
		return {v_val[max_val] << 12, 0};
	else if (cntPair.size() == 2)
	{
		int mp1 = v_val[cntPair[0]];
		int mp2 = v_val[cntPair[1]];
		int mp = max(mp1, mp2);
		int ms = 0;

		// this is weird
		for (auto &c : p)
			if (c[0] != cntPair[0] && c[0] != cntPair[1])
				ms = max(ms, v_suit[c[1]]);

		return {mp << 8, ms};
	}
	else if (cntPair.size() == 1)
	{
		int mp = v_val[cntPair[0]];
		int ms = 0;

		// this is even weirder
		for (auto &c : p)
			if (c[0] == cntPair[0])
				ms = max(ms, v_suit[c[1]]);

		return {mp << 4, ms};
	}
	else
		return {v_val[p.back()[0]], v_suit[p.back()[1]]};
}

int euler()
{
	ifstream ifs("p054_poker.txt", ifstream::in);
	int cnt = 0;

	for (int i = 0; i < 1000; ++i)
	{
		vector<string> p1(5), p2(5);

		for (int j = 0; j < 5; ++j)
			ifs >> p1[j];

		for (int j = 0; j < 5; ++j)
			ifs >> p2[j];

		auto [v1, s1] = evaluate(p1);
		auto [v2, s2] = evaluate(p2);

		cnt += v1 > v2 || (v1 == v2 && s1 > s2);
	}

	ifs.close();

	return cnt;
}

int main()
{
	cout << euler() << endl;

	return 0;
}
