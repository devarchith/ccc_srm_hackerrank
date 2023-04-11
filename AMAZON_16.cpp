//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

//Input Format

//Contains two Strings

//Constraints

//1 <= haystack.length, needle.length <= 10^4
//haystack and needle consist of only lowercase English characters.
//Output Format

//Print the integer which is the answer for the question

//Sample Input 0

//hrptkgrc
//tk
//Sample Output 0

//3
//solution:-
#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    int m = haystack.size(), n = needle.size();
    if (n == 0) return 0;
    for (int i = 0; i <= m - n; i++) {
        if (haystack.substr(i, n) == needle) {
            return i;
        }
    }
    return -1;
}

int main() {
    string haystack, needle;
    cin >> haystack >> needle;
    int result = strStr(haystack, needle);
    cout << result << endl;
    return 0;
}
