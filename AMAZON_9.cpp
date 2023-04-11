//Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//The matching should cover the entire input string (not partial).

//Input Format

//Given two strings

//Constraints

//1 <= s.length <= 20
//1 <= p.length <= 30
//s contains only lowercase English letters.
//p contains only lowercase English letters, '.', and '*'.
//It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
//Output Format

//Return true or false

//Sample Input 0

//aa
//a
//Sample Output 0

//false
// solution:-
#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    // Initialize the memoization table with all values set to false
    vector<vector<bool>> memo(s.length() + 1, vector<bool>(p.length() + 1, false));
    // Set the base case value to true
    memo[0][0] = true;

    // Handle the case where p starts with one or more '*' characters
    for (int j = 1; j <= p.length(); j++) {
        if (p[j - 1] == '*') {
            memo[0][j] = memo[0][j - 2];
        }
    }

    // Fill in the rest of the memoization table
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= p.length(); j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                memo[i][j] = memo[i - 1][j - 1];
            }
            else if (p[j - 1] == '*') {
                memo[i][j] = memo[i][j - 2];
                if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                    memo[i][j] = memo[i][j] || memo[i - 1][j];
                }
            }
            else {
                memo[i][j] = false;
            }
        }
    }

    // Return the final result
    return memo[s.length()][p.length()];
}

int main() {
    string s, p;
    cin >> s >> p;
    bool result = isMatch(s, p);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
