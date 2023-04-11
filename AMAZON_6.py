#Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

#Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

#Input Format

#Given an integer x

#Constraints

#-2^31 <= x <= 2^31 - 1

#Output Format

#Return an integer which is the answer to the question

#Sample Input 0

#404
#Sample Output 0

#404
#Sample Input 1

#123
#Sample Output 1

#321
#solution:-
def reverse_integer(x):
    is_negative = x < 0
    x = abs(x)
    rev_x = 0
    while x:
        rev_x = rev_x * 10 + x % 10
        x //= 10
    if rev_x > 2**31 - 1:
        return 0
    return -rev_x if is_negative else rev_x
x = int(input())
result = reverse_integer(x)
print( result)
