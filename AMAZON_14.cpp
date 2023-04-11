//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//An input string is valid if:

//Open brackets must be closed by the same type of brackets. Open brackets must be closed in the correct order. Every close bracket has a corresponding open bracket of the same type.

//Input Format

//Given a string

//Constraints

//1 <= s.length <= 5*10^4
//s consists of parentheses only '()[]{}'.
//Output Format

//Return either true or false.

//Sample Input 0

//[))({]{
//Sample Output 0

//false
//Sample Input 1

//([{}])(){}[]
//Sample Output 1

//true
//solution:-
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char c : s) {
        if (mapping.count(c)) {
            if (st.empty() || st.top() != mapping[c]) {
                return false;
            }
            st.pop();
        } else {
            st.push(c);
        }
    }

    return st.empty();
}

int main() {
    string s;
    cin >> s;
    cout << (isValid(s) ? "true" : "false") << endl;
    return 0;
}
