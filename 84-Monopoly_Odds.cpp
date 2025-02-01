/*
35%

<p>In the game, <strong>Monopoly</strong>, the standard board is set up in the following way:</p>
<div class="center">
<img src="p084_monopoly_board.png" alt="p084_monopoly_board.png">
</div>
<p>A player starts on the GO square and adds the scores on two 6-sided dice to determine the number of squares they advance in a clockwise direction. Without any further rules we would expect to visit each square with equal probability: 2.5%. However, landing on G2J (Go To Jail), CC (community chest), and CH (chance) changes this distribution.</p>
<p>In addition to G2J, and one card from each of CC and CH, that orders the player to go directly to jail, if a player rolls three consecutive doubles, they do not advance the result of their 3rd roll. Instead they proceed directly to jail.</p>
<p>At the beginning of the game, the CC and CH cards are shuffled. When a player lands on CC or CH they take a card from the top of the respective pile and, after following the instructions, it is returned to the bottom of the pile. There are sixteen cards in each pile, but for the purpose of this problem we are only concerned with cards that order a movement; any instruction not concerned with movement will be ignored and the player will remain on the CC/CH square.</p>
<ul><li>Community Chest (2/16 cards):
<ol><li>Advance to GO</li>
<li>Go to JAIL</li>
</ol></li>
<li>Chance (10/16 cards):
<ol><li>Advance to GO</li>
<li>Go to JAIL</li>
<li>Go to C1</li>
<li>Go to E3</li>
<li>Go to H2</li>
<li>Go to R1</li>
<li>Go to next R (railway company)</li>
<li>Go to next R</li>
<li>Go to next U (utility company)</li>
<li>Go back 3 squares.</li>
</ol></li>
</ul><p>The heart of this problem concerns the likelihood of visiting a particular square. That is, the probability of finishing at that square after a roll. For this reason it should be clear that, with the exception of G2J for which the probability of finishing on it is zero, the CH squares will have the lowest probabilities, as 5/8 request a movement to another square, and it is the final square that the player finishes at on each roll that we are interested in. We shall make no distinction between "Just Visiting" and being sent to JAIL, and we shall also ignore the rule about requiring a double to "get out of jail", assuming that they pay to get out on their next turn.</p>
<p>By starting at GO and numbering the squares sequentially from 00 to 39 we can concatenate these two-digit numbers to produce strings that correspond with sets of squares.</p>
<p>Statistically it can be shown that the three most popular squares, in order, are JAIL (6.24%) = Square 10, E3 (3.18%) = Square 24, and GO (3.09%) = Square 00. So these three most popular squares can be listed with the six-digit modal string: 102400.</p>
<p>If, instead of using two 6-sided dice, two 4-sided dice are used, find the six-digit modal string.</p>
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
#include <random>
//#include <gmpxx.h> // GMP C++ wrapper

/*
GO A1 CC1 A2 T1 R1 B1 CH1 B2 B3 JAIL
00 01  02 03 04 05 06  07 08 09   10
        +        +      +

C1 U1 C2 C3 R2 D1 CC2 D2 D3 FP
11 12 13 14 15 16  17 18 19 20
    +        +      +

E1 CH2 E2 E3 R3 F1 F2 U2 F3 G2J
21  22 23 24 25 26 27 28 29  30
     +        +        +

G1 G2 CC3 G3 R4 CH3 H1 T2 H2
31 32  33 34 35  36 37 38 39
        +         +
*/

using namespace std;

const int SQUARE_GO = 0;
const int SQUARE_JAIL = 10;
const int SQUARE_C1 = 11;
const int SQUARE_E3 = 24;
const int SQUARE_H2 = 39;
const int SQUARE_R1 = 5;
const int SQUARE_RAILWAY_1 = 5;
const int SQUARE_RAILWAY_2 = 15;
const int SQUARE_RAILWAY_3 = 25;
const int SQUARE_RAILWAY_4 = 35;
const int SQUARE_UTILITY_1 = 12;
const int SQUARE_UTILITY_2 = 28;

const int CC_NONE = -1;

vector<int> communityChest = 
{
	SQUARE_GO,  // Advance to GO
	SQUARE_JAIL, // Go to JAIL
	CC_NONE, CC_NONE, CC_NONE, CC_NONE, CC_NONE, CC_NONE, CC_NONE, 
	CC_NONE, CC_NONE, CC_NONE, CC_NONE, CC_NONE, CC_NONE, CC_NONE 
};

const int CHANCE_NEXT_RAILWAY = 98;
const int CHANCE_NEXT_UTILITY = 99;
const int CHANCE_GO_BACK_3 = 97;
const int CHANCE_NONE = -1;

vector<int> chance = {
	SQUARE_GO,  
	SQUARE_JAIL, 
	SQUARE_C1, 
	SQUARE_E3, 
	SQUARE_H2, 
	SQUARE_R1, 	
	CHANCE_NEXT_RAILWAY, 
	CHANCE_NEXT_RAILWAY, 
	CHANCE_NEXT_UTILITY, 
	CHANCE_GO_BACK_3, 
	CHANCE_NONE,
	CHANCE_NONE,
	CHANCE_NONE,
	CHANCE_NONE,
	CHANCE_NONE,
	CHANCE_NONE
};

pair<int, int> rollDice(int DICE_SIDES) {
    return {rand() % DICE_SIDES + 1, rand() % DICE_SIDES + 1};
}

void moveToNextRailway(int &position) {
	// Railways: 5, 15, 25, 35
    if (position < SQUARE_RAILWAY_1) 
		position = SQUARE_RAILWAY_1;
    else if (position < SQUARE_RAILWAY_2) 
		position = SQUARE_RAILWAY_2;
    else if (position < SQUARE_RAILWAY_3) 
		position = SQUARE_RAILWAY_3;
	else if (position < SQUARE_RAILWAY_4) 
		position = SQUARE_RAILWAY_4;
    else 
		position = SQUARE_RAILWAY_1;
}

void moveToNextUtility(int &position) {
    if (position < SQUARE_UTILITY_1) 
		position = SQUARE_UTILITY_1;
	else if (position < SQUARE_UTILITY_2) 
		position = SQUARE_UTILITY_2;
    else 
		position = SQUARE_UTILITY_1;
}

void handleCommunityChest(int &position) {
    int card = communityChest[rand() % communityChest.size()];

    if (card != CC_NONE) 
		position = card;
}

void handleChance(int &position) {
    int card = chance[rand() % chance.size()];

    if (card == CHANCE_NEXT_RAILWAY) 
		moveToNextRailway(position);
    else if (card == CHANCE_NEXT_UTILITY) 
		moveToNextUtility(position);
	else if (card == CHANCE_GO_BACK_3) 
		position -= 3;
	else if (card != CHANCE_NONE) 
		position = card;
}

int euler(int N)
{
	const int BOARD_SIZE = 40;
	int position = 0;
    int doublesCount = 0;
	vector<int> count(BOARD_SIZE, 0);

	for (int i = 0; i < N; ++i) {
        auto [die1, die2] = rollDice(4);
        int roll = die1 + die2;

        if (die1 == die2) {
            ++doublesCount;
        } else {
            doublesCount = 0;
        }

        if (doublesCount == 3) {
            position = 10; // Go to jail
            doublesCount = 0;
        } else {
            position = (position + roll) % BOARD_SIZE;
            if (position == 30) {
                position = 10; // Go to jail
			// Community Chest: 2, 17, 33
            } else if (position == 2 || position == 17 || position == 33) {
                handleCommunityChest(position);
			// Chance: 7, 22, 36
            } else if (position == 7 || position == 22 || position == 36) {
                handleChance(position);
            }
        }

        ++count[position];
    }

	vector<pair<int, int>> result(BOARD_SIZE);

	for (int i = 0; i < BOARD_SIZE; ++i) {
		result[i] = {count[i], i};
	}

	sort(result.begin(), result.end(), greater<>());
	
	return 10000 * result[0].second + 100 * result[1].second + result[2].second;
}

int main()
{
	cout << euler(1000000) << "\n";

	return 0;
}
