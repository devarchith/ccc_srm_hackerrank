//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

//Input Format

//Given a single integer

//Constraints

//1 <= n <= 8

//Output Format

//Print a string which is the answer to the question

//Sample Input 0

//1
//Sample Output 0

//()
//solution:-
#include <iostream>
#include <vector>
using namespace std;

void generateParenthesis(int n, int open, int close, string str, vector<string>& result) {
    if (close == n) {
        result.push_back(str);
        return;
    }
    if (open < n) {
        generateParenthesis(n, open+1, close, str+"(", result);
    }
    if (close < open) {
        generateParenthesis(n, open, close+1, str+")", result);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> result;
    generateParenthesis(n, 0, 0, "", result);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
