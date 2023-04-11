//Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

//The algorithm for myAtoi(string s) is as follows:

//Read in and ignore any leading whitespace. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2). If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -2^31 should be clamped to -2^31, and integers greater than 2^31 - 1 should be clamped to 2^31 - 1. Return the integer as the final result.

//Input Format

//Contains a string.

//Constraints

//0 <= s.length <= 200

//Output Format

//Return the integer as a final result

//Sample Input 0

  //   23465 dskfhg helo
//Sample Output 0

//23465
//Sample Input 1

  // -923746 shdfhdsf dfuhkljfhldkjsf hldjkfhsdljkhf sdkfghsfd sdf sdljfhsdf
//Sample Output 1

//-923746
//solution:-
#include <iostream>
#include <string>
#include <climits>
using namespace std;

int myAtoi(string s) {
    int i = 0, sign = 1, result = 0;

    // Ignore leading whitespaces
    while (s[i] == ' ') {
        i++;
    }

    // Check for sign
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i++] == '-') ? -1 : 1;
    }

    // Convert digits to integer
    while (s[i] >= '0' && s[i] <= '9') {
        // Check for overflow
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        result = result * 10 + (s[i++] - '0');
    }

    return result * sign;
}

int main() {
    string s;
    getline(cin, s);
    cout << myAtoi(s) << endl;
    return 0;
}
