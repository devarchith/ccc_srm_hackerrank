//Given an integer x, return true if x is a palindrome, and false otherwise.

//Input Format

//Contains a single integer

//Constraints

//-2^31 <= x <= 2^31 - 1

//Output Format

//Return either true or false.

//Sample Input 0

//12221
//Sample Output 0

//true
//Sample Input 1

//-23434
//Sample Output 1

//false
//solution:-
#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    // Special cases: negative numbers and numbers ending in zero (except 0 itself)
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    // Reverse the second half of the number and compare it with the first half
    int reverse = 0;
    while (x > reverse) {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }

    return x == reverse || x == reverse / 10;
}

int main() {
    int x;
    cin >> x;
    cout << boolalpha << isPalindrome(x) << endl;
    return 0;
}
