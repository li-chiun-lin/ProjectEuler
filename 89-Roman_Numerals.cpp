/*
20%

<p>For a number written in Roman numerals to be considered valid there are basic rules which must be followed. Even though the rules allow some numbers to be expressed in more than one way there is always a "best" way of writing a particular number.</p>
<p>For example, it would appear that there are at least six ways of writing the number sixteen:</p>
<p class="margin_left monospace">IIIIIIIIIIIIIIII<br>
VIIIIIIIIIII<br>
VVIIIIII<br>
XIIIIII<br>
VVVI<br>
XVI</p>
<p>However, according to the rules only <span class="monospace">XIIIIII</span> and <span class="monospace">XVI</span> are valid, and the last example is considered to be the most efficient, as it uses the least number of numerals.</p>
<p>The 11K text file, <a href="resources/documents/0089_roman.txt">roman.txt</a> (right click and 'Save Link/Target As...'), contains one thousand numbers written in valid, but not necessarily minimal, Roman numerals; see <a href="about=roman_numerals">About... Roman Numerals</a> for the definitive rules for this problem.</p>
<p>Find the number of characters saved by writing each of these in their minimal form.</p>
<p class="smaller">Note: You can assume that all the Roman numerals in the file contain no more than four consecutive identical units.</p>
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

// Map to convert individual Roman numeral characters to their integer values
map<char, int> romanToInteger = {
    {'I', 1}, {'V', 5}, {'X', 10},
    {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
};

// Vector to map integer values to their minimal Roman numeral lengths
// Each pair contains the integer value and the length of its minimal Roman representation
vector<pair<int, int>> integerToRomanLength = {
    {1000, 1}, // M
    {900, 2},  // CM
    {500, 1},  // D
    {400, 2},  // CD
    {100, 1},  // C
    {90, 2},   // XC
    {50, 1},   // L
    {40, 2},   // XL
    {10, 1},   // X
    {9, 2},    // IX
    {5, 1},    // V
    {4, 2},    // IV
    {1, 1}     // I
};

// Converts a Roman numeral string to its integer value
int romanToInt(const string& s) {
    int result = 0;
    int prevValue = 0;

    // Iterate through the string in reverse order
    for (int i = s.size() - 1; i >= 0; --i) {
        int currValue = romanToInteger[s[i]];

        // If the current value is less than the previous value, subtract it (subtractive notation)
        if (currValue < prevValue)
            result -= currValue;
        else
            result += currValue;

        // Update the previous value
        prevValue = currValue;
    }

    return result;
}

// Calculates the length of the minimal Roman numeral representation of a given integer
int minimalRomanLength(int n) {
    int length = 0;

    // Iterate through the predefined Roman numeral values and lengths
    for (const auto& [value, romanLength] : integerToRomanLength) {
        while (n >= value) {
            length += romanLength; // Add the length of the Roman numeral
            n -= value;            // Subtract the value from the number
        }
    }

    return length;
}

// Main function to calculate the total number of characters saved
int calculateSavedCharacters(ifstream& inputFile) {
    string romanNumeral;
    int totalSaved = 0;

    // Read each Roman numeral from the file
    while (getline(inputFile, romanNumeral)) {
        // Convert to integer and compute the minimal Roman numeral length
        int originalLength = romanNumeral.size();
        int minimalLength = minimalRomanLength(romanToInt(romanNumeral));

        // Accumulate the number of characters saved
        totalSaved += (originalLength - minimalLength);
    }

    return totalSaved;
}

int main() {
    ifstream inputFile("p089_roman.txt"); // File containing Roman numerals
    if (!inputFile.is_open()) {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }

    // Calculate and display the total characters saved
    cout << "Total characters saved: " << calculateSavedCharacters(inputFile) << "\n";

    inputFile.close();
    return 0;
}